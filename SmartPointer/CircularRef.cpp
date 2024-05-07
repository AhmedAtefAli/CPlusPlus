#include <iostream>
#include <memory>

class Employee;

class Project {
public:
  std::shared_ptr<Employee> mEmp;

  Project() { std::cout << "Project() " << std::endl; }
  ~Project() { std::cout << "~Project" << std::endl; }
};

class Employee {
public:
  // std::shared_ptr<Project> mPrj;
  std::weak_ptr<Project> mPrj;
  Employee() { std::cout << "Employee()" << std::endl; }
  ~Employee() { std::cout << "~Employee()" << std::endl; }
};

int main() {

  std::shared_ptr<Employee> emp{new Employee};
  std::shared_ptr<Project> prj{new Project};

  // Employee *emp = new Employee;
  // Project *prj = new Project;

  emp->mPrj = prj;
  prj->mEmp = emp;

  // delete emp;
  // delete prj;
  return 0;
}