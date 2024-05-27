#include <iostream>
#include <fstream>
#include <cctype> // Для использования функции isdigit()
int main() {
    setlocale(LC_ALL, "Rus");
    std::ifstream input("input.txt");
    std::ofstream output("output.txt");
    char ch;
    while (input.get(ch)) {
        if (std::isdigit(ch)) {
            output.put('*');
        }
        else {
            output.put(ch);
        }
    }
    std::cout << "Цифры в файле были заменены на '*'.\n";
    input.close();
    output.close();;
}