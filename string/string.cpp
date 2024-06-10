#include <iostream>
#include <string>
int main()
{
    std::string s{"Ahmed"};
    s += " Atef ";
    s += " Ali ";
    std::cout <<s <<std::endl;

    std::cout << s.size()<<std::endl;
    std::cout << s.capacity()<< std::endl;
    return 0;
}