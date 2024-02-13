#include <array>
#include <iostream>
#include <string>

using namespace std;

class Array {
public:
  Array() {
    data = new int[10];
    for (int i = 0; i < 10; i++) {
      data[i] = i * i;
    }
  }
  ~Array() { delete[] data; }
  Array(const Array &rhs) {
    // copy constructor
    data = new int[10];
    for (int i = 0; i < 10; i++) {
      data[i] = rhs.data[i];
    }
  }

  Array &operator=(const Array &rhs) {
    // copy assignment operator
    if (&rhs == this) {
      // self copy
      return *this;
    }
    // delete the current content of the pointer
    delete[] data;
    // allocate new memory
    data = new int[10];
    for (int i = 0; i < 10; i++) {
      data[i] = rhs.data[i];
    }
    return *this;
  }
  void Print(void) {
    for (int i = 0; i < 10; i++) {
      cout << data[i] << endl;
    }
  }

  void SetData(int index, int value) { data[index] = value; }

private:
  int *data{nullptr};
};

int main() {
  Array num;

  num.SetData(2, 500);
  num.SetData(0, 10000);
  Array num2;
  num2 = num;
  num2.Print();

  return 0;
}