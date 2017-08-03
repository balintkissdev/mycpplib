#include <cstddef>
#include <string>

#include <mycpplib/io/System.hpp>
#include <mycpplib/test/Assert.hpp>
#include <mycpplib/memory/UniquePtr.hpp>

using namespace mycpplib::Assert;

template <typename T>
struct MyDeleter
{
  void operator()(T* raw)
  {
    mycpplib::System::out::println("Trying out custom deleter object.");
    delete raw;
  }
};

template <typename T>
void deleterFunction(T* raw)
{
  mycpplib::System::out::println("Trying out custom deleter function.");
  delete raw;
}

void testRelease()
{
  mycpplib::UniquePtr<int> ptr(new int(100));

  int* raw_ptr = ptr.release();
  assertEquals(static_cast<int*>(NULL), ptr.get()); // FIXME
  assertEquals(100, *raw_ptr);

  delete raw_ptr;
}

void testReset()
{
  mycpplib::UniquePtr<int> ptr;
  if (!ptr)
  {
    ptr.reset(new int(100));
  }
  assertEquals(100, *ptr);
}

void testGet()
{
  mycpplib::UniquePtr<int> ptr(new int(200));
  int* raw_ptr = ptr.get();
  assertEquals(200, *raw_ptr);
}

void testDereference()
{
  mycpplib::UniquePtr<int> ptr(new int(300));
  assertEquals(300, *ptr);
}

void testStorageOverhead()
{
  int* raw_ptr = new int(100);
  mycpplib::UniquePtr<int> ptr(new int(100));

  assertEquals(sizeof(raw_ptr), sizeof(ptr), "UniquePtr has size overhead");
  delete raw_ptr;
}

void testCustomDeleter()
{
  // Deleter object
  mycpplib::UniquePtr<int, MyDeleter<int> > ptr_with_deleter(new int(55));
  assertEquals(55, *ptr_with_deleter);

  // Deleter function
  mycpplib::UniquePtr<std::string, void(*)(std::string*) > strptr_with_deleter(new std::string("word"), deleterFunction<std::string>);
  assertEquals("word", *strptr_with_deleter);
}

int main()
{
  testRelease();
  testReset();
  testGet();
  testDereference();
  testStorageOverhead();
  testCustomDeleter();

  return 0;
}
