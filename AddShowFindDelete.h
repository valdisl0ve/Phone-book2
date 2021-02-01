#pragma once


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
	int i = 1;
	for (auto item : phoneBook) {
		cout << "+++HUMAN # " << i << "+++" << endl << endl;
		cout << "First name - " << item.first << endl;
		cout << "Second name - " << item.second.name << endl;
		cout << "Phone number - " << item.second.phoneNumber << endl;
		cout << "Group - " << item.second.group << endl << endl << endl;
		i++;
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

void ChangeSomebody(map<string, Person> &phoneBook, string key, int change, string temp) {
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

