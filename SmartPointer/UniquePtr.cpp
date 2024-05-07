#include "Integer.h"
#include <iostream>
#include <memory>

void Display(Integer *p) {
  if (!p) {
    return;
  }
  std::cout << p->GetValue() << std::endl;
}

Integer *GetPointer(int value) {
  Integer *p = new Integer(value);
  return p;
}

void Store(std::unique_ptr<Integer> &p) {
  std::cout << "Storing the value to a file : " << p->GetValue() << std::endl;
}

void oldOperate(int value) {
  Integer *p = GetPointer(value);

  if (p == nullptr) {
    p = new Integer{value};
  }

  p->SetValue(100);
  Display(p);
  delete p;
  p = nullptr;
  p = new Integer{};

  *p = __LINE__;
  Display(p);
  delete p;
}

void Operate(int value) {

  /* this will not work as the unique pointer has explicit constructor so it
  will prevent the compiler from performing type conversion with the bare object
  so the only way to initialize it is either using parameterized constructor of
  uniquePtr or use the Move constructor through the usage of make_unique
  function or explicit move constructable expression:

  std::unique_ptr<Integer> P = GetPointer(5); */

  std::unique_ptr<Integer> p{GetPointer(value)};

  /* unique pointer has overload for the assignment operator for nullptr value
   * so assign nullptr value to unique pointer will call reset function that
   * will release the resource and assign nullptr value to the underlying
   * pointer*/

  /* also the unique pointer has operator overloads for logical == and != and
   * also bool logical expression so that we can compare the unique pointer
   * either against another one or against nullptr*/
  if (!p) {
    // reallocate the object for the unique pointer
    p.reset(new Integer(value));
  }

  p->SetValue(100);
  Display(
      p.get()); // return the underlying pointer of the unique pointer object
  // p = nullptr;
  p.reset(new Integer{});
  *p = __LINE__;
  Display(p.get());
  Store(p);
}
int main() {
  Operate(5);
  return 0;
}