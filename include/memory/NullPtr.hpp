#ifndef JLSTL_NULLPTR_HPP_
#define JLSTL_NULLPTR_HPP_

namespace jlstl
{

const class NullPtr
{
  public:
    
    /**
     * Return for any type of null non-member pointer.
     */
    template<typename NON_MEMBER_TYPE>
    inline operator NON_MEMBER_TYPE*() const
    {
      return 0;
    }

    /**
     * Return for any type of null member pointer.
     */
    template<typename NON_MEMBER_TYPE, typename MEMBER_TYPE>
    inline operator MEMBER_TYPE NON_MEMBER_TYPE::*() const
    {
      return 0;
    }

  private:

    /**
     * Forbid to take address of a null pointer
     */
    void operator&() const;

} NullPtr = {};

} // namespace jlst

#endif  // JLSTL_NULLPTR_HPP_
