#include <iostream>
#include <map>
#include <string>

using namespace std;

// Структура для хранения информации о книге
struct Book {
    string author; // Фамилия и инициалы автора книги
    string title;  // Название книги
    int year;      // Год издания книги
    int copies;    // Количество экземпляров книги в библиотеке

    // Конструктор
    Book(string author, string title, int year, int copies) : author(author), title(title), year(year), copies(copies) {}
};

// Функция для вывода информации о книге
void printBook(const Book& book) {
    cout << "Author: " << book.author << ", Title: " << book.title << ", Year: " << book.year << ", Copies: " << book.copies << endl;
}

int main() {
    // Мультимап для хранения книг, ключом является фамилия и инициалы автора
    multimap<string, Book> library;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Remove a book" << endl;
        cout << "3. Display books ordered by author" << endl;
        cout << "4. Display books ordered by year" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter author, title, year, and number of copies: ";
            string author, title;
            int year, copies;
            cin >> author >> title >> year >> copies;
            Book newBook(author, title, year, copies);
            library.insert(make_pair(author, newBook)); // Добавление книги в мультимап
            cout << "Book added successfully." << endl;
            break;
        }
        case 2: {
            cout << "Enter author and title of the book to remove: ";
            string author, title;
            cin >> author >> title;
            auto range = library.equal_range(author); // Поиск всех книг автора
            for (auto it = range.first; it != range.second; ++it) {
                if (it->second.title == title) {
                    library.erase(it); // Удаление книги
                    cout << "Book removed successfully." << endl;
                    break;
                }
            }
            break;
        }
        case 3: {
            cout << "Books ordered by author:" << endl;
            for (const auto& pair : library) { // Перебор книг в мультимапе
                printBook(pair.second); // Вывод информации о книге
            }
            break;
        }
        case 4: {
            cout << "Books ordered by year:" << endl;
            multimap<int, string> tempMap;
            for (const auto& pair : library) { // Перебор книг в мультимапе
                tempMap.insert(make_pair(pair.second.year, pair.second.author)); // Добавление во временную мультимапу для сортировки по годам
            }
            for (const auto& pair : tempMap) { // Перебор отсортированных данных из временной мультимапы
                auto range = library.equal_range(pair.second); // Поиск всех книг автора
                for (auto it = range.first; it != range.second; ++it) {
                    printBook(it->second); // Вывод информации о книге
                }
            }
            break;
        }
        case 5:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    }

    return 0;
}
