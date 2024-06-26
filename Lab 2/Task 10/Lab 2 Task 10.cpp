﻿#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
struct PurchaseInfo {
    string name;
    string date;
    double totalCostFirstHalf;
    double totalCostSecondHalf;
    double discountPercent;
};
void printPurchaseInfo(const PurchaseInfo& purchase) {
    cout << "Покупатель: " << purchase.name << endl;
    cout << "Дата покупки: " << purchase.date << endl;
    cout << "Общая стоимость за первое полугодие: " << purchase.totalCostFirstHalf << " руб." << endl;
    cout << "Общая стоимость за второе полугодие: " << purchase.totalCostSecondHalf << " руб." << endl;
    cout << "Начальный процент скидки: " << purchase.discountPercent << "%" << endl << endl;
}

int main() {
    setlocale(LC_ALL, "Rus");
    vector<PurchaseInfo> purchases = {
        {"Иванов И.И.", "01.01.2024", 8000.0, 12000.0, 5.0},
        {"Петров П.П.", "15.01.2024", 15000.0, 8000.0, 7.0}
    };
    ofstream outFile("purchases.bin", ios::binary);
    for (const auto& purchase : purchases) {
        outFile.write((char*)&purchase, sizeof(PurchaseInfo));
    }
    outFile.close();
    ifstream inFile("purchases.bin", ios::binary);
    PurchaseInfo tempPurchase;
    while (inFile.read((char*)&tempPurchase, sizeof(PurchaseInfo))) {
        if (tempPurchase.totalCostFirstHalf >= 10000.0 && tempPurchase.totalCostSecondHalf >= 10000.0) {
            tempPurchase.discountPercent += 7.0;
        }
        printPurchaseInfo(tempPurchase);
    }
    inFile.close();
}