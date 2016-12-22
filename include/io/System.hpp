#ifndef JLSTL_SYSTEM_HPP_
#define JLSTL_SYSTEM_HPP_

#include <cstdio>

namespace jlstl
{
namespace System
{
namespace out
{
  static void print(const char* str)
  {
    printf("%s", str);
  }

  static void println(const char* str)
  {
    printf("%s\n", str);
  }
} // namespace out

namespace err
{
  static void print(const char* str)
  {
    fprintf(stderr, "%s", str);
  }

  static void println(const char* str)
  {
    fprintf(stderr, "%s\n", str);
  }
} // namespace err

namespace in
{

} // namespace in
} // namespace System
} // namespace jlstl

#endif  // JLSTL_SYSTEM_HPP_
