﻿#include<iostream>
#include<list>
int main()
{
	std::list<int> nums = { 148, 52, 25, 55, 145, 2005, 33, 822, 69 };
	auto iter = find(nums.begin(), nums.end(), 55);
	if (iter != nums.begin() and iter != nums.end())
	{
		iter--;
		nums.erase(iter);
	}
	for (int n : nums)
	{
		std::cout << n << "\n";
	}
}