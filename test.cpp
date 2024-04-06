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

struct add {
  add()
  {
    ++count;
  }
  ~add() 
  {
    --count;
  }
  add(int value) : num(value) {++count;}
  int getNum() {
    cout << "add::getNum()" << endl;
    count++;
    return num;
  }

  void setNum(int num) {
    cout << "add::setNum(int num)" << endl;
    this->num = num;
        count++;
  }
   void showCount() const
  {
    cout << "Number of objects are : "<< count << endl;
  }
  int num{0};
  static int count;
};

int add::count{0};
int main() {

  // cout << person::test << endl;
  // char buf[256];
  // cout << " please enter your full name : ";
  // cin.getline(buf, 64, '\n');
  // cout << endl << "your name is : " << buf;
  //// Base *instance = new Derived;
  //// instance->Func();
  //// delete instance;
  add obj(0);
  const add obj1(5);
  obj.setNum(5);
  obj1.showCount();
  return 0;
}