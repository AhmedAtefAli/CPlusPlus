#pragma once
#include <iostream>
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
	//Copy Assignment Operator
	Integer& operator=(const Integer& obj);
	//Move Assignment Operator
	Integer& operator=(Integer&& obj);

	// addition operator
	Integer operator+(const Integer& rhs) const;
	// pre increment operator
	Integer& operator++();
	// post increment operator
	Integer operator++(int);
	// comparison operator
	bool operator==(const Integer& rhs) const;
	friend std::istream& operator>>(std::istream& in,Integer& obj);
	operator int() const;
	
	int GetValue()const;
	void SetValue(int value);
	~Integer();

};
