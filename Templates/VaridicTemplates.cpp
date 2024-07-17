#include "Integer.h"
#include "Templates.hpp"
#include <algorithm>
#include <iostream>
#include <memory>

void Print() { std::cout << std::endl; }
template <typename T, typename... Params> void Print(T &&a, Params &&... args) {
  std::cout << a;
  if (sizeof...(args) != 0) {
    std::cout << " , ";
  }

  Print(args...);
}

void print() { std::cout << std::endl; }
// template parameter pack
template <typename T, typename... params>
// function parameter pack or argument pack
void print(T a, params... args) {
  std::cout << a;
  if (sizeof...(args) != 0) {
    std::cout << " , ";
  }
  print(args...);
}

int main() {
  // print(1, 2.5, 3, "A");
  Integer Val{100};
  Print(0, Integer{2}, Val);
  return 0;
}