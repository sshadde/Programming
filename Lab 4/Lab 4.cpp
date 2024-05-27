#include <iostream>
#include <cstring>

// Базовый класс для работы со строками
class String {
protected:
    char* data; // Данные строки
    int length; // Длина строки

public:
    String() : data(nullptr), length(0) {}

    // Конструктор для строки из символьного массива
    String(const char* str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy_s(data, length + 1, str);
    }

    // Конструктор для строки из одного символа
    String(char ch) : length(1) {
        data = new char[2];
        data[0] = ch;
        data[1] = '\0';
    }

    // Получение длины строки
    int getLength() const {
        return length;
    }

    // Получение данных строки
    const char* getData() const {
        return data;
    }

    // Деструктор для освобождения памяти
    ~String() {
        delete[] data;
    }
};

// Класс для работы с бинарными строками, наследуется от String
class BinaryString : public String {
public:
    BinaryString() : String("0") {}

    // Конструктор для бинарной строки
    BinaryString(const char* str) {
        length = strlen(str);
        data = new char[length + 1];
        int valid = 1;
        for (int i = 0; i < length; ++i) {
            if (str[i] != '0' && str[i] != '1') {
                valid = 0;
                break;
            }
        }
        if (valid) {
            strcpy_s(data, length + 1, str);
        }
        else {
            delete[] data;
            length = 1;
            data = new char[2];
            strcpy_s(data, 2, "0");
        }
    }

    // Метод для изменения знака первой цифры в бинарной строке
    void changeSign() {
        if (data[0] == '0') {
            data[0] = '1';
        }
        else {
            data[0] = '0';
        }
    }

    // Деструктор для освобождения памяти
    ~BinaryString() {
        // Базовый класс String очистится автоматически
    }
};

int main() {
    const int MAX_SIZE = 2;
    BinaryString* binaries[MAX_SIZE];

    binaries[0] = new BinaryString("1010");
    binaries[1] = new BinaryString("1100");

    for (int i = 0; i < MAX_SIZE; ++i) {
        std::cout << "Binary String " << i + 1 << ": ";
        std::cout << binaries[i]->getData() << std::endl;

        BinaryString copy(binaries[i]->getData());
        std::cout << "Copied Binary String: " << copy.getData() << std::endl;

        binaries[i]->changeSign();
        std::cout << "Changed Sign Binary String: " << binaries[i]->getData() << std::endl;

        delete binaries[i];
    }
}