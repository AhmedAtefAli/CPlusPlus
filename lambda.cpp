#include <iostream>

//using comparator = bool (*)(int,int);
template<typename T,int size,typename comparator>
void Sort(T (&arr)[size],comparator comp)
{
    for(int i = 0; i < size-1;i++)
    {
        for(int j = 0;j <size-1;j++)
        {
            if(comp(arr[j],arr[j+1]))
            {
                T temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

bool comp(int x, int y)
{
    return x > y;
}

bool comp1(int x, int y)
{
    return x < y;
}

struct comp2
{
    bool operator()(int x, int y)
    {
        return x < y;
    }
};

int main()
{

    //auto lambda = [](int x, int y) -> int
    //{
    //    return x+y;
    //};
    //std::cout <<lambda(5,6)<<std::endl;

    int arr[]{100,45,6,97,56,4,1,2,35,5};
    comp2 comp;
    for(auto& it : arr)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    Sort(arr,[](auto x, auto y){
        return x < y;
    });
    
    for(auto& it : arr)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;
    return 0;
}