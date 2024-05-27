﻿#include<iostream>
#include<list>
int main() {
	std::list<int> nums = { -3, -2, -1, 0, 1, 2, 3 };
	for (auto iter = nums.begin(); iter != nums.end(); iter++) {
		if (*iter > 0) {
			nums.insert(iter, *iter);
			break;
		}
	}
	for (int n : nums) {
		std::cout << n << "\n";
	}
}