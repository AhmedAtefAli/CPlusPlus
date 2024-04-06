#include "Integer.h"
#include <iostream>

Integer Add(const Integer &a, const Integer &b){
	Integer temp ;
	temp.SetValue(a.GetValue() + b.GetValue()) ;
	return temp ;
}

class Number{

	Integer mValue{};

	public:
	Number(int value) : mValue{value}
	{

	}

	Number( Number&& n) : mValue{std::move(n.mValue)}
	{
	}
	Number& operator=(Number && rhs) = default;
};

Number CreateNumber(int num)
{
	return Number(num);
}
int main() {
	//Integer a(1), b(3) ;
	//a.SetValue(Add(a,b).GetValue()) ;
	Number n1{5};
	//auto n2{n1};
	//n2 = n1;
	auto n3{CreateNumber(6)};
	n3 = CreateNumber(82);
	n3 = std::move(n1);
	n1 = CreateNumber(64);

	return 0;
}