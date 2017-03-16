#include "stdafx.h"
#include "Person.h"
#include "DataBase.h"


int main()
{
	DataBase dataBase = DataBase();

	cout << "-----------------------------------------------------------" << endl
		<< "Fundamentals Of Programming - Assesment: \"Database program\".\nCreated by Piotr Pawluk." << endl
		<< "-----------------------------------------------------------" << endl;

	// try to open a file (until success)
	string fileName;
	do {		
		cout << "Please provide a name of a file to open: ";
		getline(cin, fileName);		
	} while (!dataBase.readFromFile(fileName));
 
	dataBase.printAll();

	// ask user what to do
	cout << "-----------------------------------------------------------" << endl
		<< "Avaliable commands:" << endl
		<< "Print the list: print" << endl
		<< "Modify: mod [number of object (1-n)] [number of field (1-3)] [value to write]" << endl
		<< "Add: add [value1] [value2] [value3]" << endl
		<< "Remove: del [number of object (1-n)]" << endl
		<< "Save: save [name of a fie]" << endl
		<< "Exit: exit" << endl
		<< "-----------------------------------------------------------" << endl;
	string s;
	while (s != "exit") {
		getline(cin, s);
		dataBase.processCommand(s);
	}
	
    return 0;
}

