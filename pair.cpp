#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
  std::pair<string, int> p1{};
  std::pair<string, int> p2{};

  vector<std::pair<string, int>> Vec{};
  p1.first = "Ahmed";
  p1.second = 28;
  p2.first = "Atef";
  p2.second = 76;

  Vec.push_back(p1);
  Vec.push_back(p2);

  cout << Vec.front().first << Vec.front().second << endl;
  cout << Vec.back().first << Vec.back().second << endl;
  return 0;
}
