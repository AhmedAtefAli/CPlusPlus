#include <iostream>
#include <thread>
#include <future>
#include <vector>

int Add(int x, int y)
{
    return x + y;
}

int Square(int x)
{
    return x * x;
}

int Compute(const std::vector<int>& vec )
{
    int sum = 0;
    using namespace std;
    for(auto iter : vec)
    {
        sum += iter;
        std::this_thread::sleep_for(1s);
        std::cout << ".";
    }
    return sum;
}
int main()
{
    std::packaged_task<int(int,int)> taskAdd{Add};
    std::future<int> ft = taskAdd.get_future();

    taskAdd(3,5);
    auto result = ft.get();
    std::cout << result << std::endl;

    std::packaged_task<int(int)> taskSquare{Square};
    std::future<int> fut = taskSquare.get_future();
    taskSquare(4);
    std::cout << fut.get()<<std::endl;

    std::packaged_task<int(std::vector<int>&)> taskCompute{Compute};
    std::future<int> ftCompute = taskCompute.get_future();
    std::vector<int> data{1,2,3,4,5};
    //taskCompute(data);
    std::thread thCompute{std::move(taskCompute),std::ref(data)};
    std::cout << "thread has started\n";
    std::cout << ftCompute.get() << std::endl;
    std::cout << "End of main"<<std::endl;
    thCompute.join();
}