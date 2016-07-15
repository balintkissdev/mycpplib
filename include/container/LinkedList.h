#ifndef BKSTL_LINKED_LIST_H
#define BKSTL_LINKED_LIST_H

#include <exception>

#include "List.h"

namespace bkstl
{
    template <typename T>
    struct SingleNode
    {
        T value_;
        SingleNode* next_node_;
        SingleNode(T value, SingleNode* next) : value_(value), next_node_(next) {};
    };

    template <typename T>
    class LinkedList : public List<T>
    {
        public:
            LinkedList() : size_(0), head_node_(0) {};
            ~LinkedList();
            bool add(const T element);
            void clear();
            // TODO: bool contains(const T& element);
            T get(int index);
            T operator[](int index);
            bool isEmpty();
            // TODO: Iterator<T> iterator();
            // TODO: T remove(int index);
            std::size_t size();

        private:
            std::size_t size_;
            SingleNode<T>* head_node_;

            /**
             * Traverse until the end of list
             */
            SingleNode<T>* traverse();

            /**
             * Traverse until specified index
             */
            SingleNode<T>* traverse(const int index);
    };

    template <typename T>
    inline LinkedList<T>::~LinkedList()
    {
        clear();
    }

    // FIXME: can't add more than two elements
    template <typename T>
    inline bool LinkedList<T>::add(const T element)
    {
        if (!head_node_)
        {
            head_node_ = new SingleNode<T>(element, 0);
        }
        else
        {
            traverse()->next_node_ = new SingleNode<T>(element, 0);
        }
        ++size_;

        return true;
    }

    template <typename T>
    inline void LinkedList<T>::clear()
    {
        // Start from beginning and delete everything from there
        SingleNode<T>* current = head_node_;
        SingleNode<T>* tmp = 0;
        while (current)
        {
            tmp = current;
            current = tmp->next_node_;
            delete tmp;
        }
        size_ = 0;
    }

    template <typename T>
    inline T LinkedList<T>::get(const int index)
    {
        if (-1 < index && index < size_)
        {
            return traverse(index)->value_;
        }
        throw std::exception();
    }

    template <typename T>
    inline T LinkedList<T>::operator[](const int index)
    {
        return get(index);
    }
     
    template <typename T>
    inline bool LinkedList<T>::isEmpty()
    {
        return size_ < 1;
    }

    template <typename T>
    inline std::size_t LinkedList<T>::size()
    {
        return size_;
    }

    template <typename T>
    SingleNode<T>* LinkedList<T>::traverse()
    {
        SingleNode<T>* current = head_node_;
        while (current->next_node_)
        {
            current = current->next_node_;
        }
        return current;
    }

    // FIXME: bugged
    template <typename T>
    SingleNode<T>* LinkedList<T>::traverse(const int index)
    {
        SingleNode<T>* current = head_node_;
        for (int i = 0; i < index + 1; ++i)
        {
            current = head_node_->next_node_;
        }
        return current;
    }
} // namespace bkstl

#endif  // BKSTL_LINKED_LIST_H
