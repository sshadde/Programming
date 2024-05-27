#include<iostream>
class Time {
public:
	Time(int m, int s);
	void set_minutes(int m);
	void set_seconds(int s);
	void get_minutes();
	void get_seconds();
	void get_overall_seconds();
	void info();
private:
	int minutes;
	int seconds;
};