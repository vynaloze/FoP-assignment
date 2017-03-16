#include "stdafx.h"
#include "DataBase.h"

bool DataBase::readFromFile(string fileName) {
	// declare stream and enable handling exceptions
	ifstream in;
	in.exceptions(ifstream::failbit | ifstream::badbit);

	// read names from a file, put them together in objects and add objects to the dynamic list
	try {
		string temp;
		in.open(fileName);
		while (!in.eof()) {
			// read a single line from the file
			getline(in, temp);
			// create a new Person object and initialise it with names (that were separated by spaces)
			string* names = parseArguments(temp);
			Person person = Person(names[0], names[1], names[2]);
			// add this object to the list
			this->personList.push_back(person);
		}
	}
	catch (ios_base::failure const &e) {
		cerr << "Error: " << e.what() << " Please try again." << endl;
		return false;
	};
	in.close();
	return true;
}

void DataBase::printAll() {
	// print objects on the screen
	cout << "Content of a file:" << endl;
	int i = 1;
	for (Person p : this->personList) {
		cout << i++ << ". " << p << endl;
	}
}

void DataBase::processCommand(string input)
{
	string* args = parseArguments(input);

	if (args[0] == "exit" || args[0] == "") {
		// nothing
	}
	else if (args[0] == "print") {
		printAll();
	}
	else if (args[0] == "mod") {
		try {
			personList.at(stoi(args[1]) - 1).setName(stoi(args[2]), args[3]);
		}
		catch (invalid_argument e) {
			// catches exception from stoi
			cerr << "Error: you did not provide a number." << endl;
		}
		catch (out_of_range e) {
			// catches out of range exceptions from "at" and "setName"
			cerr << "Error: number out of range." << endl;
		}
	}
	else if (args[0] == "add") {
		personList.push_back(Person(args[1], args[2], args[3]));
	}
	else if (args[0] == "del") {
		try {
			int whichOne = stoi(args[1]) - 1;
			// no exception thrown by erase functions so we need to deal with it in this way
			if (whichOne >= personList.size()) {
				throw range_error("");
			}
			personList.erase(personList.begin() + whichOne);
		}
		catch (invalid_argument e) {
			// catches exception from stoi
			cerr << "Error: you did not provide a number." << endl;
		}
		catch (range_error e) {
			// catches out of range exceptions from erase
			cerr << "Error: number out of range." << endl;
		}
	}
	else if (args[0] == "save") {
		writeToFile(args[1]);
	}
	else {
		cout << "Unknown command. Try again." << endl;
	}

}

string* DataBase::parseArguments(string input)
{
	// cut given string into max 4 words that were separated by spaces
	string* arguments = new string[4];
	istringstream iss(input);
	string temp;
	for (int i = 0; i < 4; i++) {
		iss >> arguments[i];
	};
	return arguments;
}

void DataBase::writeToFile(string name) {
	ofstream out;
	out.exceptions(ofstream::failbit | ofstream::badbit);

	try {
		out.open(name);
		bool first = true;
		for (Person p : personList) {
			if (!first) {
				out << "\n";
			}
			first = false;
			out << p.name1 << " " << p.name2 << " " << p.name3;
		}
		out.close();
		cout << "Save successfull." << endl;
	}
	catch (ios_base::failure const &e) {
		cerr << "Error: " << e.what() << "Please try again.";
	};
}
