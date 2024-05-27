#include<iostream>
#include"Header.h"
Time::Time(int m, int s) {
	minutes = m;
	seconds = s;
}
void Time::set_minutes(int m) {
	minutes = m;
}
void Time::set_seconds(int s) {
	seconds = s;
}
void Time::get_minutes() {
	std::cout << "Minutes: " << minutes << "\n";
}
void Time::get_seconds() {
	std::cout << "Seconds: " << seconds << "\n";
}
void Time::get_overall_seconds() {
	int overall = minutes * 60 + seconds;
	std::cout << "Overall seconds value is: " << overall << "\n";
}
void Time::info() {
	std::cout << "Minutes: " << minutes << "\t" << "Seconds: " << seconds << "\n";
}
int main() {
	Time time = { 2, 30 };
	time.get_minutes();
	time.get_seconds();
	std::cout << "Uptading..." << "\n";
	time.set_minutes(40);
	time.set_seconds(50);
	time.get_minutes();
	time.get_seconds();
	time.info();
	time.get_overall_seconds();
}