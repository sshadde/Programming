﻿#include<iostream>
#include<stack>
#include<string>
void push(std::stack<std::string>& Q, std::string x)
{
	Q.push(x);
}
void pop(std::stack<std::string>& Q)
{
	Q.pop();
}
void display(std::stack<std::string>& Q)
{
	std::stack<std::string> tmpQ = Q;
	while (!tmpQ.empty())
	{
		std::cout << tmpQ.top() << "\n";
		tmpQ.pop();
	}
}
void words(std::stack<std::string>& Q)
{
	std::stack<std::string> tmpQ = Q;
	std::cout << "2-symbol words:\n";
	while (!tmpQ.empty())
	{
		if (tmpQ.top().size() == 2)
		{
			std::cout << tmpQ.top() << "\n";
		}
		tmpQ.pop();
	}
}
int main()
{
	std::stack<std::string> Q;
	push(Q, "Students");
	push(Q, "of");
	push(Q, "the");
	push(Q, "group");
	push(Q, "TE");
	push(Q, "3");
	display(Q);
	std::cout << "\n";
	pop(Q);
	display(Q);
	std::cout << "\n";
	words(Q);
}