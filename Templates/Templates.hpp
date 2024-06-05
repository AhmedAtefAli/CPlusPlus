#include <iostream>
#include <algorithm>
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

template<typename T,int size>
T ArraySum(const T (&arr)[size])
{
    T sum = 0;
    for(auto iter : arr)
    {
        sum += iter;
    }

    return sum;
}

template<typename T, int size> 
T Max( T (&arr)[size])
{
    T Max = arr[0];
    for(auto iter : arr)
    {
        if(Max < iter)
        {
            Max = iter;
        }
    }

    return Max;
}

template<typename T,int size>
std::pair<T,T> MinMax( T (&arr)[size])
{
    std::pair<T,T> pair{};
    pair.first = arr[0];
    pair.second = arr[0];

    for(int idx = 0;idx < size;idx++)
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
