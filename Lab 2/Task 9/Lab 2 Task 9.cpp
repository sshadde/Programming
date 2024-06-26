﻿#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
void writeToFile(const std::string& filename, const std::vector<char>& data) {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        file.write(data.data(), data.size());
        file.close();
    }
}
std::vector<char> readFromFile(const std::string& filename) {
    std::vector<char> data;
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {
        char ch;
        while (file.get(ch)) {
            data.push_back(ch);
        }
        file.close();
    }
    return data;
}
std::string toUpperCase(const std::string& str) {
    std::string upperCaseStr = str;
    std::transform(upperCaseStr.begin(), upperCaseStr.end(), upperCaseStr.begin(), ::toupper);
    return upperCaseStr;
}
int main() {
    setlocale(LC_ALL, "Rus");
    std::string inputText;
    std::cout << "Введите текст: ";
    std::getline(std::cin, inputText);
    std::vector<char> data(inputText.begin(), inputText.end());
    writeToFile("data.bin", data);
    std::cout << "Текст записан в файл." << std::endl;
    std::vector<char> dataFromFile = readFromFile("data.bin");
    std::string textFromFile(dataFromFile.begin(), dataFromFile.end());
    std::string upperCaseText = toUpperCase(textFromFile);
    std::cout << "Символы до изменения данных в файле: " << textFromFile << std::endl;
    std::cout << "Символы после изменения данных в файле: " << upperCaseText << std::endl;
}