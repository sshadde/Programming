﻿#include<iostream>
#include<fstream>
int main() {
	std::ifstream a("a.txt");
	int n, count = 0, sum = 0;
	while (a >> n) {
		if (n > 0) {
			sum += n;
			count++;
		}
	}
	std::cout << "Quantity of positives: " << count << "\n" << "Summary of positives: " << sum << "\n";
	a.close();
}