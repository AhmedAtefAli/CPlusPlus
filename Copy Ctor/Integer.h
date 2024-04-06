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
	
	int GetValue()const;
	void SetValue(int value);
	~Integer();

};
