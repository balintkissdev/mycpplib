#include <mycpplib/test/Assert.hpp>
#include <mycpplib/container/LinkedList.hpp>

using namespace mycpplib::Assert;

void testInsert()
{
  mycpplib::LinkedList<int> list;

  // Initial insert
  list.add(40);
  assertEquals(40, list[0]);
}

void testClear()
{
  mycpplib::LinkedList<int> list;

  // Initial insert
  list.add(40);
  assertEquals(40, list[0]);

  // Clear
  list.clear();
  assertEquals(0, list.size());
}

void testMultipleInsert()
{
  mycpplib::LinkedList<int> list;
  int samples[] = {87, 12, 33, 65, 77};

  for (size_t i = 0; i < (sizeof(samples) / sizeof(samples[0])); ++i)
  {
    list.add(samples[i]);
  }

  for (size_t i = 0; i < (sizeof(samples) / sizeof(samples[0])); ++i)
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
