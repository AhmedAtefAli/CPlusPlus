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

//void Print(int&& ref)
//{
//    cout << "Print(int&&)"<<endl;
//}
int main()
{
    int &&r1 = 52;
    int x =20;
    int &r2 = r1;
    cout << r1 <<endl;
    cout << r2 << endl;

    Print(x);
    Print(r1);
    Print(56);
    return 0;
}