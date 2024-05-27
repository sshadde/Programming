#include <iostream>
#include <vector>
#include <stdexcept>

// Объявление и реализация шаблонного класса Stack
template<typename T>
class Stack {
private:
    std::vector<T> elements; // Вектор для хранения элементов стека

public:
    // Добавление элемента в стек
    void push(const T& element) {
        elements.push_back(element);
    }

    // Удаление верхнего элемента стека
    void pop() {
        if (elements.empty()) { // Проверка на пустоту стека
            std::cerr << "Error: Stack<>::pop(): empty stack" << std::endl; // Вывод ошибки, если стек пуст
            exit(1); // Выход из программы
        }
        elements.pop_back(); // Удаление верхнего элемента
    }

    // Получение ссылки на верхний элемент стека
    T& top() {
        if (elements.empty()) { // Проверка на пустоту стека
            std::cerr << "Error: Stack<>::top(): empty stack" << std::endl; // Вывод ошибки, если стек пуст
            exit(1); // Выход из программы
        }
        return elements.back(); // Возврат верхнего элемента
    }

    // Получение константной ссылки на верхний элемент стека
    const T& top() const {
        if (elements.empty()) { // Проверка на пустоту стека
            std::cerr << "Error: Stack<>::top(): empty stack" << std::endl; // Вывод ошибки, если стек пуст
            exit(1); // Выход из программы
        }
        return elements.back(); // Возврат верхнего элемента
    }

    // Проверка на пустоту стека
    bool empty() const {
        return elements.empty();
    }

    // Получение размера стека
    size_t size() const {
        return elements.size();
    }
};

// Функция main, основная точка входа в программу
int main() {
    // Пример использования стека для типа int
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    std::cout << "Top element of intStack: " << intStack.top() << std::endl;
    intStack.pop();
    std::cout << "Top element of intStack after pop: " << intStack.top() << std::endl;
    intStack.pop();
    std::cout << "intStack size after pop: " << intStack.size() << std::endl;

    // Пример использования стека для типа double
    Stack<double> doubleStack;
    doubleStack.push(1.1);
    doubleStack.push(2.2);
    std::cout << "Top element of doubleStack: " << doubleStack.top() << std::endl;
    while (!doubleStack.empty()) {
        doubleStack.pop();
    }
    // Пытаемся обратиться к top на пустом стеке
    doubleStack.top();

    // Пример использования стека для типа std::string
    Stack<std::string> stringStack;
    stringStack.push("Hello");
    stringStack.push("World");
    std::cout << "Top element of stringStack: " << stringStack.top() << std::endl;
    stringStack.pop();
    stringStack.pop();
    // Пытаемся pop пустого стека
    stringStack.pop();

    return 0; // Возврат из функции main, завершение программы
}
