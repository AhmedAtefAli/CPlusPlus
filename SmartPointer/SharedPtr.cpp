#include "Integer.h"
#include <iostream>
#include <memory>

using namespace std;

int main() {

  std::shared_ptr<Integer> ptr{new Integer(5)};

  shared_ptr<Integer> ptr1 = ptr;

  std::cout << " Reference count : " << ptr.use_count() << std::endl;

  ptr1.reset(new Integer(6));
  std::cout << " Reference count ptr1 : " << ptr1.use_count() << std::endl;
  std::cout << " Reference count ptr : " << ptr.use_count() << std::endl;
  return 0;
}