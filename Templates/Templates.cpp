#include <iostream>
#include <memory>
#include <vector>
#include <cstring>
#include <algorithm>
#include "Templates.hpp"

// explicit template specialization
template <> const char* Max<const char*,4>(const char* (&arr)[4])
{
    const char * max = arr[0];
    for(int idx = 0;idx < 4;idx++)
    {
        if(strcmp(max,arr[idx]) < 0)
        {
            max = arr[idx];
        }
    }
    return max;
}

template <> std::string Max<std::string, 4>(std::string (&arr)[4])
{
    auto str = std::max_element(std::begin(arr),std::end(arr));
    return *str;
}

template <> std::pair<const char *, const char *> MinMax<const char *, 4>(const char * (&arr)[4])
{
    std::pair<const char *,const char *> pair{};
    pair.first = arr[0];
    pair.second = arr[0];

    for(int idx = 0;idx < 4;idx++)
    {
        if(strcmp(pair.second,arr[idx]) < 0)
        {
            pair.second = arr[idx];
        }

        if(strcmp(pair.first,arr[idx]) > 0)
        {
            pair.first = arr[idx];
        }

    }

    return pair;
}

template<> std::pair<std::string,std::string> MinMax<std::string,4>(std::string (&arr)[4])
{
    auto max = std::max_element(std::begin(arr),std::end(arr));
    auto min = std::min_element(std::begin(arr),std::end(arr));

    return std::pair<std::string,std::string>{*min,*max};
}

int main()
{
    int arr[] {1,3,4,5,678,8,9,111};
    auto num = Max(9,5);
    std::cout << std::endl<< num << std::endl;
    auto num2 = Max(3.5f,5.3f);
    std::cout << num2 << std::endl;
    auto num3 = Max(arr);
    std::cout << num3 << std::endl;
    auto sum = ArraySum(arr);
    std::cout << "Sum of array : "<< sum<<std::endl;
    auto pair = MinMax(arr);
    std::cout << " Min of arr : "<<pair.first<<" , Max of arr : "<<pair.second<<std::endl;

    const char* str[4] {"D","C","B","A"};
    std::cout << Max(str)<<std::endl;
    auto strPair = MinMax(str);
    std::cout << " Min of str : "<<strPair.first<< " , Max of str :  "<< strPair.second<<std::endl;

    std::cout << "string literals usage "<<std::endl;

    std::string string[4] {"D","C","B","A"};
    std::cout << Max(string)<<std::endl;
    auto StringPair = MinMax(string);
    std::cout << " Min of str : "<<StringPair.first<< " , Max of str :  "<< StringPair.second<<std::endl;

    return 0;
}