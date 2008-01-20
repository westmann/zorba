/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *
 *  Authors: Nicolae Brinza
 */

#include <string>
#include <exception>
#include "util/datetime/timezone.h"
#include "util/datetime/parse.h"

#define RETURN_FALSE_ON_EXCEPTION(sequence)     \
  try                                           \
  {                                             \
    sequence;                                   \
  }                                             \
  catch (std::exception& ex)                    \
  {                                             \
    return false;                               \
  }

namespace xqp
{
    
bool TimeZone::parse_string(const xqpString& s, TimeZone_t& tz_t)
{
  std::string ss = *s.getStore();
  unsigned int position = 0;
  bool is_negative = false;

  // A time zone is of form: (('+' | '-') hh ':' mm) | 'Z'

  skip_whitespace(ss, position);
  if (position == ss.size())
    return false;
    
  if (ss[position] == 'Z')
  {
    // '+00:00', '-00:00', and 'Z' all represent the same zero-length duration timezone, UTC; 'Z' is its canonical representation.

    RETURN_FALSE_ON_EXCEPTION( tz_t = new TimeZone(boost::posix_time::duration_from_string("00:00:00")) );
    
    position++;
    
    if (ss.size() != position)
      return false;
  }
  else
  {
    if (ss[position] == '-')
      is_negative = true;
    else if (ss[position] == '+')
      /* do nothing */ ;
    else
      return false;

    position++;

    // Parse hh:mm . Add ":00" and pass it off to boost
    std::string temp = ss.substr(position,ss.size()-position) + ":00";
    if (is_negative)
      temp = "-" + temp;
  
    RETURN_FALSE_ON_EXCEPTION( tz_t = new TimeZone(boost::posix_time::duration_from_string(temp)); );
  }
  
  return true;
}

TimeZone& TimeZone::operator=(const TimeZone_t& tz_t)
{
  the_time_zone = tz_t->the_time_zone;
  return *this;
}

bool TimeZone::operator<(const TimeZone& t) const
{
  return (the_time_zone < t.the_time_zone);
}

bool TimeZone::operator==(const TimeZone& t) const
{
  return (the_time_zone == t.the_time_zone);
}

xqpString TimeZone::toString() const
{
  xqpString result;
  
  if (the_time_zone.is_not_a_date_time())
    return xqpString("");
  else
  {
    result = boost::posix_time::to_simple_string(the_time_zone);
    
    if (the_time_zone.hours() >= 0)
      result = "+" + result.substr(0, 5);
    else
      result = result.substr(0, 6);
  }
  
  return result;
}

int TimeZone::compare(const TimeZone& t) const
{
  if (operator<(t))
    return -1;
  else if (operator==(t))
    return 0;
  else
    return 1;
}

} // namespace xqp
