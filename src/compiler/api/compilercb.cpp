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

#include "compiler/api/compilercb.h"
#include "compiler/expression/expr_base.h"

#include "context/static_context.h"

#include "util/properties.h"


namespace zorba {

#define DEF_PRINT_EXPR_TREE( phase )                                    \
  static void print_expr_tree_##phase (const expr *e, std::string name) \
  {                                                                     \
    std::ostream &os = Properties::instance ()->debug_out ();           \
    os << "Expression tree after " << #phase                            \
       << " for " << name << "\n";                                      \
    e->put (os) << std::endl;                                           \
  }

  DEF_PRINT_EXPR_TREE (translation)
  DEF_PRINT_EXPR_TREE (normalization)
  DEF_PRINT_EXPR_TREE (optimization)


CompilerCB::CompilerCB(std::map<short, static_context_t>& sctx_map)
  :
  m_is_loadprolog(false),
  m_context_map(sctx_map),
  m_sctx(0),
  m_cur_sctx(0),
  m_error_manager(0)
#ifdef ZORBA_DEBUGGER
 ,m_debugger(0)
#endif
{
}


CompilerCB::CompilerCB(const CompilerCB& cb)
  :
  m_is_loadprolog(false),
  m_context_map(cb.m_context_map),
  m_sctx(NULL),
  m_cur_sctx(m_cur_sctx),
  m_error_manager(cb.m_error_manager),
  m_config(cb.m_config)
#ifdef ZORBA_DEBUGGER
  ,m_debugger(cb.m_debugger)
#endif
{
}
  

CompilerCB::~CompilerCB() 
{
}


CompilerCB::config::config ()
  :
  opt_level (O1),
  lib_module(false),
  parse_cb (NULL)
{
  translate_cb = normalize_cb = optimize_cb = NULL;
  // TODO: move these out
  print_item_flow = Properties::instance()->printItemFlow();
  if (Properties::instance()->printTranslated())
    translate_cb = print_expr_tree_translation;
  if (Properties::instance()->printNormalized())
    normalize_cb = print_expr_tree_normalization;
  if (Properties::instance()->printOptimized())
    optimize_cb = print_expr_tree_optimization;
  force_gflwor = Properties::instance()->forceGflwor();
}

} /* namespace zorba */
