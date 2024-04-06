#include <initializer_list>
#include <iostream>
#include <vector>

using namespace std;

class Base {
public:
  Base(std::initializer_list<int> data) : m_data(data) {
    cout << "initializr list contructor" << endl;
  }
  Base(int a, int b, int c) { cout << "parameterized contructor " << endl; }

  void print() {
    for (auto &i : m_data) {
      cout << i << ",";
    }
    cout << endl;
  }

private:
  std::initializer_list<int> m_data;
};

class udt
{
  int mValue{};
  public:
  explicit udt(int value)  
  {
      mValue = value;
      std::cout<<" value : "<<mValue<<std::endl;
  }
};


int main() {
  //Base num{1, 2, 3, 6, 8, 9, 7, 12, 11, 20}; // direct list initialization
  //num.print();
  udt d{500};
  return 0;
}