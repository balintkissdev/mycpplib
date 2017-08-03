# My C++ standard library implementation
(work in progress)

## Description
This is my take on recreating STL as a hobby and practice, with API somewhat inspired by Java. The goal is to be able to compile with C++98 compiler and minimize the use of the C++ Standard Library. It currently includes

* A unique pointer
* A dynamic array
* and a barebone unit test framework

Further planned components:

* Singly- and doubly linked list
* Stack
* Iterator
* Trees
* Maps
* String
* Buffers
* Shared pointer and weak reference

## How to install
It's a header-only library (thanks to heavy use of templates). No need to compile a separate lib. Also, it doesn't require dependencies.

## How to test
```bash
make test
```
