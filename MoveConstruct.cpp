#include <iostream>
#include <memory>

using namespace std;

class Integer {
	int *m_pInt;
public:
	//Default constructor
	Integer();
	//Parameterized constructor
	Integer(int value);
	//Copy constructor
	Integer(const Integer &obj);
	//Move constructor
	Integer(Integer &&obj);
	int GetValue()const;
	void SetValue(int value);
	~Integer();

};

Integer::Integer() {
	std::cout << "Integer()" << std::endl;
	m_pInt = new int(0);
}

Integer::Integer(int value) {
	std::cout << "Integer(int)" << std::endl;
	m_pInt = new int(value);
}

int Integer::GetValue() const {
	return *m_pInt;
}

void Integer::SetValue(int value) {
	*m_pInt = value;
}

Integer::~Integer() {
	std::cout << "~Integer()" << std::endl;
	delete m_pInt;
}

Integer::Integer(const Integer& ref)
{
    std::cout << "Integer(const Integer&)" << std::endl;
    delete m_pInt;
    m_pInt = new int(*(ref.m_pInt));
}

Integer::Integer(Integer&& obj)
{
	std::cout << "Integer(Integer&&)" << std::endl;
	m_pInt = obj.m_pInt;
	obj.m_pInt = nullptr;
}
Integer Add(const Integer& a,const Integer& b)
{
    Integer temp;
    temp.SetValue(a.GetValue() + b.GetValue());
    return temp;
}
int main()
{
    Integer a(1), b(3) ;
    a.SetValue(Add(a,b).GetValue());
    return 0;
}