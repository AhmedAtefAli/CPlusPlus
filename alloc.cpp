#include <iostream>

using namespace std;

int main() {

  int *ptr = static_cast<int *>(calloc(2, sizeof(int)));
  *ptr = 5;
  *(ptr + 1) = 10;
  printf("%d %d\n", *ptr, *(ptr + 1));
  free(ptr);
  return 0;
}
