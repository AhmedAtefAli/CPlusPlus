#include <fstream>
#include <iostream>

int main() {

  int y = 9;
  auto fn = [y = y](int x) mutable {
    y = 100;
    return y + x;
  };
  std::cout << fn(5) << std::endl;
  std::cout << y << std::endl;

  std::ofstream outfile{"file.txt"};
  auto write = [out = std::move(outfile)](int x) mutable { out << x; };
  write(500);
  write(154);
  return 0;
}