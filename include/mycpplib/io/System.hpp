#ifndef _MYCPPLIB_SYSTEM_HPP_
#define _MYCPPLIB_SYSTEM_HPP_

#include <cstdio>

namespace mycpplib
{
namespace System
{
namespace out
{
  void print(const char* str)
  {
    printf("%s", str);
  }

  void println(const char* str)
  {
    printf("%s\n", str);
  }
} // namespace out

namespace err
{
  void print(const char* str)
  {
    fprintf(stderr, "%s", str);
  }

  void println(const char* str)
  {
    fprintf(stderr, "%s\n", str);
  }
} // namespace err

namespace in
{

} // namespace in
} // namespace System
} // namespace mycpplib

#endif  // _MYCPPLIB_SYSTEM_HPP_
