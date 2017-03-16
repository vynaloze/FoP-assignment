#pragma once
#include "Person.h"
class DataBase
{
public:	
	bool readFromFile(string fileName);
	void printAll();
	void processCommand(string input);

private:
	vector<Person> personList;
	string* parseArguments(string input);
	void writeToFile(string name);
};

