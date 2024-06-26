﻿#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct TV {
    string firmName;
    float screenSize;
    float cost;
};
void writeTV(ofstream& outFile, const TV& tv) {
    size_t firmNameLength = tv.firmName.size();
    outFile.write((char*)&firmNameLength, sizeof(firmNameLength));
    outFile.write(tv.firmName.data(), firmNameLength);
    outFile.write((char*)&tv.screenSize, sizeof(tv.screenSize));
    outFile.write((char*)&tv.cost, sizeof(tv.cost));
}
void readTV(ifstream& inFile, TV& tv) {
    size_t firmNameLength;
    inFile.read((char*)&firmNameLength, sizeof(firmNameLength));
    char buffer[256];
    inFile.read(buffer, firmNameLength);
    buffer[firmNameLength] = '\0';
    tv.firmName = string(buffer);
    inFile.read((char*)&tv.screenSize, sizeof(tv.screenSize));
    inFile.read((char*)&tv.cost, sizeof(tv.cost));
}

int main() {
    setlocale(LC_ALL, "Rus");
    ofstream outFile("TVs.bin", ios::binary);
    TV tv1 = { "Samsung", 40, 500 };
    TV tv2 = { "LG", 32, 400 };
    TV tv3 = { "Sony", 45, 600 };
    TV tv4 = { "Samsung", 55, 800 };
    writeTV(outFile, tv1);
    writeTV(outFile, tv2);
    writeTV(outFile, tv3);
    writeTV(outFile, tv4);
    outFile.close();
    ifstream inFile("TVs.bin", ios::binary);
    TV tv;
    int samsungTVsCount = 0;
    while (!inFile.eof()) {
        readTV(inFile, tv);
        if (!inFile.eof() && tv.firmName == "Samsung" && tv.screenSize > 32.0) {
            cout << "Фирма: " << tv.firmName << endl;
            cout << "Размер по диагонали: " << tv.screenSize << " дюймов" << endl;
            cout << "Стоимость: $" << tv.cost << endl << endl;
            samsungTVsCount++;
        }
    }
    cout << "Количество телевизоров фирмы Samsung с размером более 32 дюймов: " << samsungTVsCount << endl;
    inFile.close();
}