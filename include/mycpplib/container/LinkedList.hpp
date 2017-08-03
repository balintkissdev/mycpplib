#ifndef _MYCPPLIB_LINKED_LIST_HPP_
#define _MYCPPLIB_LINKED_LIST_HPP_

#include <mycpplib/memory/NullPtr.hpp>

namespace mycpplib
{

template <typename T>
class LinkedList
{
  public:

    /**
     * Constructor
     */
    LinkedList() 
      : size_(0)
      , head_node_(NullPtr)
    {}

    /**
     * Destructor
     */
    ~LinkedList();

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
     * Insert element to the beginning of linked list.
     *
     * @param element
     */
    void addFirst(const T element);

    /**
     * Append element to the end of linked list.
     *
     * @param element
     */
    void addLast(const T element);

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
    T get(const size_t index);

    /**
     * Array subscript operator overload.
     */
    T operator[](const int index);
    
    /**
     * Return first element in linked list.
     *
     * @return
     */
    T getFirst();

    /**
     * Return last element in linked list.
     *
     * @return
     */
    T getLast();

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
     * Remove and return first element from linked list.
     *
     * @return
     */
    T removeFirst();

    /**
     * Remove and return last element from linked list.
     *
     * @return
     */
    T removeLast();

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
     * Return array representation of existing list.
     *
     * @return
     */
    T* toArray();

  private:
    struct DoubleNode;

    size_t size_;
    DoubleNode* head_node_;

    /**
     * Traverse until the end of list
     */
    DoubleNode* traverse();

    /**
     * Traverse until specified index
     */
    DoubleNode* traverse(const int index);

};

#include <mycpplib/container/LinkedList.inl>

} // namespace mycpplib

#endif  // MYCPPLIB_LINKED_LIST_HPP_
