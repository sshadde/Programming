﻿#include<iostream>
#include<fstream>
#include<vector>
int main() {
	std::vector<int> a;
	std::fstream input("input.txt");
	int n;
	while (input >> n) {
		a.push_back(n);
	}
	input.close();
	int sum = 0, count = 0;
	double avg;
	for (int i = 2; i < a.size(); i += 3) {
		sum += a[i];
		count++;
	}
	avg = sum / count;
	std::cout << "Average is: " << avg;
}