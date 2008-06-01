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

#ifndef ZORBA_DEBUGGER_ITERATORS_H
#define ZORBA_DEBUGGER_ITERATORS_H

#include <vector>

#include <boost/thread/mutex.hpp>

#include "runtime/base/narybase.h"

#include "compiler/parser/location.hh"

namespace zorba {

class ZorbaDebuggerImpl;

class FnDebugIterator : public NaryBaseIterator<FnDebugIterator, PlanIteratorState>
{
protected:
  ZorbaDebuggerImpl *  theDebugger;

public:
  FnDebugIterator( const QueryLoc& loc, std::vector<PlanIter_t>& args );

  virtual ~FnDebugIterator();

  store::Item_t nextImpl( store::Item_t& result, PlanState& planState ) const;

  void accept(PlanIterVisitor& v) const;

  void openImpl(PlanState& planState, uint32_t& offset );

};
} /* namespace zorba */

#endif /* XQP_DEBUG_ITERATORS_H */
/* vim:set ts=2 sw=2: */
