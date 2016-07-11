#ifndef BKSTL_ASSERT_H
#define BKSTL_ASSERT_H

#include <iostream>
#include <cstdlib>
#include <exception>

namespace bkstl
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
     * Set of assertion functions for writing tests.
     */
    class Assert
    {
        public:

            /**
             * Assert if two values are equals (watch out for comparing non-primitives)
             *
             * @param expected
             * @param actual
             * @param message
             */
            template <typename E, typename A>
            static void assertEquals(const E& expected, const A& actual, const std::string& message = "");

        // TODO: the rest
        
        private:
            Assert() {};
            ~Assert() {};
    };

    template <typename E, typename A>
    void Assert::assertEquals(const E& expected, const A& actual, const std::string& message)
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
}

#endif  // BKSTL_ASSERT_H
