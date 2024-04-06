#include <iostream>
#include "Integer.h"

//Integer operator+(const Integer& lhs,const Integer& rhs) 
//{
//	Integer temp;
//	temp.SetValue(lhs.GetValue() + rhs.GetValue());
//	return temp;
//}

Integer operator+(const int& lhs,const Integer& rhs) 
{
	Integer temp;
	temp.SetValue(lhs + rhs.GetValue());
	return temp;
}

std::ostream & operator<<(std::ostream& out, const Integer& obj)
{
	out << obj.GetValue();
	return out;
}
std::istream& operator>>(std::istream& in,Integer& obj)
{
	int temp;
	in >> temp;
	*obj.m_pInt =temp;
	return in;
}

int main()
{
	Integer a{5};
	Integer b{5};

	Integer c = a + 5;
	std::cout << "please insert an integer number : "; 
	std::cin >>c;
	std::cout <<"the value is : "<< c <<std::endl;
    return 0;
}