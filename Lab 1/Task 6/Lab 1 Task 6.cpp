﻿#include <iostream>
#include <list>
void duplicate(std::list<int>& nums) {
    auto P1 = nums.begin();
    while (P1 != nums.end()) {
        if (*P1 % 2 != 0) {
            P1 = nums.insert(P1, *P1);
            ++P1;
        }
        ++P1;
    }
}
void printList(const std::list<int>& nums) {
    for (int n : nums) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::list<int> nums = { 1, 2, 3, 4, 5 };
    std::cout << "Original list: ";
    printList(nums);
    duplicate(nums);
    std::cout << "Modified list: ";
    printList(nums);
}