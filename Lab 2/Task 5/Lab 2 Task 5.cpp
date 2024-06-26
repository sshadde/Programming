﻿#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

struct Owner {
    std::string surname;
    std::string name;
    std::string patronymic;
    std::string phone_number;
    std::string address;
    std::string car_brand;
    std::string car_number;
    std::string passport_number;
};

int main() {
    setlocale(LC_ALL, "Rus");
    std::ifstream input_file("owners.txt");
    std::ofstream output_file("vaz_owners.txt");
    std::vector<Owner> owners;
    std::string line;
    while (std::getline(input_file, line)) {
        std::stringstream ss(line);
        Owner owner;
        std::getline(ss, owner.surname, ';');
        std::getline(ss, owner.name, ';');
        std::getline(ss, owner.patronymic, ';');
        std::getline(ss, owner.phone_number, ';');
        std::getline(ss, owner.address, ';');
        std::getline(ss, owner.car_brand, ';');
        std::getline(ss, owner.car_number, ';');
        std::getline(ss, owner.passport_number, ';');
        if (owner.car_brand == "Ваз") {
            owners.push_back(owner);
        }
    }
    for (const auto& owner : owners) {
        output_file << owner.surname << "; " << owner.name << "; " << owner.patronymic << "; " << owner.phone_number << "; "
            << owner.address << "; " << owner.car_brand << "; " << owner.car_number << "; " << owner.passport_number << std::endl;
    }
    std::cout << "Информация о владельцах автомобилей марки 'Ваз' сохранена в файле 'vaz_owners.txt'." << std::endl;
    input_file.close();
    output_file.close();
    return 0;
}