#include <iostream>

using namespace std;

class Integer {
public:
  int data;

  Integer() : data(0) { cout << "Integer()" << endl; }
  Integer(int val) : data(val) { cout << "Integer(int val)" << endl; }
  Integer(const Integer &ref) {
    cout << "Integer(const Integer &ref)" << endl;
    data = ref.data;
  }
  Integer &operator=(const Integer &rhs) {
    cout << "Integer operator=(const Integer &rhs)" << endl;

    data = rhs.data;

    return *this;
  }
};

class Vector {
public:
  float x, y, z;
  Integer v;

  Vector() : x(1.0f), y(2.0f), z(x) { v = 5; }
};

std::ostream &operator<<(ostream &out, const Vector &ref) {
  out << ref.x << " , " << ref.y << " , " << ref.z << endl;
  return out;
}

int main() {
  Vector v1;

  cout << v1;
  return 0;
}