#include <iostream>
#include <memory>
#include <vector>


template<typename T>
T Max(T x, T y)
{
    std::cout << "T Max(T x, T y)"<< std::endl;
    return x < y ? y : x;
}

template<typename T>
T Add(T x, T y)
{
    return x + y;
}

template<typename T>
T ArraySum(const T  * arr, std::size_t Sz)
{
    T sum = 0;
    for(int idx = 0; idx < Sz; idx++)
    {
        sum += arr[idx];
    }

    return sum;
}

template<typename T> 
T Max(const T * arr, std::size_t Sz)
{
    T Max = arr[0];
    for(int idx = 0;idx < Sz;idx++)
    {
        if(Max < arr[idx])
        {
            Max = arr[idx];
        }
    }

    return Max;
}

template<typename T>
std::pair<T,T> MinMax(const T * arr, std::size_t Sz)
{
    std::pair<T,T> pair{};
    pair.first = arr[0];
    pair.second = arr[0];

    for(int idx = 0;idx < Sz;idx++)
    {
        if(pair.first > arr[idx])
        {
            pair.first = arr[idx];
        }
        if(pair.second < arr[idx])
        {
            pair.second = arr[idx];
        }
    }

    return pair;
}

int main()
{
    int arr[] {1,3,4,5,678,8,9,111};
    auto num = Max(9,5);
    std::cout << std::endl<< num << std::endl;
    auto num2 = Max(3.5f,5.3f);
    std::cout << num2 << std::endl;
    auto num3 = Max(arr, 8);
    std::cout << num3 << std::endl;
    auto sum = ArraySum(arr,8);
    std::cout << "Sum of array : "<< sum<<std::endl;
    auto pair = MinMax(arr,8);
    std::cout << " Min of arr : "<<pair.first<<" , Max of arr : "<<pair.second<<std::endl;
    return 0;
}