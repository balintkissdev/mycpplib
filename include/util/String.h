#ifndef BKSTL_STRING_H
#define BKSTL_STRING_H

namespace bkstl
{
    // FIXME: unfinished
    class String
    {
        public:
            String(char* str) : c_str_(str) {};
            ~String() { delete c_str_; };
            char* toCStr() { return c_str_; }

        private:
            char* c_str_;
    };
} // namespace bkstl

#endif  // BKSTL_STRING_H
