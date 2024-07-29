#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

void UnSet() {
  std::unordered_set<std::string> con;

  con.insert("Hulk");
  con.insert("Batman");
  con.insert("Green Lantern");
  con.insert("The Flash");
  con.insert("DR. Strange");

  for (const auto x : con) {
    std::cout << " Bucket #: " << con.bucket(x) << " contains " << x
              << std::endl;
  }

  std::cout << "Bucket count : " << con.bucket_count() << std::endl;
  std::cout << "Number of elements : " << con.size() << std::endl;
  std::cout << "Load factor : " << con.load_factor() << std::endl;
}

void UnMap() {
  std::unordered_map<std::string, std::string> con;

  con["Batman"] = "Bruce wayne";
  con["SuperMan"] = "Clark Kent";
  con["Hulk"] = "Bruce Banner ";

  for (const auto &it : con) {
    std::cout << it.first << ":" << it.second << std::endl;
  }
}

int main() {
  // UnSet();
  // UnMap();

  return 0;
}