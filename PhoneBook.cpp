#include <iostream>
#include <string>
#include <map>
#include <fstream>
using namespace std;

struct Person {
	string name;
	string lastName;
	string phoneNumber;
	string group;
};


void AddPerson(map<string, Person>& phoneBook) {
	Person person;
	string lastName;
	cout << "\n\n\n1. Enter the lastname - "; cin >> lastName;
	person.lastName = lastName;
	cout << "2. Enter the name - "; cin >> person.name;
	cout << "3. Enter the phone number - "; cin >> person.phoneNumber;
	cout << "4. Enter the group - "; cin >> person.group;

	phoneBook.insert(make_pair(lastName, person));

}

void ShowAll(map<string, Person> phoneBook) {
	cout << "\n\n\n\t+++BOOK LIST+++\n\n\n";
	for (auto item : phoneBook) {
		cout << endl;
		cout << item.first << " "
			<< item.second.name << " "
			<< item.second.phoneNumber << " "

			<< item.second.group << endl;
	}
}



void FindSomebody(map<string, Person> phoneBook, string key) {

	auto iterator = phoneBook.find(key);
	if (iterator != phoneBook.end()) {
		cout << iterator->second.lastName << " "
			<< iterator->second.name << " "
			<< iterator->second.phoneNumber << " "
			<< iterator->second.group << endl;
	}
	else {
		cout << "No one found (" << endl;
	}
}


string FindSomebody(map<string, Person> phoneBook) {
    string key;
    cout << "Who do you wont to find?" << endl;
    cin >> key;
    FindSomebody(phoneBook, key);
    return key;
}

void ChangeSomebody(map<string, Person> phoneBook,  string key, int change, string temp) {
    auto iterator = phoneBook.find(key);
    if (change == 1) {
        iterator->second.lastName = temp;
    }
    if (change == 2) {
        iterator->second.name = temp;
    }
    if (change == 3) {
        iterator->second.phoneNumber = temp;
    }
    if (change == 4) {
        iterator->second.group = temp;
    }
    FindSomebody(phoneBook, key);
}


void DeleteSomebody(map<string, Person>& phoneBook, string key) {
	phoneBook.erase(key);
}


void WriteToFile(map<string, Person> phoneBook, ofstream& file) {

	for (auto iter : phoneBook)
	{
		file << iter.second.name << ";";
		file << iter.second.lastName << ";";
		file << iter.second.phoneNumber << ";";
		file << iter.second.group << endl;
	}
}

void ReadFromFile(map<string, Person>& phoneBook, ifstream& file) {
	Person person;
	string key;
	string someShit;

	while (!file.eof()) {
		getline(file, person.name, ';');
		getline(file, person.lastName, ';');
		getline(file, person.phoneNumber, ';');
		getline(file, person.group);

		key = person.lastName;
		phoneBook.insert(make_pair(key, person));
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

void ImportFromFile(map<string, Person>& phoneBook) {
	ifstream file;
	string address;

	cout << "Please, Enter The Address Of File" << endl;
	cin >> address;

	file.open(address);

	if (file.is_open() && file.peek() == -1) {
		cout << "File is empty. Please, try again" << endl;
	}
	else if (file.is_open() && file.peek() != -1) {
		ReadFromFile(phoneBook, file);
		cout << "Adding students list from file is successful" << endl;
	}
	else {
		cout << "There is no such file. Please try again" << endl;
	}
	file.close();
}



int main()
{
	map<string, Person> phoneBook;
	int menu;
    string temp;
    int change;
    string key;

	cout << "\n\n\t+++PhoneBook+++\n\n";
	do {
		cout << "\n\n\nTo add somebody press [1]" << endl;
		cout << "To show all press [2]" << endl;
		cout << "To find somebody press [3]" << endl;
		cout << "To change somebody press [4]" << endl;
		cout << "To delete somebody press [5]" << endl;
		cout << "To export file press [6]" << endl;
		cout << "To import file press [7]" << endl;
		cout << "To exit press [8]" << endl;
		cout << endl << "Choose something - ";
		cin >> menu;

		switch (menu) {

		case 1:
			AddPerson(phoneBook);
			break;

		case 2:
			ShowAll(phoneBook);
			break;

		case 3:
		{
			string key;
			cout << "Enter the last name - "; cin >> key;
			FindSomebody(phoneBook, key);
			break;
		}

		case 4:
		{
            key = FindSomebody(phoneBook);
            cout << "What do you want to change?" << endl;
            cout << "1 - lastname" << endl;
            cout << "2 - name" << endl;
            cout << "3 - phone number" << endl;
            cout << "4 - group" << endl;
            cin >> change;
            cout << "Enter the new value" << endl;
            switch (change) {
                case 1:
                    cin >> temp;
                    ChangeSomebody(phoneBook, key, change, temp);
                    break;
                case 2:
                    cin >> temp;
                    ChangeSomebody(phoneBook, key, change, temp);
                    break;
                case 3:
                    cin >> temp;
                    ChangeSomebody(phoneBook, key, change, temp);
                    break;
                case 4:
                    cin >> temp;
                    ChangeSomebody(phoneBook, key, change, temp);
                    break;
            }
            break;

		}
		case 5:
		{
			string key;
			cout << "Enter the last name - "; cin >> key;
			DeleteSomebody(phoneBook, key);

			cout << "RESULT" << endl << endl;
			ShowAll(phoneBook);
			break;
		}
		case 6:
		{
			ExportToFile(phoneBook);
			break;
		}
		case 7:
		{
			ImportFromFile(phoneBook);
			break;
		}
		}

	} while (menu != 8);
	return 0;
}
