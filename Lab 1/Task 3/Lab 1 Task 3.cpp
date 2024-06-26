﻿#include<iostream>
#include<queue>
int main()
{
	std::queue<int> q1, q2;
	for (int i = 1; i <= 10; i++)
	{
		if (i % 2 != 0)
		{
			q1.push(i);
		}
		if (i % 2 == 0)
		{
			q2.push(i);
		}
	}
	int* q1ptrFront = &q1.front();
	int* q1ptrBack = &q1.back();
	std::cout << "Pointer to the first Q1 element: " << *q1ptrFront;
	std::cout << "\nPointer to the last Q1 element: " << *q1ptrBack;
	int* q2ptrFront = &q2.front();
	int* q2ptrBack = &q2.back();
	std::cout << "\nPointer to the first Q2 element: " << *q2ptrFront;
	std::cout << "\nPointer to the last Q2 element: " << *q2ptrBack;
}