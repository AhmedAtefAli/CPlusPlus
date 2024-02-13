#include <iostream>

using std::cout, std::endl;

inline int Add(int x = 9, int y = 5, int z = 10);

int &transform(int &x) {
  x *= x;
  return x;
}

int main(void) {

  int &&
  return 0;
}

inline int Add(int x, int y, int z) { return x + y + z; }