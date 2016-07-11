#include <iostream>

#include <test/Assert.h>
#include <memory/UniquePtr.h>
#include <container/ArrayList.h>

using bkstl::Assert;

void testUniquePtr()
{
    bkstl::UniquePtr<int> int_ptr;
    if (!int_ptr)
    {
        int_ptr.reset(new int(100));
    }
    Assert::assertEquals(*(int_ptr.get()), 100);
}

void testArrayList()
{
    bkstl::ArrayList<int> list;
    list.add(35);
    Assert::assertEquals(list[0], 35);
    Assert::assertEquals(list.capacity(), 1000);

    //bkstl::List<int>* array_list = new bkstl::ArrayList<int>();
    bkstl::UniquePtr< bkstl::List<int> > array_list(new bkstl::ArrayList<int>());
    // UniquePtr< List<int> > array_list = makeUnique<ArrayList <int> >();  // FIXME: doesn't support polymorphism yet
    array_list->add(2);
    array_list->add(34);

    Assert::assertEquals(array_list->get(0), 2);
    Assert::assertEquals(array_list->get(1), 34);
    Assert::assertEquals(array_list->size(), 2);

    //delete array_list;
}

int main()
{
    testArrayList();
    testUniquePtr();

    return 0;
}
