#include <iostream>
#include <string>
#include "Integer.h"


class Employee
{
    std::string mName;
    Integer mId;
    public:

    template<typename T1,typename T2>
    Employee(T1 &&name, T2 &&id) : mName{std::forward<T1>(name)},mId{std::forward<T2>(id)}
    {
        std::cout << "Employee(std::string &&name, Integer&&id)"<< std::endl;
    }

};


int main()
{
    //Employee emp1{"Umar", Integer{100}};
    //Integer val{100};
    //Employee emp2{std::string{"Umar"}, val};
    Employee emp3{"Umar", 100};
    return 0;
}
