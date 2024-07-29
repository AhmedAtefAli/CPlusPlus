#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>

class Employee {

  std::string mName;
  int mId;
  std::string mProgLang;

public:
  Employee(const std::string &n, int id, const std::string &p)
      : mName(n), mId(id), mProgLang(p) {}

  const std::string &GetName() const { return mName; }

  int GetId() const { return mId; }

  const std::string &GetProLang() const { return mProgLang; }

  bool operator<(const Employee &e) const { return mId < e.mId; }
};

struct EmployeeHash {
  size_t operator()(const Employee &emp) const {
    auto s1 = std::hash<std::string>{}(emp.GetName());
    auto s2 = std::hash<int>{}(emp.GetId());

    return s1 ^ s2;
  }
};

struct EmployeeComp {
  bool operator()(const Employee &e1, const Employee &e2) {
    return e1.GetId() < e2.GetId();
  }
};

struct EmpId {
  std::vector<int> mId;

  void operator()(const Employee &e) {
    if (e.GetProLang() == "C++") {
      mId.push_back(e.GetId());
    }
  }
};

int main() {
  std::vector<Employee> v{Employee{"Ahmaro", 105, "C++"},
                          Employee{"Alaya", 200, "C++"},
                          Employee{"Ahmed", 101, "Java"}};

  auto comp = [](const Employee &e1, const Employee &e2) -> bool {
    return e1.GetId() < e2.GetId();
  };

  std::set<Employee, EmployeeComp> set{Employee{"Ahmaro", 105, "C++"},
                                       Employee{"Alaya", 200, "C"},
                                       Employee{"Ahmed", 101, "Java"}};

  std::sort(v.begin(), v.end(),
            [](const Employee &e1, const Employee &e2) -> bool {
              return e1.GetId() < e2.GetId();
            });

  for (auto &it : v) {
    std::cout << "Id :" << it.GetId() << " | Name:" << it.GetName()
              << std::endl;
  }

  for (auto &it : set) {
    std::cout << "Id :" << it.GetId() << " | Name:" << it.GetName()
              << std::endl;
  }

  auto iter = std::find_if(v.begin(), v.end(), [](const auto &e) {
    return e.GetProLang() == "Java";
  });

  if (iter != v.end()) {
    std::cout << "Found : " << iter->GetName() << " is a Java programmer"
              << std::endl;
  }
  std::cout << "Count : "
            << std::count_if(
                   v.begin(), v.end(),
                   [](const auto &e) { return e.GetProLang() == "C++"; })
            << std::endl;

  std::for_each(v.begin(), v.end(), [](const Employee &e) {
    std::cout << e.GetName() << std::endl;
  });

  auto foundIds = std::for_each(v.begin(), v.end(), EmpId());
  for (auto it : foundIds.mId) {
    std::cout << "id: " << it << std::endl;
  }
  return 0;
}