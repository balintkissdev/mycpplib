#ifndef JLSTL_LIST_HPP_
#define JLSTL_LIST_HPP_

#include <cstddef>

namespace jlstl
{

/**
 * List interface
 */
template <typename T>
class List
{
  public:
    virtual ~List() {};

    /**
     * Insert object to list.
     */
    virtual bool add(const T element) = 0;

    /**
     * Remove all elements from list.
     */
    virtual void clear() = 0;

    /**
     * Check if list contains a specific element.
     */
    // TODO
#if 0
     virtual bool contains(const T& element) = 0;
#endif

    /**
     * Access element at specified index.
     */
    virtual T get(const int index) = 0;

    /**
     * Array subscript operator overload.
     */
    virtual T operator[](const int index) = 0;

    /**
      Check if list is empty
      */
    virtual bool isEmpty() = 0;

    // FIXME: Header dependency problems
    /**
     * Return an iterator
     */
#if 0
    Iterator<T> iterator()
    {
      return Iterator<T>(*this);
    }

    Iterator<T> begin()
    {
      return iterator();
    }

    Iterator<T> end()
    {
      Iterator<T> it;
      it.last();
      return it;
    }
#endif

    /**
     * Remove element at specified index
     */
    // TODO: T remove(int index) = 0;

    /**
     * Query number of stored elements
     */
    virtual size_t size() = 0;
};
} // namespace jlstl

#endif  // JLSTL_LIST_HPP_
