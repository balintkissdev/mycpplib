#include <iostream>
#include <string>

#include <io/System.h>
#include <test/Assert.h>
#include <memory/UniquePtr.h>
#include <container/ArrayList.h>
#include <container/LinkedList.h>

using namespace bkstl::Assert;

void testUniquePtr()
{
    // Base unique pointer facilities
    bkstl::UniquePtr<int> int_ptr;
    if (!int_ptr)
    {
        int_ptr.reset(new int(100));
    }
    assertEquals(100, *int_ptr);

    // Check for no storage overhead    FIXME: UniquePtr has storage overhead
    //int* raw_intptr = new int(100);
    //bkstl::UniquePtr<int> int_ptr2(new int(100));
    //assertEquals(sizeof(raw_intptr), sizeof(int_ptr2), "UniquePtr has storage overhead");
    //delete raw_intptr;
}

void testArrayList()
{
    bkstl::ArrayList<int> list;
    list.add(35);
    assertEquals(35, list[0]);
    assertEquals(1000, list.capacity());

    bkstl::UniquePtr< bkstl::List<int> > array_list(new bkstl::ArrayList<int>());
    // UniquePtr< List<int> > array_list = makeUnique<ArrayList <int> >();  // FIXME: doesn't support polymorphism yet
    array_list->add(2);
    array_list->add(34);

    assertEquals(2, array_list->get(0));
    assertEquals(34, array_list->get(1));
    assertEquals(2, array_list->size());
}

void testLinkedList()
{
    bkstl::LinkedList<int> list;

    // Initial insert
    list.add(40);
    assertEquals(40, list[0]);

    // Continous insert
    list.add(12);
    assertEquals(40, list[0]);
    assertEquals(12, list[1]);
    //list.add(33);                 // FIXME
    //assertEquals(33, list[2]);
}

void testSystemOut()
{
    using namespace bkstl;

    // const char*
    System::out::print("Test char* cout.\n");
    System::out::println("Test char* cout.");
    System::err::print("Test char* cerr.\n");
    System::err::println("Test char* cerr.");

    // const std::string&
    System::out::print(std::string("Test std::string cout.\n"));
    System::out::println(std::string("Test std::string cout."));
    System::err::print(std::string("Test std::string cerr.\n"));
    System::err::println(std::string("Test std::string cerr."));
}

int main()
{
    testSystemOut();
    testUniquePtr();
    //testArrayList();  // FIXME: fails
    testLinkedList();

    return 0;
}
