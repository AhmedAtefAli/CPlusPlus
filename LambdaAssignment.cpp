#include <iostream>

using namespace std;

template <typename T> struct FObj_Max {
  T operator()(T x, T y) { return x > y ? x : y; }
};

template <typename T> struct FObj_Greater {
  bool operator()(T x, T y) { return x > y ? true : false; }
};

template <typename T> struct FObj_Less {
  bool operator()(T x, T y) { return x < y ? true : false; }
};

int main() {
  auto Max = [](auto x, auto y) { return x > y ? x : y; };
  auto Greater = [](auto x, auto y) { return x > y ? true : false; };
  auto Less = [](auto x, auto y) { return x > y ? false : true; };

  std::cout << Max(15, 9) << std ::endl;
  std::cout << Greater(9, 15) << std::endl;
  std::cout << Less(9, 15) << std::endl;
  std::cout << FObj_Greater<int>()(15, 9) << std::endl;
  std::cout << FObj_Max<int>()(9, 15) << std ::endl;
  std::cout << FObj_Less<int>()(15, 9) << std::endl;
  return 0;
}