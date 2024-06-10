#include <iostream>
#include <thread>
#include <list>
#include <mutex>

std::list<int> gData;
constexpr int size = 10000;
std::mutex gMutex{};

class String {
public:
	String() {
		std::cout << "String()" << std::endl;
	}
	String(const String &) {
		std::cout << "String(const String&)" << std::endl;
	}
	String & operator=(const String&) {
		std::cout << "operator=(const String&)" << std::endl;

		return *this;
	}
	~String() {
		std::cout << "~String()" << std::endl;
	}
};

void Download()
{
    //std::cout << "[Download] Started Download" << std::endl;
    for(int i=0;i < size;i++)
    {
        gMutex.lock();
        gData.push_back(i);
        gMutex.unlock();
    }
    //std::cout << "[Download] Finished Download"<<std::endl;
}

void Download2()
{
    for(int i=0;i < size;i++)
    {
        gMutex.lock();
        gData.push_back(i);
        gMutex.unlock();
    }
}

int main()
{
    //String file;
    //std::cout << "[main]User started an operation" << std::endl; 
    //std::thread thDownload(Download, std::cref(file));
    //
    ////thDownload.detach();
    //std::cout << "[main]User started another operation" << std::endl;
    //if(thDownload.joinable())
    //{
    //    thDownload.join();
    //}
    std::thread thDownload{Download};
    std::thread thDownload2{Download2};
    thDownload.join();
    thDownload2.join();
    std::cout <<std::endl<< gData.size()<<std::endl;
   
    return 0;
}