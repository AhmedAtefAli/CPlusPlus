#include <iostream>
#include <memory>
#include <vector>
#include <cstring>
template<typename T>
T Max(T x, T y)
{
    std::cout << typeid(T).name()<<std::endl;
    return x < y ? y : x;
}

// explicit template instantiation for type char
template char Max(char x, char y);

// explicit template specialization of Max function
template<> const char * Max<const char *>(const char* x, const char* y)
{
    std::cout << std::endl<< "Max<const char *>()"<< std::endl;
    return strcmp(x,y) > 0 ? x : y;
}

int main()
{
    const char * B{"B"};
    const char * A{"A"};
    std::cout << Max(A,B)<<std::endl;

    // template class and function instantiation
    std::vector<int> Vec{1,2,3,4,5};
    Max(3,5);
    // explicit specifying the type in the arguement list so no deduction is performed and template is instantiated.
    Max<double>(3,5.6);

    // template instantiation by taking address of the function template
    float(*pfn)(float,float) = Max;
    return 0;
}