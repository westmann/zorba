#ifndef ZORBA_SPECIFICATON
#define ZORBA_SPECIFICATON

#include <vector>
#include <string>

#include <boost/spirit.hpp>
#include <boost/bind.hpp>

class Specification
{
  typedef char char_t;
  typedef boost::spirit::file_iterator <char_t> iterator_t;
  typedef boost::spirit::scanner<iterator_t> scanner_t;
  typedef boost::spirit::rule<scanner_t> rule_t;

public:
  struct Variable {
    bool theInline;
    std::string theVarName, theVarValue;
  };

  Specification() : theInline(false) {}

private:
  bool theInline;
  std::string theVarName, theVarValue;
  std::vector<Variable> theVariables;
  std::vector<std::string> theErrors;

  void setInline(iterator_t, iterator_t) {
    theInline = true;
  }

  void setVarName(iterator_t str, iterator_t end) {
    theVarName = std::string(str, end);
  }

  void setVarValue(iterator_t str, iterator_t end) {
    theVarValue = std::string(str, end);
  }

  void addVariable(iterator_t str, iterator_t end) {
    Variable args = { theInline, theVarName, theVarValue};
    theVariables.push_back(args);
  }

  void addError(iterator_t str, iterator_t end) {
    std::string s(str, end);
    theErrors.push_back(s);
  }

public:
  std::vector<Variable>::const_iterator
  variablesBegin() { return theVariables.begin(); }
  std::vector<Variable>::const_iterator
  variablesEnd()   { return theVariables.end(); }

  std::vector<std::string>::const_iterator
  errorsBegin() { return theErrors.begin(); }
  std::vector<std::string>::const_iterator
  errorsEnd()    { return theErrors.end(); }

  size_t
  variablesSize() { return theVariables.size(); }

  size_t
  errorsSize() { return theErrors.size(); }

  bool
  parseFile(std::string str)
  {
    rule_t props
      = (+(boost::spirit::graph_p & ~boost::spirit::ch_p(':') & ~boost::spirit::ch_p('=')))[bind(&Specification::setVarName, this, _1, _2)]
      >> boost::spirit::str_p("=")[bind(&Specification::setInline, this, _1, _2)]
      >> (+boost::spirit::graph_p)[bind(&Specification::setVarValue, this, _1, _2)];

    rule_t propsInline
      = (+(boost::spirit::graph_p & ~boost::spirit::ch_p(':') & ~boost::spirit::ch_p('=')))[bind(&Specification::setVarName, this, _1, _2)]
      >> boost::spirit::str_p(":=") 
      >> (+boost::spirit::graph_p)[bind(&Specification::setVarValue, this, _1, _2)];
    
    rule_t argument 
      =  boost::spirit::str_p("Args:") 
      >> +(
            boost::spirit::blank_p
         && boost::spirit::str_p("-x")
         && boost::spirit::blank_p
         && (props | propsInline)[bind(&Specification::addVariable, this, _1, _2)]
         )
      >> !boost::spirit::eol_p;

    rule_t error  
      =  boost::spirit::str_p("Error:") 
      >> !boost::spirit::blank_p
      >> (*boost::spirit::print_p)[bind(&Specification::addError, this, _1, _2)] 
      >> !boost::spirit::eol_p;

    rule_t defs = *( argument | error );

    iterator_t first(str.c_str());
    if (!first)
      return false;

    iterator_t last = first.make_end();

    return boost::spirit::parse(first, last, defs).full; 
  }
};
#endif
