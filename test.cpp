#include <iostream>
#include <memory>

using namespace std;
/// class Base {
/// public:
///  Base() { cout << "Base constructor" << endl; }
///  Base(const Base &&) = delete;
///  Base &operator=(const Base &) = delete;
///  Base &operator=(const Base &&) = delete;
///  virtual ~Base() { cout << "Base destructor" << endl; }
///  virtual void Func() { cout << "Base::Func()" << endl; }
///};
///
/// class Derived : public Base {
/// public:
///  Derived() { cout << "Derived Constructor " << endl; }
///  ~Derived() { cout << "Derived Destructor " << endl; }
///  void Func() { cout << "Derived::Func()" << endl; }
///  void Draw() { cout << "Derived::Draw() " << endl; }
///};

class person {
public:
  static int test;
};

// int person::test = 5;

int main() {

  cout << person::test << endl;
  // char buf[256];
  // cout << " please enter your full name : ";
  // cin.getline(buf, 64, '\n');
  // cout << endl << "your name is : " << buf;
  //// Base *instance = new Derived;
  //// instance->Func();
  //// delete instance;
  return 0;
}