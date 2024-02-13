#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  int arr[]{1, 2, 3, 6, 7, 8, 9};
  vector<int> Vec{1, 2, 3, 6, 4, 78, 9};

  // for (int &iter : Vec) {
  //  cout << iter << endl;
  //}

  // for(int x : arr)
  //{
  //    cout << x << " " ;
  //}

  auto &&range = Vec;
  auto beg = begin(range);
  auto en = end(range);
  for (; beg != en; beg++) {
    auto v = *beg;
    v = 5;
    cout << v << " ";
  }
  return 0;
}