#include <iostream>
#include <memory>

template<typename T,int col>
class PrettyPrinter
{
    T* data{};

public:
    PrettyPrinter(T* value)
    {
        data = value;
    }

    void Print()
    {
        std::cout <<"Columns : "<<col<<std::endl;
        std::cout << "{ "<<*data<<" }"<< std::endl;
    }

    T* GetData()
    {
        return data;
    }
};

// partial specialization for PrettyPrinter
template<typename T>
class PrettyPrinter<T,80>
{
    T* data{};

public:
    PrettyPrinter(T* value)
    {
        data = value;
    }

    void Print()
    {
        std::cout <<"using column 80 "<<std::endl;
        std::cout << "{ "<<*data<<" }"<< std::endl;
    }

    T* GetData()
    {
        return data;
    }
};

template<typename T>
class SmartPointer
{
    T * mPtr;
public:

    SmartPointer(T* ptr) : mPtr{ptr}
    {

    }

    T* operator->()
    {
        return mPtr;
    }

    T& operator*()
    {
        return *mPtr;
    }

    ~SmartPointer()
    {
        delete mPtr;
    }

};

template<typename T>
class SmartPointer<T[]>
{
    T * mPtr;
public:

    SmartPointer(T* ptr) : mPtr{ptr}
    {
    }

    T& operator[](int index)
    {
        return mPtr[index];
    }

    ~SmartPointer()
    {
        delete[] mPtr;
    }

};

int main()
{
    int data = 800;
    PrettyPrinter<int,80> P(&data);
    P.Print();
    SmartPointer<int> ptr(new int{5});
    std::cout << *ptr<<std::endl;
    SmartPointer<int[]> arr(new int[5]);
    arr[1] = 34532; 
    std::cout << arr[1]<<std::endl;
    return 0;
}
