#include <test/Assert.hpp>
#include <container/LinkedList.hpp>

using namespace jlstl::Assert;

void testInsert()
{
  jlstl::LinkedList<int> list;

  // Initial insert
  list.add(40);
  assertEquals(40, list[0]);
}

void testClear()
{
  jlstl::LinkedList<int> list;

  // Initial insert
  list.add(40);
  assertEquals(40, list[0]);

  // Clear
  list.clear();
  assertEquals(0, list.size());
}

void testMultipleInsert()
{
  jlstl::LinkedList<int> list;
  int samples[] = {87, 12, 33, 65, 77};

  for (int i = 0; i < (sizeof(samples) / sizeof(samples[0])); ++i)
  {
    list.add(samples[i]);
  }

  for (int i = 0; i < (sizeof(samples) / sizeof(samples[0])); ++i)
  {
    assertEquals(samples[i], list[i]);
  }
}

int main()
{
  testInsert();
  testClear();
  testMultipleInsert();

  return 0;
}
