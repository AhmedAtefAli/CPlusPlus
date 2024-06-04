#include <iostream>
#include <memory>

struct Free
{
    void operator()(int* ptr)
    {
        free(ptr);
        std::cout << "pointer freed "<<std::endl;
    }

    Free* operator&()  
    {
        return this;
    }
};

template<typename T>
void MallocFree(T* ptr)
{
    free(ptr);
    std::cout << "Free pointer function \n";
}

int main()
{

    std::unique_ptr<int, void (*)(int*)> p{(int * )malloc(4),MallocFree<int>};
    std::shared_ptr<int> ptr{(int*)malloc(4), MallocFree<int>};
    std::shared_ptr<int> ptr1{(int*)malloc(4), Free{}};
    *p = 100;
    *ptr = 32;
    std::cout << *p << std::endl;
    std::cout <<*ptr<<std::endl;

    std::shared_ptr<int[]> arr{new int[5]{1,2,3,5,4}};
    arr[0] = 23;

    for(int i = 0;i  < 5;i++)
    {
        std::cout << " , "<< arr[i];
    }

    auto del = std::get_deleter<void (*)(int*)>(ptr);
    if(*del == MallocFree<int>)
    {
        std::cout <<" owns deleter"<<std::endl;
    }
    else
    {
        std::cout << " does not own deleter or null "<< std::endl; 
    }
    //free(p);
    return 0;
}