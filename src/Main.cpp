#include <iostream>
#include <cassert>
#include <vector>
#include <exception>

#include "UniquePtr.h"
#include "ArrayList.h"

template <typename T, typename E>
void assertEquals(T x, E y)
{
    x == y ? : std::cerr << "Wrong: " << x << " =/= " << y << '\n';
}

void testValues()
{
    ArrayList<int> list;
    list.add(35);
    assertEquals(list[0], 35);

    List<int>* array_list = new ArrayList<int>();
    //UniquePtr< List<int> > array_list(new ArrayList<int>());
    // UniquePtr< List<int> > array_list = makeUnique<ArrayList <int> >();  // FIXME: doesn't support polymorphism
    array_list->add(2);
    array_list->add(34);

    assertEquals(array_list->get(0), 2);
    assertEquals(array_list->get(1), 34);
    assertEquals(array_list->size(), 2);
    assertEquals(array_list->capacity(), 1000);

    delete array_list;
}

void testPointers()
{
    /*UniquePtr< List<int*> > ptr_list(new ArrayList<int*>());
    int* ptr = new int(30);
    ptr_list->add(ptr);
    assertEquals(*(ptr_list->get(0)), 30);
    delete ptr;

    typedef UniquePtr<int> intPtr;*/
    //UniquePtr< List <intPtr > > smart_list(new ArrayList<intPtr>());
    //intPtr ptr0(new int(54));
    //smart_list.get()->add(ptr0);
}

void testUniquePtr()
{
    /*UniquePtr<int> int_ptr;
    if (!int_ptr)
    {
        int_ptr.reset(new int(100));
    }
    assertEquals(*(int_ptr.get()), 100);*/

    // Custom deleter
    //struct MyDeleter
    //{

}

int main()
{
    testValues();

    return 0;
}
