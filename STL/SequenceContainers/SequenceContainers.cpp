#include <iostream>
#include <array>
#include <vector>
#include <deque>

void Array()
{

    std::array<int,5> arr{1,2,3,4,5};

    for(int i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i]<< " , ";
    }

    // creation of iterator
    auto iter = arr.begin();

    std::cout << std::endl;

    // access the array using the iterator
    for (auto it : arr)
    {
        std::cout << it << " , ";
    }
    
    // access the pointer of the array directly
    std::cout <<std::endl<<  " the address of the array is : " << arr.data();

}

void Vector()
{
    std::vector<int> vec{1,2,3,4};

    // adding elements to vector
    for(int i = 0;i < 5 ;i++)
    {
        vec.push_back(i * 10);
        std::cout << vec.size()<< std::endl;
        // notice how the size of the vector grows dynamically during runtime 
        // without performing memory management from our side
    }

    // accessing Vector elements
    // using iterators
    auto it = vec.begin();

    while(it != vec.end())
    {
        std::cout << *it++ <<" ";
    }

    // using subscriptor operator
    vec[0] = 100;

    std::cout << std::endl;

    // print all vector elements
    for(auto it : vec)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    // insert element inside vector
    vec.insert(vec.begin(), 600);
    // insert at any position in vector except at the end will imply some performance implications
    // as vector will perfom some shifting operations that requires execute copy and assignment operations
    // so try push_back function instead

    // delete elements from vector
    vec.erase(vec.end());
    for(auto it : vec)
    {
        std::cout << it << " ";
    }

    // use pop_back instead
    vec.pop_back();

}

void Deque()
{
    std::deque<int> vec;

    // adding elements to vector
    for(int i = 0;i < 5 ;i++)
    {
        vec.push_back(i * 10);
        std::cout << vec.size()<< std::endl;
        // notice how the size of the vector grows dynamically during runtime 
        // without performing memory management from our side
    }

    for(int i = 5;i < 10 ;i++)
    {
        vec.push_front(i * 10);
        std::cout << vec.size()<< std::endl;
        // notice how the size of the vector grows dynamically during runtime 
        // without performing memory management from our side
    }

    // accessing Vector elements
    // using iterators
    auto it = vec.begin();

    while(it != vec.end())
    {
        std::cout << *it++ <<" ";
    }

    // using subscriptor operator
    vec[0] = 100;

    std::cout << std::endl;

    // print all vector elements
    for(auto it : vec)
    {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    // insert element inside vector
    vec.insert(vec.begin(), 600);
    // insert at any position in vector except at the end will imply some performance implications
    // as vector will perfom some shifting operations that requires execute copy and assignment operations
    // so try push_back function instead

    // delete elements from vector
    vec.erase(vec.end());
    // use pop_back instead
    vec.pop_back();
    vec.pop_front();
    for(auto it : vec)
    {
        std::cout << it << " ";
    }



}

int main()
{
    //Array();
    //Vector();
    Deque();
    return 0;
}