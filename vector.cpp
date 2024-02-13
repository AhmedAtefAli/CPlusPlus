#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  // vector<int> vec(50, 30);
  vector<int> vec{10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  vector<vector<int>> Vec1{};

  Vec1.push_back(vec);
  return 0;
}