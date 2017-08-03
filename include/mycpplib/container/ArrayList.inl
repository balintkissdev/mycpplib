template <typename T>
inline ArrayList<T>::~ArrayList()
{
  clear();
  delete[] dynamic_array_;
}

template <typename T>
inline ArrayList<T>::ArrayList(const ArrayList& other)
{
  //TODO
#if 0
  clear();
  delete[] dynamic_array_;

  last_index_ = other.last_index_;
  capacity_ = other.capacity;
  std::copy(other.dynamic_array_, other.dynamic_array_ + capacity_, dynamic_array_);
#endif
}

template <typename T>
bool ArrayList<T>::add(const T element)
{
  if (capacity_ <= size())
  {
    resize(capacity_ + 1000);
  }
  dynamic_array_[++last_index_] = element;
  return true;
}

template <typename T>
void ArrayList<T>::add(const int index, const T element)
{
  // TODO
}

template <typename T>
void ArrayList<T>::clear()
{
  for (int i = 0; i < last_index_; ++i)
  {
    erase(dynamic_array_[i]);
  }
  last_index_ = -1;
}

template <typename T>
bool ArrayList<T>::contains(const T& element) const
{
  // TODO
  return false;
}

template <typename T>
T ArrayList<T>::get(const int index)
{
  if (-1 < index && index <= last_index_)
  {
    return dynamic_array_[index];
  }
  else
  {
    throw std::exception(); // TODO
  }
}

template <typename T>
inline T ArrayList<T>::operator[](const int index)
{
  return get(index);
}

template <typename T>
inline int ArrayList<T>::indexOf(const T& element) const
{
  // TODO
  return -1;
}

template <typename T>
inline bool ArrayList<T>::isEmpty() const
{
  return -1 < last_index_;
}

template <typename T>
inline int ArrayList<T>::lastIndexOf(const T& element) const
{
  // TODO
  return -1;
}

template <typename T>
inline T ArrayList<T>::remove(const int index)
{
  // TODO
  return 0;
}

template <typename T>
inline bool ArrayList<T>::remove(const T& element)
{
  // TODO
  return false;
}

template <typename T>
inline T ArrayList<T>::set(const int index, const T& element)
{
  // TODO
  return 0;
}

template <typename T>
inline int ArrayList<T>::size() const
{
  return last_index_ + 1;
}

template <typename T>
inline void ArrayList<T>::sort()
{
  // TODO
}

template <typename T>
inline ArrayList<T> subList(const int from_index, const int to_index)
{
  // TODO
  return NullPtr;
}

template <typename T>
inline T* ArrayList<T>::toArray()
{
  // TODO
  return NullPtr;
}

template <typename T>
inline int ArrayList<T>::capacity() const
{
  return capacity_;
}

template <typename T>
void ArrayList<T>::resize(int new_size)
{
  // Reallocate
  capacity_ = new_size;
  T* realloc = new T[capacity_];

  // Copy
  for (int i = 0; i < new_size; ++i)
  {
    realloc[i] = dynamic_array_[i];
  }
  delete[] dynamic_array_;
  dynamic_array_ = realloc;
}

template <typename T>
inline void ArrayList<T>::erase(T& value)
{
  value = 0;
}

template <typename T>
inline void ArrayList<T>::erase(T*& ptr)
{
  delete ptr;
  ptr = NullPtr;
}
