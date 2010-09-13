#include <iostream>

#include "runtime/core/function_trace_iterator.h"

#include "zorbaerrors/error_manager.h"
#include "errors/user_error.h"

namespace zorba {

bool FunctionTraceIterator::nextImpl(store::Item_t &result, PlanState &aPlanState) const
{
  try {
    PlanIteratorState* lState = 0;
    DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);
    while (consumeNext(result, theChildren[0], aPlanState)) {
      STACK_PUSH(true, lState);
    }
    STACK_END(lState);
  } catch (error::ZorbaError& err) {
    err.theStackTrace.push_back(error::ZorbaError::StackEntry_t(
        theFunctionLocation,
        std::pair<store::Item_t, unsigned int>(theFunctionName, theFunctionArity))
    );
    throw err;
  }
}

void FunctionTraceIterator::setFunctionName(const store::Item_t& aFunctionName)
{
  theFunctionName = aFunctionName;
}

void FunctionTraceIterator::setFunctionLocation(const QueryLoc &aFunctionLocation)
{
  theFunctionLocation = aFunctionLocation;
}

void FunctionTraceIterator::setFunctionArity(unsigned int arity)
{
  theFunctionArity = arity;
}

} // namespace zorba
