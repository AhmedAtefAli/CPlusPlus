#include <iostream>
#include <memory>

template <typename T, int size> class Stack {
  T buffer[size];
  int top{-1};

public:
  Stack() = default;
  Stack(const Stack &rhs);
  // void push(const T& value)
  //{
  //    buffer[++top] = value;
  //}
  void Push(const T &value);

  T &Pop() { return buffer[top--]; }

  const T &Top() const;

  bool IsEmpty() const { return top == -1; }

  static Stack Create(); // short hand notation
};

template <typename T, int size> void Stack<T, size>::Push(const T &value) {
  buffer[++top] = value;
}

template <typename T, int size> Stack<T, size>::Stack(const Stack &rhs) {
  top = rhs.top;
  for (int i = 0; i <= top; i++) {
    buffer[i] = rhs.buffer[i];
  }
}

template <typename T, int size> const T &Stack<T, size>::Top() const {
  return buffer[top];
}

template <typename T, int size> Stack<T, size> Stack<T, size>::Create() {
  return Stack<T, size>();
}

int main() {
  Stack<float, 10> s;

  s.Push(3);
  s.Push(5);
  s.Push(9);
  s.Push(1);

  Stack<int, 10> S3 = Stack<int, 10>::Create();
  Stack<float, 10> S2 = s;

  while (!S2.IsEmpty()) {
    std::cout << S2.Pop() << std::endl;
  }
  return 0;
}