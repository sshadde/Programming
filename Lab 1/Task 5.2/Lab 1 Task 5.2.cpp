﻿#include<iostream>
#include<list>
int main() {
	std::list<int> nums = { -3, -2, -1, 0, 3, 5, 9, 15, 16, 15, 178 };
	for (auto iter = nums.begin(); iter != nums.end(); iter++) {
		if (*iter > 4) {
			nums.erase(iter);
			break;
		}

	}
	for (auto iter = nums.begin(); iter != nums.end(); iter++) {
		if (*iter == 15) {
			nums.insert(iter, 10);
			iter++;
		}
	}
	for (int n : nums) {
		std::cout << n << "\n";
	}
}