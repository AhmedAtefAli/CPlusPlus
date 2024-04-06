#include <iostream>
using namespace std;

class Integer
{
    public:
    Integer()
    {
        mPtr = new int(0);
    }
    Integer(int value)
    {
        mPtr = new int(value);
    }
    ~Integer()
    {
        delete mPtr;
    }
    Integer( Integer &copy)
    {
        delete mPtr;
        mPtr = new int(*(copy.mPtr));
    }

    void setValue(int value)
    {
        *mPtr = value;
    }

    int getValue() const
    {
        return *mPtr;
    }

    private:
    int *mPtr{nullptr};
};
int main()
{
    Integer i(5);
    Integer i2(i); // invoke copy constructor
    cout << i.getValue()<< endl;
    return 0;
}