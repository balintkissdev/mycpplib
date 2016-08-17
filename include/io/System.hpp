#ifndef BKSTL_SYSTEM_HPP_
#define BKSTL_SYSTEM_HPP_

#include <iostream>
#include <string>

// FIXME: don't use Standard Library
namespace bkstl
{
    namespace System
    {
        namespace out
        {
            static void print(const char* str)
            {
                std::cout << str;
            }

            static void println(const char* str)
            {
                std::cout << str << '\n';
            }

            static void print(const std::string& str)
            {
                print(str.c_str());
            }

            static void println(const std::string& str)
            {
                println(str.c_str());
            }
        }

        namespace err
        {
            static void print(const char* str)
            {
                std::cerr << str;
            }

            static void println(const char* str)
            {
                std::cerr << str << '\n';
            }

            static void print(const std::string& str)
            {
                print(str.c_str());
            }

            static void println(const std::string& str)
            {
                println(str.c_str());
            }
        }

        namespace in
        {}
    }

} // namespace bkstl

#endif  // BKSTL_SYSTEM_HPP_
