#ifndef UNIQUE_PTR_H
#define UNIQUE_PTR_H

#if __cplusplus >= 201103L
#include <memory>
#endif

// FIXME: Not right, can't use custom deleter
template <typename T>
struct UniqueDeleter
{
    void operator()(T* raw) { delete raw; }
};

template <typename T, typename D = UniqueDeleter<T> >
class UniquePtr
{
    public:
        UniquePtr() : raw_ptr_(0) {};
        UniquePtr(T* new_ptr) : raw_ptr_(new_ptr) {};

        UniquePtr(T* new_ptr, D deleter) 
            : raw_ptr_(new_ptr)
            , deleter_(deleter)
            {};
        
        ~UniquePtr();
        UniquePtr(const UniquePtr& other);              // Disallow copy constructor
        UniquePtr& operator=(const UniquePtr& other);   // Disallow copy assignment

        #if __cplusplus >= 201103L
        UniquePtr(UniquePtr&& other) : raw_ptr_(std::move(other.get())) {}
        UniquePtr& operator=(UniquePtr&& other) = default;  // TODO
        #endif

        void release();
        
        void reset();

        void reset(T* new_ptr);

        T* get();
        T& operator*();
        T* operator->();

        // TODO: safe bool idiom
        // http://www.artima.com/cppsource/safebool.html
        operator bool() const;
        
    private:
        T* raw_ptr_;
        D deleter_;
};

#if __cplusplus >= 201103L
template <typename T, typename... V>
UniquePtr<T>& makeUnique(V... vars)
{
    return UniquePtr<T>(new T(vars...));
}
#endif

#endif
