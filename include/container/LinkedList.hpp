#ifndef JLSTL_LINKED_LIST_HPP_
#define JLSTL_LINKED_LIST_HPP_

#include <exception>

#include "List.hpp"
#include "../memory/NullPtr.hpp"

namespace jlstl
{

template <typename T>
class LinkedList : public List<T>
{
  public:
    struct DoubleNode
    {
      T value;
      DoubleNode* previous_node;
      DoubleNode* next_node;

      DoubleNode()
        : previous_node(NullPtr)
        , next_node(NullPtr)
        {}

      DoubleNode(const T x)
        : value(x)
        , previous_node(NullPtr)
        , next_node(NullPtr)
        {}
    };

    LinkedList() 
      : size_(0)
      , head_node_(NullPtr)
    {}
    ~LinkedList();

    bool add(const T element);
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

    void clear();
    bool contains(const T& element) const;
    T get(const int index);
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

    int indexOf(const T& element) const;
    bool isEmpty() const;
    int lastIndexOf(const T& element) const;
    T remove(const int index);
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

    T set(const int index, const T& element);
    int size() const;
    void sort();
    T* toArray();

  private:
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

template <typename T>
inline LinkedList<T>::~LinkedList()
{
  clear();
}

template <typename T>
inline bool LinkedList<T>::add(const T element)
{
  // Initial insert
  if (!head_node_)
  {
    head_node_ = new DoubleNode(element);
  }
  // Continous insert
  else
  {
    traverse()->next_node = new DoubleNode(element);
  }
  ++size_;

  return true;
}

template <typename T>
inline void LinkedList<T>::add(const int index, const T element)
{
  // TODO
}

template <typename T>
inline void LinkedList<T>::addFirst(const T element)
{
  // TODO
}

template <typename T>
inline void LinkedList<T>::addLast(const T element)
{
  // TODO
}

template <typename T>
inline void LinkedList<T>::clear()
{
  // Start from beginning and delete everything from there
  DoubleNode* current = head_node_;
  DoubleNode* tmp = 0;
  while (current)
  {
    tmp = current;
    current = tmp->next_node;
    delete tmp;
  }
  head_node_ = 0;
  size_ = 0;
}

template <typename T>
inline bool LinkedList<T>::contains(const T& element) const
{
  // TODO
  return 0;
}

template <typename T>
inline T LinkedList<T>::get(const int index)
{
  if (-1 < index && index < size_)
  {
    return traverse(index)->value;
  }
  throw std::exception();
}

template <typename T>
inline T LinkedList<T>::getFirst()
{
  // TODO
  return 0;
}

template <typename T>
inline T LinkedList<T>::getLast()
{
  // TODO
  return 0;
}

template <typename T>
inline T LinkedList<T>::operator[](const int index)
{
  return get(index);
}

template <typename T>
inline int LinkedList<T>::indexOf(const T& element) const
{
  // TODO
  return -1;
}

template <typename T>
inline bool LinkedList<T>::isEmpty() const
{
  return size_ < 1;
}

template <typename T>
inline int LinkedList<T>::lastIndexOf(const T& element) const
{
  // TODO
  return -1;
}

template <typename T>
inline T LinkedList<T>::remove(const int index)
{
  // TODO
  return 0;
}

template <typename T>
inline bool LinkedList<T>::remove(const T& element)
{
  // TODO
  return false;
}

template <typename T>
inline T LinkedList<T>::removeFirst()
{
  // TODO
  return 0;
}

template <typename T>
inline T LinkedList<T>::removeLast()
{
  // TODO
  return 0;
}

template <typename T>
inline T LinkedList<T>::set(const int index, const T& element)
{
  // TODO
  return 0;
}

template <typename T>
inline int LinkedList<T>::size() const
{
  return size_;
}

template <typename T>
inline void LinkedList<T>::sort()
{
  // TODO
}

template <typename T>
inline T* LinkedList<T>::toArray()
{
  // TODO
  return NullPtr;
}

template <typename T>
inline typename LinkedList<T>::DoubleNode* LinkedList<T>::traverse()
{
  DoubleNode* current = head_node_;
  while (current->next_node)
  {
    current = current->next_node;
  }
  return current;
}

template <typename T>
inline typename LinkedList<T>::DoubleNode* LinkedList<T>::traverse(const int index)
{
  DoubleNode* current = head_node_;
  for (int i = 0; i < index; ++i)
  {
    current = current->next_node;
  }
  return current;
}

} // namespace jlstl

#endif  // JLSTL_LINKED_LIST_HPP_
