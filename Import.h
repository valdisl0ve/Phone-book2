#pragma once
#include <fstream>





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
