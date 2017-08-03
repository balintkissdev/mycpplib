#ifndef _MYCPPLIB_UNIQUE_PTR_HPP_
#define _MYCPPLIB_UNIQUE_PTR_HPP_

#include <mycpplib/memory/NullPtr.hpp>

namespace mycpplib
{

/**
 * Unique pointer for managing lifecycle of objects on the heap.
 *
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
      : ptr_(NullPtr)
      {};

    /**
     * Wrap memory resource
     *
     * @param new_ptr   Raw pointer to wrap
     */
    UniquePtr(T* new_ptr)
      : ptr_(new_ptr) 
      {};

    /**
     * Wrap memory resource and specify deleter
     *
     * @param raw_ptr
     * @param deleter
     */
    UniquePtr(T* new_ptr, const D deleter )
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
    void reset(T* new_ptr);

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
 *
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
      : raw_ptr_(NullPtr)
      {};

    /**
     * Wrap memory resource
     */
    UniquePtr(T* new_ptr)
      : raw_ptr_(new_ptr)
      {};

    /**
     * Destroy managed object when leaving scope
     */
    ~UniquePtr();

    UniquePtr(const UniquePtr& other);              // Disallow copy construction
    UniquePtr& operator=(const UniquePtr& other);   // Disallow copy assignment

    /**
     * Release ownership of memory resource as war pointer. 
     *
     * Be careful, it will leak if not deleted manually after release.
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

#include <mycpplib/memory/UniquePtr.inl>

} // namespace mycpplib

#endif  // _MYCPPLIB_UNIQUE_PTR_HPP_
