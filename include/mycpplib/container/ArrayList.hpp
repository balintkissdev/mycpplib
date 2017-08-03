#ifndef _MYCPPLIB_ARRAY_LIST_HPP_
#define _MYCPPLIB_ARRAY_LIST_HPP_

#include <mycpplib/memory/NullPtr.hpp>

namespace mycpplib
{
// FIXME: can't hold unique_ptr yet
// TODO: dynamic grow yet
/**
 * A dynamic list, with automatically growing array under the hood.
 */
template <typename T>
class ArrayList
{
  public:

    // TODO: better comments
    /**
     * Constructor
     */
    ArrayList(int capacity = 1000)
      : last_index_(-1)
      , capacity_(capacity)
      , dynamic_array_(new T[capacity_])
      {};

    /**
     * Copy constructor
     */
    ArrayList(const ArrayList& other);

    /**
     * Copy assignment
     */
    ArrayList& operator=(const ArrayList& rhs);

    /**
     * Destructor
     */
    ~ArrayList();

    /**
     * Insert element to list.
     *
     * @param element
     * @return
     */
    bool add(const T element);

    /**
     * Insert object to specific index in the list.
     *
     * @param index
     * @param element
     */
    void add(const int index, const T element);

    /**
     * Remove all elements from list.
     */
    void clear();

    /**
     * Check if list contains a specific element.
     *
     * @param element
     * @return
     */
    bool contains(const T& element) const;

    /**
     * Access element at specified index.
     */
    T get(const int index);

    /**
     * Array subscript operator overload.
     */
    T operator[](int index);

    /**
     * Return index of first occurence of element in the list.
     *
     * @param element
     * @return
     */
    int indexOf(const T& element) const;

    /**
     * Check if list is empty.
     *
     * @return
     */
    bool isEmpty() const;

    /**
     * Return the index of the last element in the list.
     *
     * @param element
     * @return
     */
    int lastIndexOf(const T& element) const;

    /**
     * Remove element at specified index from the list.
     *
     * @param index
     * @return
     */
    T remove(const int index);

    /**
     * Remove specified element from the list.
     *
     * @param element
     * @return
     */
    bool remove(const T& element);

    /**
     * Replace element at specified position with specified element.
     *
     * @param index
     * @param element
     * @return  previously stored element at specified location
     */
    T set(const int index, const T& element);

    /**
     * Query number of stored elements
     *
     * @return
     */
    int size() const;

    /**
     * Sort with comparator. (TODO)
     */
    void sort();
    
    /**
     * Return portion of the list.
     *
     * @param from_index
     * @param to_index
     * @return
     */
    ArrayList<T> subList(const int from_index, const int to_index);
    
    /**
     * Return array representation of existing list.
     *
     * @return
     */
    T* toArray();

    /**
     * Query currently allocated capacity
     */
    int capacity() const;

  private:
    int last_index_;
    int capacity_;
    T* dynamic_array_;

    /**
     * Resizing helper
     */
    void resize(int new_size);

    /**
     * Eraser for value types used in clear()
     */
    void erase(T& value);

    /**
     * Eraser for pointer type used in clear()
     */
    void erase(T*& ptr);
};

#include <mycpplib/container/ArrayList.inl>

} // namespace mycpplib

#endif  // _MYCPPLIB_ARRAY_LIST_HPP_
