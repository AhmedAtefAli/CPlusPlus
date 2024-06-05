#include <iostream>

class Stack
{
    int Top{-1};
    int buffer[512]{};

    public:
    void Push(int value)
    {
        buffer[++Top] = value;
    }

    int Pop()
    {
        int x = buffer[Top--];
        return x;
    }

    int Peek()
    {
        return buffer[Top];
    }

    bool isEmpty()
    {
        return Top < 0;
    }
};

int main()
{
    Stack s;
    s.Push(5);
    s.Push(9);
    s.Push(57);
    s.Push(3);

    while(!s.isEmpty())
    {
        std::cout<<s.Peek()<<" ";
        s.Pop();
    }
}