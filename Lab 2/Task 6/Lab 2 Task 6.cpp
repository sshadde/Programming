﻿#include<iostream>
#include<fstream>
int main() {
	std::fstream input_file("f.txt");
	std::fstream output_file("f_result.txt");
	int num;
	int sum = 0;
	int sqrd = 1;
	while (input_file >> num) {
		sum += num;
		sqrd *= num;
	}
	sum = abs(sum);
	sqrd *= sqrd;
	output_file << sum;
	output_file << "\n";
	output_file << sqrd;
	input_file.close();
	output_file.close();
}