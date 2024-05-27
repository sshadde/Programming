#include<iostream>
#include<list>
int main()
{
	std::list<int> nums = { 52, 0, 520, 5200, 1941, 1812, 1917, 1685, 69 };
	auto iter = find(nums.begin(), nums.end(), 0);
	if (iter != nums.begin() and iter != nums.end())
	{
		nums.insert(iter, 111);
		nums.insert(iter, 222);
	}
	for (int n : nums)
	{
		std::cout << n << "\n";
	}
}