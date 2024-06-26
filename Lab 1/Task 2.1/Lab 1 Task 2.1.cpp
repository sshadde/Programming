﻿#include<iostream>
#include<queue>
void enqueue(std::queue<float>& Q, float x)
{
	Q.push(x);
}
void dequeue(std::queue<float>& Q)
{
	Q.pop();
}
void display(std::queue<float>& Q)
{
	std::queue<float> tmpQ = Q;
	while (!tmpQ.empty())
	{
		std::cout << tmpQ.front() << "\n";
		tmpQ.pop();
	}
}
float summary(std::queue<float>& Q)
{
	std::queue<float> tmpQ = Q;
	float sum = 0;
	while (!tmpQ.empty())
	{
		sum += tmpQ.front();
		tmpQ.pop();
	}
	return sum;
}
int main()
{
	std::queue<float> Q;
	enqueue(Q, 2.1);
	enqueue(Q, 2.1);
	enqueue(Q, 5.3);
	std::cout << "Original queue:\n";
	display(Q);
	dequeue(Q);
	enqueue(Q, 4.9);
	std::cout << "\nModified queue:\n";
	display(Q);
	std::cout << "\nSummary:\n" << summary(Q);
}