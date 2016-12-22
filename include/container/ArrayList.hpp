#ifndef JLSTL_ARRAY_LIST_HPP_
#define JLSTL_ARRAY_LIST_HPP_

#include <exception>

#include "List.hpp"

namespace jlstl
{
// FIXME: can't hold unique_ptr yet
// TODO: dynamic grow
/**
 * A dynamic list, with automatically growing array under the hood (not implemented yet)
 */
template <typename T>
class ArrayList : public List<T>
{
  public:
    ArrayList(int capacity = 1000)
      : last_index_(-1)
      , capacity_(capacity)
      , dynamic_array_(new T[capacity_])
      {};
    ~ArrayList();

    bool add(const T element);
    void clear();
    bool contains(const T& element);    // TODO: not implemented yet
    T get(int index);
    T operator[](int index);
    bool isEmpty();
    size_t size();

    /**
     * Query currently allocated capacity
     */
    int capacity();

  private:
    int last_index_;
    int capacity_;
    T* dynamic_array_;

    /**
     * Resizing helper
     */
    void resize(size_t new_size);

    /**
     * Eraser for value types used in clear()
     */
    void erase(T& value);

    /**
     * Eraser for pointer type used in clear()
     */
    void erase(T*& ptr);
};

template <typename T>
inline ArrayList<T>::~ArrayList()
{
  clear();
  delete[] dynamic_array_;
}

template <typename T>
inline bool ArrayList<T>::add(const T element)
{
  if (capacity_ <= size())
  {
    resize(capacity_ + 1000);
  }
  dynamic_array_[++last_index_] = element;
  return true;
}

template <typename T>
inline void ArrayList<T>::clear()
{
  for (int i = 0; i < last_index_; ++i)
  {
    erase(dynamic_array_[i]);
  }
  last_index_ = -1;
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
inline bool ArrayList<T>::isEmpty()
{
  return -1 < last_index_;
}

template <typename T>
inline size_t ArrayList<T>::size()
{
  return last_index_ + 1;
}

template <typename T>
inline int ArrayList<T>::capacity()
{
  return capacity_;
}

template <typename T>
void ArrayList<T>::resize(size_t new_size)
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
  ptr = 0;
}

} // namespace jlstl

#endif  // JLSTL_ARRAY_LIST_HPP_
