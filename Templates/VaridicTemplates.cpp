#include <iostream>
#include <memory>
#include "Templates.hpp"
#include <algorithm>

void print()
{
    std::cout << std::endl;
}
// template parameter pack
template<typename T,typename... params>
// function parameter pack or argument pack
void print(T a, params... args)
{
    std::cout<<a;
    if(sizeof...(args) != 0)
    {
        std::cout << " , ";
    }
    print(args...);
}

int main()
{
    print(1,2.5,3,"A");
    return 0;
}