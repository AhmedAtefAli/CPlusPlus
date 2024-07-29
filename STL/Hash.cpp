#include <iostream>
#include <string>
#include <unordered_set>

class Employee {

  std::string mName;
  int mId;

public:
  Employee(const std::string &n, int id) : mName(n), mId(id) {}

  const std::string &GetName() const { return mName; }

  int GetId() const { return mId; }
};

struct EmployeeHash {
  size_t operator()(const Employee &emp) const {
    auto s1 = std::hash<std::string>{}(emp.GetName());
    auto s2 = std::hash<int>{}(emp.GetId());

    return s1 ^ s2;
  }
};

struct EmpEquality {
  bool operator()(const Employee &e1, const Employee &e2) const {
    return (e1.GetId() == e2.GetId()) && (e1.GetName() == e2.GetName());
  }
};

int main() {
  std::hash<std::string> h;
  std::cout << h("Ahmed") << std::endl;
  std::unordered_set<Employee, EmployeeHash, EmpEquality> set{};

  set.insert(Employee("Ahmed", 55));
  set.insert(Employee("Alaya", 42));
  set.insert(Employee("Ahmaro", 75));

  for (const auto &it : set) {
    std::cout << it.GetId() << ":" << it.GetName() << std::endl;
  }

  return 0;
}