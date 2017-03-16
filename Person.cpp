#include "stdafx.h"
#include "Person.h"

Person::Person()
{
}

Person::Person(string name1, string name2, string name3) {
	this->name1 = name1;
	this->name2 = name2;
	this->name3 = name3;
}

Person::~Person()
{
}

void Person::setName(int whichOne, string value) throw (out_of_range)
{
	switch (whichOne) {
	case 1:
		name1 = value;
		break;
	case 2:
		name2 = value;
		break;
	case 3:
		name3 = value;
		break;
	default:
		throw out_of_range("");
	}
}

ostream& operator<<(ostream & s, Person p) {
	s << p.name1 << " " << p.name2 << " " << p.name3;
	return s;
}

istream& operator>> (istream& s, Person p) {
	s >> p.name1 >> p.name2 >> p.name3;
	return s;
}

