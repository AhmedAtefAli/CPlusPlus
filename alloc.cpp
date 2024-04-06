#include <iostream>
#include <stdlib.h>

using namespace std;

void Malloc() {

  int *ptr = static_cast<int *>(calloc(2, sizeof(int)));
  int *p = (int *)malloc(1 * sizeof(int));
  *ptr = 5;
  *(ptr + 1) = 10;
  printf("%d %d\n", *ptr, *(ptr + 1));
  free(ptr);
  free(p);
}

void New() {
  int *p = new int(9);
  cout << *p << endl;
  *p = 5;
  cout << *p << endl;
  delete p;
  p = nullptr;
  delete p;
}

void NewArray() {
  int *ptr = new int[5];

  for (int i = 0; i < 5; i++) {
    ptr[i] = i;
  }
  delete[] ptr;
}

void TwoDArray() {
  int *p1 = new int[5];
  int *p2 = new int[5];

  // using array of pointers
  int **pData = new int *[2];
  pData[0] = p1;
  pData[1] = p2;

  delete[] p1;
  delete[] p2;
  delete[] pData;
}

int main() {

  // int *ptr{::new int(5)};
  // cout << *ptr << endl;
  NewArray();
  TwoDArray();
  return 0;
}
