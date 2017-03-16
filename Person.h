#pragma once
#include "stdafx.h"

class Person
{
public:
	string name1;
	string name2;
	string name3;

	Person();
	Person(string name1, string name2, string name3);
	~Person();

	void setName(int whichOne, string value);

	friend ostream& operator<< (ostream& s, Person p);
	friend istream& operator>> (istream& s, Person p);
};

