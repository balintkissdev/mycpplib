#ifndef BKSTL_UNIQUE_PTR_H
#define BKSTL_UNIQUE_PTR_H

#if __cplusplus >= 201103L
#include <utility>      // Needed for move semantics if C++0x support is enabled
#endif

namespace bkstl
{
    // FIXME: Can't create new custom deleter yet
    // FIXME: standard deleter creates storage overhead
    /**
     * Default unique pointer deleter
     */
    /*template <typename T>
    struct UniqueDeleter
    {
        void operator()(T* raw) { delete raw; }
    };*/

    template <typename T>
    struct UniqueDeleter
    {
    };

    /**
     * Unique pointer for managing lifecycle of objects on the heap.
     */
    template <typename T, typename D = UniqueDeleter<T> >
    class UniquePtr
    {
        public:
            /**
             * Default constructor to initialize to null
             */
            UniquePtr() : raw_ptr_(0) {};

            /**
             * Wrap memory resource
             */
            UniquePtr(T* new_ptr) : raw_ptr_(new_ptr) {};

            /**
             * Wrap memory resource with custom deleter
             */
            /*UniquePtr(T* new_ptr, D deleter) 
                : raw_ptr_(new_ptr)
                , deleter_(deleter)
                {};*/
            
            /**
             * Destroy managed object when leaving scope
             */
            ~UniquePtr();

            UniquePtr(const UniquePtr& other);              // Disallow copy construction
            UniquePtr& operator=(const UniquePtr& other);   // Disallow copy assignment

            #if __cplusplus >= 201103L
            // FIXME: move semantics if C++0x
            UniquePtr(UniquePtr&& other) : raw_ptr_(std::move(other.get())) {}
            UniquePtr& operator=(UniquePtr&& other);
            #endif

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
            //D* deleter_;
    };

    #if __cplusplus >= 201103L
    // FIXME
    template <typename T, typename... V>
    UniquePtr<T>& makeUnique(V... vars)
    {
        return UniquePtr<T>(new T(vars...));
    }
    #endif

    template <typename T, typename D >
    inline UniquePtr<T, D>::~UniquePtr()
    {
        delete raw_ptr_;
        //deleter_(raw_ptr_);
    }

    template <typename T, typename D >
    inline T* UniquePtr<T, D>::release()
    {
        T* tmp = raw_ptr_;
        raw_ptr_ = 0;
        return tmp;
    }

    template <typename T, typename D >
    inline void UniquePtr<T, D>::reset(T* new_ptr)
    {
        reset();
        raw_ptr_ = new_ptr;
    }

    template <typename T, typename D >
    inline void UniquePtr<T, D>::reset()
    {
        //deleter_(raw_ptr_);
        delete raw_ptr_;
        raw_ptr_ = 0;
    }

    template <typename T, typename D >
    inline T* UniquePtr<T, D>::get()
    {
        return raw_ptr_;
    }

    template <typename T, typename D >
    inline T& UniquePtr<T, D>::operator*()
    {
        return *raw_ptr_;
    }

    template <typename T, typename D >
    inline T* UniquePtr<T, D>::operator->()
    {
        return raw_ptr_;
    }

    template <typename T, typename D >
    inline UniquePtr<T, D>::operator bool() const 
    {
        return raw_ptr_;
    }
} // namespace bkstl

#endif  // BKSTL_UNIQUE_PTR_H
