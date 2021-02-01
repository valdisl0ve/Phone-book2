#pragma once
#include <fstream>

void WriteToFile(map<string, Person> phoneBook, ofstream& file) {

	for (auto iter : phoneBook)
	{
		file << iter.second.name << ";";
		file << iter.second.lastName << ";";
		file << iter.second.phoneNumber << ";";
		file << iter.second.group << endl;
	}
}




void ExportToFile(map<string, Person> phoneBook) {
	string address;
	ofstream file;
	cout << "Please, Enter The Adress Of File" << endl;
	cin >> address;
	file.open(address, ios_base::trunc);
	if (phoneBook.empty()) {
		cout << "The phonebook is empty. Please, add some positions first." << endl;
	}
	else if (file.is_open()) {
		WriteToFile(phoneBook, file);
		cout << "Recording is successful" << endl;
	}
	else {
		cout << "There is no such file. Please try again" << endl;
	}
	file.close();
}
