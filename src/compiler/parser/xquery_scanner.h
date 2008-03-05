#ifndef ZORBA_XQUERY_SCANNER_H
#define ZORBA_XQUERY_SCANNER_H

// Flex expects the signature of yylex to be defined in the macro YY_DECL, and
 // the C++ parser expects it to be declared. We can factor both as follows.

#ifndef YY_DECL

#define YY_DECL                                              \
  zorba::xquery_parser::token_type                         \
  zorba::xquery_scanner::lex(                              \
    zorba::xquery_parser::semantic_type* yylval,           \
    zorba::xquery_parser::location_type* yylloc            \
    )
#endif

#ifndef __FLEX_LEXER_H
#undef yyFlexLexer
#define yyFlexLexer ZorbaFlexLexer
#include "compiler/parser/FlexLexer.h"
#endif

#include "compiler/parser/xquery_parser.hpp"

namespace zorba {

class xquery_driver;

class xquery_scanner : public ZorbaFlexLexer
{
private:
  xquery_driver* theDriver;

public:
  /** Create a new scanner object. The streams arg_yyin and arg_yyout default
   * to cin and cout, but that assignment is only made when initializing in
   * yylex(). */
  xquery_scanner(xquery_driver* aDriver, std::istream* arg_yyin = 0, std::ostream* arg_yyout = 0);

  /** Required for virtual functions */
  virtual ~xquery_scanner();

  /** This is the main lexing function. It is generated by flex according to
   * the macro declaration YY_DECL above. The generated bison parser then
   * calls this virtual function to fetch new tokens. */
  virtual 
  zorba::xquery_parser::token_type lex ( 
    zorba::xquery_parser::semantic_type* yylval, 
    zorba::xquery_parser::location_type* yylloc
  );

  xquery_driver* getDriver() const { return theDriver; } 
};

} 

#endif // EXAMPLE_SCANNER_H
