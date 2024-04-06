#include <iostream>

using namespace std;

// using comparator = bool (*)(int, int);

template <typename T, int size, typename comparator>
void sort(T (&arr)[size], comparator comp) {
  for (int i = 0; i < size - 1; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (comp(arr[j], arr[j + 1])) {
        T temp = arr[j + 1];
        arr[j + 1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

bool comp(int x, int y) { return x > y; }
bool comp1(int x, int y) { return x < y; }

// function objects
struct comp2 {
  bool operator()(int x, int y) { return x > y; }
};

int main() {
  comp2 comp;
  int arr[]{5, 4, 6, 98, 71, 22, 36, 43};
  for (auto &it : arr) {
    cout << it << ",";
  }
  cout << endl;

  sort(arr, comp);

  for (auto &it : arr) {
    cout << it << ",";
  }
  cout << endl;

  []() {
    std::cout << " welcome to unnamed lambda expressions " << endl;
  }(); // unnamed lambda expression

  // named lambda expressions
  auto fn = []() {
    std::cout << " welcome to named lambda expressions " << endl;
  };
  fn();
  cout << " address of the lambda expression is : " << &fn << endl;
  cout << typeid(fn).name() << endl;

  auto sum = [](int x, int y) -> double { return x + y; };
  cout << "Sum is : " << sum(5, 7) << endl;
  return 0;
}