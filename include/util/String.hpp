#ifndef JLSTL_STRING_HPP_
#define JLSTL_STRING_HPP_

namespace jlstl
{
  // TODO: unfinished
  class String
  {
    public:
      String(char* str) : c_str_(str) {};
      ~String() { delete c_str_; };
      char* toCharArray() { return c_str_; }

    private:
      char* c_str_;
  };

} // namespace jlstl

#endif  // JLSTL_STRING_HPP_
