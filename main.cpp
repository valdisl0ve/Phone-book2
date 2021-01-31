#include <iostream>
#include <map>
#include "Person.h"
#include "Export.h"
#include "Import.h"
#include "AddShowFindDelete.h"
using namespace std;

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
            cout << "Who do you want to find?" << endl;
            cin >> key;
            FindSomebody(phoneBook, key);
            cout << "What do you want to change?" << endl;
            cout << "1 - lastname" << endl;
            cout << "2 - name" << endl;
            cout << "3 - phone number" << endl;
            cout << "4 - group" << endl;
            cin >> change;
            cout << "Enter the new value" << endl;
            cin >> temp;
            ChangeSomebody(phoneBook, key, change, temp);
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