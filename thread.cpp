#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>

//std::mutex glock;
static std::atomic<int> shared{0};
void increment_shared()
{
    //std::lock_guard<std::mutex> guard(glock);
    //shared = shared +1;
    shared++;
}
int main()
{
    std::vector<std::thread> myVec{};
    for(int i=0;i < 1000;i++)
    {
        myVec.push_back(std::thread(increment_shared));
    }
    for(auto& it : myVec)
    {
        it.join();
    }

    std::cout <<"Shared value is "<<shared<<std::endl;
    return 0;
}