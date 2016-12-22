#ifndef JLSTL_ITERATOR_HPP_
#define JLSTL_ITERATOR_HPP_

#include "../container/List.hpp"

// FIXME: Header dependency hell problems
// TODO: optimization
namespace jlstl
{

template <typename T>
class Iterator
{
  public:
    Iterator(const List<T>& list) : index_(0), list_(list) {};
    ~Iterator() {};

    // STL-style operations
    T operator*();
    Iterator& operator++();

    // Java-style operations
    T first();
    T last();
    T next();
    bool hasNext() const;
    T get();

  private:
    int index_;
    const List<T>& list_;
};

template <typename T>
inline T Iterator<T>::operator*()
{
  return get();
}

template <typename T>
inline Iterator<T>& Iterator<T>::operator++()
{
  ++index_;
  return *this;
}

template <typename T>
inline T Iterator<T>::first()
{
  index_ = 0;
  return get();
}

template <typename T>
inline T Iterator<T>::last()
{
  index_ = list_.size() - 1;
  return get();
}

template <typename T>
inline T Iterator<T>::next()
{
  ++index_;
  get();
}

template <typename T>
inline bool Iterator<T>::hasNext() const
{
  return index_ < list_.size();
}

template <typename T>
inline T Iterator<T>::get()
{
  if (!hasNext())
  {
    throw std::exception();     // TODO
  }
  return list_[index_];
}

} // namespace jlstl

#endif  // JLSTL_ITERATOR_HPP_
