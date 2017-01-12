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
     * Insert element to list.
     *
     * @param element
     * @return
     */
    virtual bool add(const T element) = 0;

    /**
     * Insert object to specific index in the list.
     *
     * @param index
     * @param element
     */
    virtual void add(const int index, const T element) = 0;

    /**
     * Remove all elements from list.
     */
    virtual void clear() = 0;

    /**
    * Check if list contains a specific element.
    *
    * @param element
    * @return
    */
    virtual bool contains(const T& element) const = 0;

    /**
     * Access element at specified index.
     */
    virtual T get(const int index) = 0;

    /**
     * Array subscript operator overload.
     */
    virtual T operator[](const int index) = 0;

    /**
     * Return index of first occurence of element in the list.
     *
     * @param element
     * @return
     */
    virtual int indexOf(const T& element) const = 0;

    /**
     * Check if list is empty.
     *
     * @return
     */
    virtual bool isEmpty() const = 0;

    // FIXME: Header dependency problems
    /**
     * Return a Java-style iterator
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
     * Return the index of the last element in the list.
     *
     * @param element
     * @return
     */
    virtual int lastIndexOf(const T& element) const = 0;

    /**
     * Remove element at specified index from the list.
     *
     * @param index
     * @return
     */
    virtual T remove(const int index) = 0;

    /**
     * Remove specified element from the list.
     *
     * @param element
     * @return
     */
    virtual bool remove(const T& element) = 0;

    /**
     * Replace element at specified position with specified element.
     *
     * @param index
     * @param element
     * @return  previously stored element at specified location
     */
    virtual T set(const int index, const T& element) = 0;

    /**
     * Query number of stored elements
     *
     * @return
     */
    virtual int size() const = 0;

    /**
     * Sort with comparator. (TODO)
     */
    virtual void sort() = 0;

    /**
     * Return array representation of existing list.
     *
     * @return
     */
    virtual T* toArray() = 0;

};
} // namespace jlstl

#endif  // JLSTL_LIST_HPP_
