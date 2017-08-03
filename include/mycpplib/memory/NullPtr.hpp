#ifndef _MYCPPLIB_NULLPTR_HPP_
#define _MYCPPLIB_NULLPTR_HPP_

namespace mycpplib
{

/**
 * Null pointer type based on Scott Meyer's idiom.
 */
const class NullPtrType
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

} // namespace mycpplib

#endif  // _MYCPPLIB_NULLPTR_HPP_
