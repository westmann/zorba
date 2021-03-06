/*
 * Copyright 2013 2006-2016 zorba.io.
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
#ifndef ZORBA_PARSER_HELPERS_H
#define ZORBA_PARSER_HELPERS_H

#include <ostream>
#include <string>
#include <zorba/config.h>

namespace zorba {

  class location;

  namespace parser {

    extern const char *the_tumbling, *the_sliding, *the_start, *the_end, *the_only_end, *the_declare, *the_create;

    // transform a parser location into a QueryLoc
    QueryLoc createQueryLoc(const location& aLoc);

  }


}
#endif
