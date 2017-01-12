#include <test/Assert.hpp>
#include <memory/UniquePtr.hpp>
#include <container/ArrayList.hpp>

using namespace jlstl::Assert;

void testArrayList()
{
  jlstl::ArrayList<int> list(5);
  assertEquals(0, list.size());
  list.add(35);
  assertEquals(35, list[0]);
  assertEquals(1, list.size());
  assertEquals(5, list.capacity());
  for (int i = 1; i <= 4; ++i)
  {
    list.add(7);
  }
  assertEquals(5, list.size());
  assertEquals(5, list.capacity());
  list.add(1);
  assertEquals(6, list.size());
  assertEquals(1005, list.capacity());

  list.clear();
  assertEquals(0, list.size());

  jlstl::UniquePtr< jlstl::List<int> > array_list(new jlstl::ArrayList<int>());
  // UniquePtr< List<int> > array_list = makeUnique<ArrayList <int> >();  // FIXME: doesn't support polymorphism yet
  array_list->add(2);
  array_list->add(34);

  assertEquals(2, array_list->get(0));
  assertEquals(34, array_list->get(1));
  assertEquals(2, array_list->size());
}

int main()
{
  testArrayList();

  return 0;
}
