#include <iostream>
#include <memory>

class printer {
  std::weak_ptr<int> mPtr{};

public:
  void SetValue(std::shared_ptr<int> ptr) { mPtr = ptr; }

  void Print() {
    if (mPtr.expired()) {
      std::cout << "object is expired " << std::endl;
      return;
    }
    auto sp = mPtr.lock();
    std::cout << " value is : " << *sp << std::endl;
  }
};
int main() {
  printer prn;

  int num{};

  std::cin >> num;

  std::shared_ptr<int> p{new int(num)};

  prn.SetValue(p);

  if (*p > 10) {
    p = nullptr;
  }

  prn.Print();

  return 0;
}