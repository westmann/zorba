/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "functions/Index.h"
#include "functions/function_impl.h"

#include "runtime/indexing/value_index_ddl.h"
#include "runtime/indexing/value_index_probe.h"
#include "runtime/indexing/value_index_context.h"


namespace zorba
{

CODEGEN_DEF(FunctionCreateInternalIndex)
{
  // There is no single iterator that implements this function. Instead, a
  // whole sub-plan is generated to build the index. This is done in 
  // plan_visitor.cpp because the sun-plan must be generated by the same 
  // visitor as th rest of the query plan.
  ZORBA_ASSERT(false);
}


/******************************************************************************
  refresh-index($indexName as xs:QName) as pul()

  This is an updating function. During normal runtime (see RefreshIndexIterator),
  it checks that index exists (in the dynamic context) and generates an update
  primitive. During applyUpdates(), it clears the index of its contents and then
  rebuilds the index the same way as the create-index() function.
********************************************************************************/
class FunctionRefreshIndex : public function 
{
public:
  FunctionRefreshIndex(const signature& sig) 
    :
    function(sig, FunctionConsts::FN_REFRESH_INDEX_1)
  {
  }

  bool requires_dyn_ctx() const { return true; }

 expr_script_kind_t getUpdateType() const { return UPDATE_EXPR; }

  DEFAULT_UNARY_CODEGEN(RebuildIndexIterator);
};


/***************************************************************************//**
  This is a helper function for creating index entries (it constitutes the 
  return expr of the flwor expr that populates the index; see the create-index
  function above). Its first arg is a reference to the domain var, and its next
  N args evaluate and return the key expressions for each domain node. The 
  function simply evaluates each of its children in turn, and returns the
  resulting items one-by-one. This is similar to fn:concatenate, but contrary
  to concatenate, this function also returns NULL items.

  index-entry-builder($domainNode as node(),
                      $key1  as anyAtomic?,
                      ...,
                      $keyN  as anyAtomic?) as item()*
********************************************************************************/
class FunctionIndexEntryBuilder : public function 
{
public:
  FunctionIndexEntryBuilder(const signature& sig) : function(sig) { }

  bool requires_dyn_ctx() const { return true; }

  DEFAULT_NARY_CODEGEN(IndexEntryBuilderIterator);
};


/***************************************************************************//**
  probe-index-point($indexName as xs:QName,
                    $key1      as anyAtomic?,
                    ...,
                    $keyN      as anyAtomic?) as node()*
********************************************************************************/
class FunctionProbeIndexPoint : public function 
{
public:
  FunctionProbeIndexPoint(const signature& sig) 
    :
    function(sig, FunctionConsts::FN_INDEX_PROBE_POINT_N)
  {
  }

  bool requires_dyn_ctx() const { return true; }

  DEFAULT_NARY_CODEGEN(IndexPointProbeIterator);
};


/*******************************************************************************
  probe-index-range($indexName               as xs:QName,
                    $range1LowerBound         as anyAtomic?,
                    $range1UpperBound         as anyAtomic?,
                    $range1HaveLowerBound     as boolean?,
                    $range1HaveupperBound     as boolean?,
                    $range1LowerBoundIncluded as boolean?,
                    $range1upperBoundIncluded as boolean?,
                    ....,
                    $rangeNLowerBound         as anyAtomic?,
                    $rangeNUpperBound         as anyAtomic?,
                    $rangeNHaveLowerBound     as boolean?,
                    $rangeNHaveupperBound     as boolean?,
                    $rangeNLowerBoundIncluded as boolean?,
                    $rangeNupperBoundIncluded as boolean?) as node()*
********************************************************************************/
class FunctionProbeIndexRange : public function 
{
public:
  FunctionProbeIndexRange(const signature& sig) 
    :
    function(sig, FunctionConsts::FN_INDEX_PROBE_RANGE_N)
  {
  }

  bool requires_dyn_ctx() const { return true; }

  DEFAULT_NARY_CODEGEN(IndexRangeProbeIterator);
};

class FunctionIsDeclaredIndex : public function 
{
public:
  FunctionIsDeclaredIndex(const signature& sig) 
    :
    function(sig)
  {
  }

  bool requires_dyn_ctx() const { return false; }

  DEFAULT_NARY_CODEGEN(IsDeclaredIndexIterator);
};

class FunctionDeclaredIndexes : public function 
{
public:
  FunctionDeclaredIndexes(const signature& sig) 
    :
    function(sig)
  {
  }

  bool requires_dyn_ctx() const { return false; }

  DEFAULT_NARY_CODEGEN(DeclaredIndexesIterator);
};

class FunctionIsAvailableIndex : public function 
{
public:
  FunctionIsAvailableIndex(const signature& sig) 
    :
    function(sig)
  {
  }

  bool requires_dyn_ctx() const { return true; }

  DEFAULT_NARY_CODEGEN(IsAvailableIndexIterator);
};

class FunctionAvailableIndexes : public function 
{
public:
  FunctionAvailableIndexes(const signature& sig) 
    :
    function(sig)
  {
  }

  bool requires_dyn_ctx() const { return false; }

  DEFAULT_NARY_CODEGEN(AvailableIndexesIterator);
};

void populateContext_Index(static_context* sctx)
{
  DECL(sctx, FunctionCreateInternalIndex,
       (createQName(ZORBA_DDL_FN_NS, "fn-zorba-ddl", "create-internal-index"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        GENV_TYPESYSTEM.EMPTY_TYPE));

  DECL(sctx, FunctionRefreshIndex,
       (createQName(ZORBA_DDL_FN_NS, "fn-zorba-ddl", "refresh-index"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        GENV_TYPESYSTEM.EMPTY_TYPE));

  DECL(sctx, FunctionIndexEntryBuilder,
       (createQName(ZORBA_DDL_FN_NS, "fn-zorba-ddl", "index-entry-builder"),
        GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE,
        true,
        GENV_TYPESYSTEM.ITEM_TYPE_STAR));

  DECL(sctx, FunctionProbeIndexPoint,
       (createQName(ZORBA_DDL_FN_NS,
                    "fn-zorba-ddl", "probe-index-point"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        true,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, FunctionProbeIndexRange,
       (createQName(ZORBA_DDL_FN_NS,
                    "fn-zorba-ddl", "probe-index-range"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        true,
        GENV_TYPESYSTEM.ANY_NODE_TYPE_STAR));

  DECL(sctx, FunctionIsDeclaredIndex,
       (createQName(ZORBA_INTROSPECT_SCTX_FN_NS,
                    "fn-zorba-introspect-sctx", "is-declared-index"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

  DECL(sctx, FunctionDeclaredIndexes,
       (createQName(ZORBA_INTROSPECT_SCTX_FN_NS,
                    "fn-zorba-introspect-sctx", "declared-indexes"),
        GENV_TYPESYSTEM.QNAME_TYPE_STAR));

  DECL(sctx, FunctionIsAvailableIndex,
       (createQName(ZORBA_INTROSPECT_DCTX_FN_NS,
                    "fn-zorba-introspect-dctx", "is-available-index"),
        GENV_TYPESYSTEM.QNAME_TYPE_ONE,
        GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE));

  DECL(sctx, FunctionAvailableIndexes,
       (createQName(ZORBA_INTROSPECT_DCTX_FN_NS,
                    "fn-zorba-introspect-dctx", "available-indexes"),
        GENV_TYPESYSTEM.QNAME_TYPE_STAR));
}


}
/* vim:set ts=2 sw=2: */
