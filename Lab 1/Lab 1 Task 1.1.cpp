#include<iostream>
#include<stack>
using namespace std;
void display(stack<int>& s1)
{
	stack<int> tmpS = s1;
	cout << "Stack: " << "\n";
	while (!tmpS.empty())
	{
		cout << tmpS.top() << "\n";
		tmpS.pop();
	}
}
int main()
{
	stack<int> s1, s_max;
	s1.push(3);
	if (s_max.empty() or s_max.top() < s1.top())
	{
		s_max.push(3);
	}
	s1.push(1);
	if (s_max.top() < s1.top())
	{
		s_max.push(1);
	}
	s1.push(9);
	if (s_max.top() < s1.top())
	{
		s_max.push(9);
	}
	s1.push(4);
	if (s_max.top() < s1.top())
	{
		s_max.push(4);
	}
	cout << "Max element: " << s_max.top() << "\n";
	display(s1);
}