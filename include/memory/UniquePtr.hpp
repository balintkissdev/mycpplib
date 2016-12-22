#ifndef JLSTL_UNIQUE_PTR_HPP_
#define JLSTL_UNIQUE_PTR_HPP_

namespace jlstl
{
/**
 * Unique pointer for managing lifecycle of objects on the heap.
 * Uses template specialization to help define custom deleter.
 */
template <typename T, typename D = void>
class UniquePtr
{
  public:

    /**
     * Default constructor to initialize to null
     */
    UniquePtr()
      : ptr_()
      {};

    /**
     * Wrap memory resource
     *
     * @param new_ptr   Raw pointer to wrap
     */
    UniquePtr(const T* new_ptr)
      : ptr_(new_ptr) 
      {};

    /**
     * Wrap memory resource and specify deleter
     *
     * @param raw_ptr
     * @param deleter
     */
    UniquePtr(const T* new_ptr, const D deleter )
      : ptr_(new_ptr)
      , deleter_(deleter)
      {};

    /**
     * Destroy managed object when leaving scope with custom deleter
     */
    ~UniquePtr();

    UniquePtr(const UniquePtr& other);              // Disallow copy construction
    UniquePtr& operator=(const UniquePtr& other);   // Disallow copy assignment

    /**
     * Release ownership of memory resource as raw pointer. 
     * Be careful, it will leak if not deleted manually after release.
     *
     * @return
     */
    T* release();

    /**
     * Replace managed object.
     *
     * @param
     */
    void reset(const T* new_ptr);

    /**
     * Free managed object.
     */
    void reset();

    /**
     * Access underlying raw pointer.
     *
     * @return
     */
    T* get();

    /**
     * Dereference pointer and return value.
     *
     * @return
     */
    T& operator*();

    /**
     * Member access override.
     *
     * @return
     */
    T* operator->();

    // FIXME: use safe bool idiom
    /**
     * Enable unique pointer to be used as conditional.
     */
    operator bool() const;

  private:
    UniquePtr<T> ptr_;
    D deleter_;
};

/**
* Unique pointer for managing lifecycle of objects on the heap.
* This one has a default delete to eliminate size overhead.
*/
template <typename T>
class UniquePtr<T, void>
{
  public:
    /**
     * Default constructor to initialize to null
     */
    UniquePtr()
      : raw_ptr_(0)
      {};

    /**
     * Wrap memory resource
     */
    UniquePtr(const T* new_ptr)
      : raw_ptr_(new_ptr)
      {};

    /**
     * Destroy managed object when leaving scope
     */
    ~UniquePtr();

    UniquePtr(const UniquePtr& other);              // Disallow copy construction
    UniquePtr& operator=(const UniquePtr& other);   // Disallow copy assignment

    /**
     * Release ownership of memory resource as war pointer. Be careful, it will leak if not deleted manually after release.
     */
    T* release();

    /**
     * Replace managed object.
     */
    void reset(T* new_ptr);

    /**
     * Free managed object.
     */
    void reset();

    /**
     * Access underlying raw pointer.
     */
    T* get();

    /**
     * Dereference pointer and return value.
     */
    T& operator*();

    /**
     * Member access override.
     */
    T* operator->();

    // FIXME: use safe bool idiom
    /**
     * Enable unique pointer to be used as conditional.
     */
    operator bool() const;

  private:
    T* raw_ptr_;
};

template <typename T>
inline UniquePtr<T>::~UniquePtr()
{
  delete raw_ptr_;
}

template <typename T>
inline T* UniquePtr<T>::release()
{
  T* tmp = raw_ptr_;
  raw_ptr_ = 0;
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
  raw_ptr_ = 0;
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
} // namespace jlstl

#endif  // JLSTL_UNIQUE_PTR_HPP_
