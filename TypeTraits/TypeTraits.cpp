#include <iostream>
#include <type_traits>

class Employee
{

};

void algorithm_signed(){
    std::cout << " algorithm_signed() "<< std::endl;
}

void algorithm_unsigned()
{
    std::cout << " algorithm_unsigned() "<<std::endl;
}

template<typename T>
void algorithm(T t)
{
    if(std::is_signed<T>::value)
    {
        algorithm_signed();
    }

    else if (std::is_unsigned<T>::value)
    {
        algorithm_unsigned();
    }
    else
    {
        static_assert(std::is_signed<T>::value || std::is_unsigned<T>::value, "Must be signed or unsigned!");
    }
}
int main()
{

    std::cout << std::is_floating_point<int>::value<< std::endl;
    std::cout << std::is_floating_point<float>::value << std::endl;
    std::cout << std::is_floating_point<char>:: value<< std::endl;
    std::cout << std::is_class<Employee>::value<<std::endl;
    std::cout << std::is_integral<int>::value<<std::endl;

    std::cout << std::is_same<int,std::remove_reference<int>::type>::value << std::endl;
    std::cout << std::is_same<int,std::remove_reference<int&>::type>::value << std::endl;
    std::cout << std::is_same<int,std::remove_reference<int&&>::type>::value << std::endl;

    int x = 6;
    unsigned int y = 7;
    Employee Z{};

    algorithm(x);
    algorithm(y);
    //algorithm(Z);



    return 0;
}