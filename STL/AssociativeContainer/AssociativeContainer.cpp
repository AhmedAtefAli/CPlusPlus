#include <functional>
#include <iostream>
#include <map>
#include <set>
#include <string>

void Set() {
  std::set<int> s{8, 2, 0, 9, 5};

  // sort in descending order
  std::multiset<int, std::greater<int>> set{4,  45, 3, 3, 3, 3, 3,
                                            97, 7,  6, 3, 2, 1};

  s.insert(1);
  s.insert(10);

  // access elements of the set
  auto iter = s.begin();
  auto i = set.begin();

  while (iter != s.end()) {
    std::cout << *iter++ << " ";
  }

  std::cout << std::endl;
  while (i != set.end()) {
    std::cout << *i++ << " ";
  }

  // erase based on value
  s.erase(2);
  // erase based on pos
  s.erase(s.begin());

  // search for Element
  auto it = s.find(9);
  if (it != s.end()) {
    std::cout << std::endl << "Element Found" << std::endl;
  } else {
    std::cout << std::endl << "Element Not Found" << std::endl;
  }

  // search a mulitset
  /* equal_range function will return std::pair object
  the first element is the iterator for the first occurance of the element
  the second element of pair is the iterator of the first greater element after
  the key or searched element  */

  auto pair = set.equal_range(3);

  while (pair.first != pair.second) {
    std::cout << *pair.first++ << " ";
  }
}

void Map() {
  std::map<int, std::string> m{
      {1, "SuperMan"},
      {2, "BatMan"},
      {3, "SpiderMan"},
  };

  // insert objects inside map
  m.insert(std::pair<int, std::string>{5, "Flash"});

  m.insert(std::make_pair(6, "AquaMan"));

  m[8] = "WonderWoman";

  // access elements
  auto iter = m.begin();

  while (iter != m.end()) {
    std::cout << iter->first << ":" << iter->second << std::endl;
    iter++;
  }
}

int main() {
  // Set();
  Map();
  return 0;
}