#include<iostream>
#include"Header.h"
Time::Time(int h, int m, int s) {
	hours = h;
	minutes = m;
	seconds = s;
}
Time::~Time() {
	std::cout << "Object destroyed." << std::endl;
}
void Time::set_hours(int h) {
	hours = h;
}
void Time::set_minutes(int m) {
	minutes = m;
}
void Time::set_seconds(int s) {
	seconds = s;
}
void Time::get_hours() {
	std::cout << "Hours: " << hours << "\n";
}
void Time::get_minutes() {
	std::cout << "Minutes: " << minutes << "\n";
}
void Time::get_seconds() {
	std::cout << "Seconds: " << seconds << "\n";
}
int Time::get_overall_seconds() {
	int overall = hours * 3600 + minutes * 60 + seconds;
	return overall;
}
void Time::add_minutes(int m) {
	if (minutes + m < 60) {
		minutes + m;
	}
	if (minutes + m == 60) {
		hours++;
		minutes = 0;
	}
	if (minutes + m > 60) {
		hours += (minutes + m) / 60;
		minutes = (minutes + m) % 60;
	}
	std::cout << "Minutes added.\n";
}
void Time::time_from_midnight(int overall) {
	int day = 86400, ost;
	int temp_s, temp_m, temp_h;
	ost = day - overall;
	temp_s = ost % 60;
	temp_m = ost % 3600 / 60;
	temp_h = ost % 86400 / 3600;
	std::cout << "Remaining untill midnight: \n" << "Hours: " << temp_h << "\t" << "Minutes: " << temp_m << "\t" << "Seconds: " << temp_s << "\n\n";
}
void Time::info() {
	std::cout << "Hours: " << hours << "\t" << "Minutes: " << minutes << "\t" << "Seconds: " << seconds << "\n\n";
}
int main() {
	Time time = { 10, 23, 36 };
	time.info();
	time.time_from_midnight(time.get_overall_seconds());
	time.add_minutes(100);
	time.info();
}