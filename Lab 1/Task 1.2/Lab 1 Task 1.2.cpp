#include <iostream>
#include <string>
#include <stack>
using namespace std;
struct Book
{
    string title;
    double price;
};
void push(stack<Book>& booksStack, double& totalprice, int& count, const string& title, double price)
{
    Book book;
    book.title = title;
    book.price = price;
    booksStack.push(book);
    totalprice += price;
    count++;
}
void display(const stack<Book>& booksStack)
{
    cout << "Books in stack:" << endl;
    stack<Book> tmpStack = booksStack;
    while (!tmpStack.empty())
    {
        Book book = tmpStack.top();
        cout << "Title: " << book.title << ", Price: " << book.price << endl;
        tmpStack.pop();
    }
}
double avgprice(double totalprice, int count)
{
    if (count == 0)
    {
        return 0;
    }
    return totalprice / count;
}

int main()
{
    stack<Book> booksStack;
    double totalprice = 0;
    int count = 0;
    push(booksStack, totalprice, count, "Book 1", 15.99);
    push(booksStack, totalprice, count, "Book 2", 12.50);
    push(booksStack, totalprice, count, "Book 3", 20.00);
    display(booksStack);
    double average = avgprice(totalprice, count);
    cout << "Average price of books: " << average << endl;
}