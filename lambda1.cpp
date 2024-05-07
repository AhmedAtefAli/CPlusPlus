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

int offset{10};
bool comp(int x, int y) { return x > y; }
bool comp1(int x, int y) { return x < y; }

// function objects
struct comp2 {
  bool operator()(int x, int y) { return x > y; }
};

template <typename T> struct unnamed {
  T operator()(T x, T y) { return x + y; }
};

template <typename T, int size, typename callBack>
void forEach(T (&arr)[size], callBack operation) {
  for (auto &iter : arr) {
    operation(iter);
  }
}

template <typename T> struct _Unnamed {
  T offset{0};
  _Unnamed(T val) : offset(val) {}
  void operator()(T &x) {
    x = x + offset;
    offset++;
  }
};

class Product {
  std::string name;
  float price;

public:
  Product(std::string str, float prc) : name(str), price(prc) {}

  void AssignFinalPrice() {
    float taxes[]{12, 5, 5};
    float basePrice{price};
    forEach(taxes, [basePrice, this](float tax) {
      float taxedPrice = (tax * basePrice) / 100;
      price += taxedPrice;
    });
  }

  float GetPrice() const { return price; }
};
int main() {

  Product p{"watch", 500};
  p.AssignFinalPrice();
  cout << " final price : " << p.GetPrice() << endl;

  // nested lambda expression
  [](int x) {
    [](int x) {
      x *= 2;
      cout << x << endl;
    }(x);
  }(5);

  int arr[]{1, 5, 6, 9, 7, 52, 14, 78, 101};
  forEach(arr, [](auto &x) { cout << x << " "; });
  cout << endl;
  //_Unnamed<int> n(0);
  // forEach(arr, n);
  // int offset = 5;
  forEach(arr, [](auto &x) {
    x += offset;
    offset++;
  });

  forEach(arr, [](auto &x) { cout << x << " "; });
  cout << endl;
  cout << offset << endl;
  return 0;
}

void oldCode() {
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

  // templated lambda expression
  unnamed<int> n;
  cout << " sum using templated lambda is : " << n(5, 6) << endl;

  // generic lambda Expression
  auto plus = [](auto x, auto y) { return x + y; };
  cout << "sum using generic lambda : " << plus(4, 6) << endl;
}