#ifndef JLSTL_ASSERT_HPP_
#define JLSTL_ASSERT_HPP_

#include <iostream>
#include <cstdlib>
#include <exception>

namespace jlstl
{

/**
 * Set of assertion functions for writing tests.
 */
namespace Assert
{    
  /**
   * Assertion error
   */
  struct AssertionFailure : public std::exception
  {
    const char* what() const throw()
    {
      return "Test has failed.";
    }
  };

  /**
   * Assert if two values are equals (watch out for comparing non-primitives)
   *
   * @param expected
   * @param actual
   * @param message
   */
  template <typename E, typename A>
  static void assertEquals(const E& expected, const A& actual, const char* message = "");

  // TODO: the rest
#if 0
  static void assertTrue(const bool& expression, const char* message = "");
  static void assertFalse(const bool& expression, const char* message = "");

  template <typename T>
  static void assertNotNull(const T& expected, const char* message = "");

  template <typename T>
  static void assertNull(const T& expected, const char* message = "");

  static void fail();
  static void fail(const char* message);
#endif
} // namespace Assert

template <typename E, typename A>
void Assert::assertEquals(const E& expected, const A& actual, const char* message)
{
  if (expected == actual)
  {
    std::cerr << "[SUCCESS]\tassertEquals(" << expected << ',' << actual << ")\n";
  }
  else
  {
    std::cerr << "[FAILURE]: " << message << '\t'
      << "assertEquals(" << expected << ',' << actual << "):\n";
    throw AssertionFailure();
  }
}

} // namespace jlstl

#endif  // JLSTL_ASSERT_HPP_
