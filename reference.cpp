#include<iostream>
#include <memory>

using namespace std;

void Print(int& x)
{
    cout << "Print(int&)"<< endl;
}

void Print(const int &x)
{
    cout << "Print(const int&)" << endl;
}

void Print(int&& ref)
{
    cout << "Print(int&&)"<<endl;
}

void Print(float x)
{
    std::cout << " Print(float x)"<<std::endl;
}

void Print(float* ptr)
{
    std::cout << " Print(float* ptr) "<< std::endl;
}

void Print(const float* ptr)
{
    std::cout << " Print(const float* ptr) "<< std::endl;
}

int main()
{
    int &&r1 = 52;
    int x =20;
    int &r2 = r1;
    cout << r1 <<endl;
    cout << r2 << endl;
    float y = 4.5f;
    const float z = 5.6f;

    Print(x);
    Print(&y);
    Print(&z);
    Print(r1);
    Print(56);
    return 0;
}