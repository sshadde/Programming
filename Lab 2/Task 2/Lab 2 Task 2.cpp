﻿#include<iostream>
#include<fstream>
int main() {
	std::ifstream a1("a1.txt");
	std::ifstream a2("a2.txt");
	int n1, n2;
	int num, count = 0;
	while (a1 >> num) {
		if (num == 0) {
			count++;
		}
	}
	while (a2 >> num) {
		if (num == 0) {
			count++;
		}
	}
	std::cout << "Quantity of zeroes: " << count << "\n";
	a1.close();
	a2.close();
}