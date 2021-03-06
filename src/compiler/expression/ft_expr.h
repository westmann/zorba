/*
 * Copyright 2006-2016 zorba.io
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
#pragma once
#ifndef ZORBA_COMPILER_FT_EXPR_H
#define ZORBA_COMPILER_FT_EXPR_H

#include "common/shared_types.h"

#include "compiler/expression/expr_base.h"
#include "compiler/expression/ftnode_classes.h"

namespace zorba {

/**
 * An ftcontains_expr is-an expr for the FTContainsExpr.
 */
class ftcontains_expr : public expr
{
  friend class expr;
  friend class ExprIterator;
  friend class ExprManager;

protected:
  ftcontains_expr(
    CompilerCB* ccb,
    static_context*,
    user_function*,
    QueryLoc const&,
    expr* range,
    ftnode *ftselection,
    expr* ftignore
  );

public:
  void compute_scripting_kind();

  expr* get_range() const { return range_; }
  ftnode_t get_ftselection() const;
  expr* get_ignore() const { return ftignore_; }

  void accept( expr_visitor& );

  std::ostream& put( std::ostream& ) const;

private:
  expr* range_;
  ftnode_t ftselection_;
  expr* ftignore_;
};

} // namespace zorba

#endif /* ZORBA_FT_EXPR_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
