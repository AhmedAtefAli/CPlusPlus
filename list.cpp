#include <iostream>
#include <list>

using namespace std;

int main() {
  list<int> l{4, 47, 8779, 78, 56, 2, 32, 9};
  list<int> lst{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  l.push_front(0);
  l.push_back(9);

  for (auto &i : l) {
    cout << i << ",";
  }
  cout << endl;

  // l.insert(l.end(), lst.begin(), lst.end());;
  for (auto &i : l) {
    cout << i << ",";
  }
  cout << endl;
  l.reverse();
  for (auto &i : l) {
    cout << i << ",";
  }
  cout << endl;
  return 0;
}