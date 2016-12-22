# JLSTL: My STL implementation ("Java-like STL")
(work in progress)

## Description
This is my take on recreating STL, with API somewhat inspired by Java API. The goal is to be able to compile with C++98 compiler and minimize the use of the C++ Standard Library. It's just a hobby for me. It currently includes
* A unique pointer (UniquePtr.h)
* A dynamic array (ArrayList.h)
* and a barebone unit test framework (Assert.h)

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
