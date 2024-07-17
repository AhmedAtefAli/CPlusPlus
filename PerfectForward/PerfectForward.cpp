#include <iostream>
#include <string>
#include "Integer.h"

class Employee
{
    std::string mName{};
    Integer mId;
    public:
    //Employee(const std::string& name, const Integer& id) : mName{name}, mId{id}
    //{
    //    std::cout << "Employee(const std::string& name, const Integer& id)"<< std::endl;
    //}
//
    //Employee(std::string && name, Integer&& id) : mName(name),mId(id)
    //{
    //    std::cout << "Employee(std::string && name, Integer&& id)"<< std::endl;
    //}
template<typename T1, typename T2>
    Employee(T1&& name, T2&& id) : mName(name),mId(id)
    {
        std::cout << "Employee(std::string && name, Integer&& id)"<< std::endl;
    }

};

int main()
{
    Employee emp{"Ahmed", 500};
    return 0;
}