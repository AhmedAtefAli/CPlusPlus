#include <iostream>
#include <memory>

using namespace std;

class A {
public:
  int x{5}, y{9};
};

class B : virtual public A {
public:
  int power{20};
};

class C : virtual public A {
public:
  int num{88};
};

class D : public B, public C {
public:
};

int main() {
  D temp;

  cout << temp.x << endl;
  cout << temp.y << endl;
  temp.B::x = 0;
  temp.C::y = 6;
  cout << temp.x << endl;
  cout << temp.y << endl;
  cout << temp.power << endl;
  // cout << temp.B::y << endl;
  return 0;
}