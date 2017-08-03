template <typename T>
inline UniquePtr<T>::~UniquePtr()
{
  delete raw_ptr_;
}

template <typename T>
inline T* UniquePtr<T>::release()
{
  T* tmp = raw_ptr_;
  raw_ptr_ = NullPtr;
  return tmp;
}

template <typename T>
inline void UniquePtr<T>::reset(T* new_ptr)
{
  reset();
  raw_ptr_ = new_ptr;
}

template <typename T>
inline void UniquePtr<T>::reset()
{
  delete raw_ptr_;
  raw_ptr_ = NullPtr;
}

template <typename T>
inline T* UniquePtr<T>::get()
{
  return raw_ptr_;
}

template <typename T>
inline T& UniquePtr<T>::operator*()
{
  return *raw_ptr_;
}

template <typename T>
inline T* UniquePtr<T>::operator->()
{
  return raw_ptr_;
}

template <typename T>
inline UniquePtr<T>::operator bool() const 
{
  return raw_ptr_;
}

/** Template overloads with custom deleter **/

template <typename T, typename D>
inline UniquePtr<T, D>::~UniquePtr()
{
  deleter_(ptr_.release());
}

template <typename T, typename D>
inline T* UniquePtr<T, D>::release()
{
  return ptr_.release();
}

template <typename T, typename D>
inline void UniquePtr<T, D>::reset(T* new_ptr)
{
  reset();
  ptr_.reset(new_ptr);
}

template <typename T, typename D>
inline void UniquePtr<T, D>::reset()
{
  deleter_(ptr_.release());
}

template <typename T, typename D>
inline T* UniquePtr<T, D>::get()
{
  return ptr_.get();
}

template <typename T, typename D>
inline T& UniquePtr<T, D>::operator*()
{
  return *ptr_;
}

template <typename T, typename D>
inline T* UniquePtr<T, D>::operator->()
{
  return ptr_.get();
}

template <typename T, typename D>
inline UniquePtr<T, D>::operator bool() const 
{
  return ptr_.get();
}
