template <typename T>
struct LinkedList<T>::DoubleNode
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
  
template <typename T>
inline LinkedList<T>::~LinkedList()
{
  clear();
}

template <typename T>
bool LinkedList<T>::add(const T element)
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
void LinkedList<T>::clear()
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
T LinkedList<T>::get(const size_t index)
{
  if (index < size_)
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
typename LinkedList<T>::DoubleNode* LinkedList<T>::traverse()
{
  DoubleNode* current = head_node_;
  while (current->next_node)
  {
    current = current->next_node;
  }
  return current;
}

template <typename T>
typename LinkedList<T>::DoubleNode* LinkedList<T>::traverse(const int index)
{
  DoubleNode* current = head_node_;
  for (int i = 0; i < index; ++i)
  {
    current = current->next_node;
  }
  return current;
}
