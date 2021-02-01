Проект "Phone Book" (Ну или какое-там название).
Ссылка на гитхаб (ссылка).

Переменная телефонной книги phoneBook представляет из себя структуру map<string, Person>.
В качестве ключа к паре элементов передается строка с фамилией человека.
Поля структуры Person:
- string name;
- stringlastName;
- stringphoneNumber;
- stringgroup;

Список используемых функций.
1. Добавление новых человеков в телефонную книгу - void AddPerson(map<string, Person>& phoneBook);
2. Вывод на экран всех человеков из телефонной книги - void ShowAll(map<string, Person> phoneBook);
3. Поиск и вывод определенного человека - void FindSomebody(map<string, Person> phoneBook);
4. Изменение данных определенного человека - void ChangeSomebody(map<string, Person> phoneBook);
5. Импорт новых человеков из файла (расширение csv) - void ImportFromFile(map<string, Person>& phoneBook);
6. Експорт всех человеков в файл (расширение csv) - void ExportToFile(map<string, Person>& phoneBook);
7. Где-то там должно быть удаление определенного человека - void DeletePerson(map<string, Person>& phoneBook).
