#include <string>

#include <io/System.hpp>
#include <test/Assert.hpp>
#include <memory/UniquePtr.hpp>

using namespace jlstl::Assert;

template <typename T>
struct MyDeleter
{
  void operator()(T* raw)
  {
    jlstl::System::out::println("Trying out custom deleter object.");
    delete raw;
  }
};

template <typename T>
void deleterFunction(T* raw)
{
  jlstl::System::out::println("Trying out custom deleter function.");
  delete raw;
}

void testBaseFacilities()
{
  jlstl::UniquePtr<int> int_ptr;
  if (!int_ptr)
  {
    int_ptr.reset(new int(100));
  }
  assertEquals(100, *int_ptr);
}

void testStorageOverhead()
{
  int* raw_intptr = new int(100);
  jlstl::UniquePtr<int> int_ptr(new int(100));

  assertEquals(sizeof(raw_intptr), sizeof(int_ptr), "UniquePtr has size overhead");
  delete raw_intptr;
}

void testCustomDeleter()
{
  // Deleter object
  jlstl::UniquePtr<int, MyDeleter<int> > ptr_with_deleter(new int(55));
  assertEquals(55, *ptr_with_deleter);

  // Deleter function
  jlstl::UniquePtr<std::string, void(*)(std::string*) > strptr_with_deleter(new std::string("word"), deleterFunction<std::string>);
  assertEquals("word", *strptr_with_deleter);
}

int main()
{
  testBaseFacilities();
  testStorageOverhead();
  testCustomDeleter();

  return 0;
}
