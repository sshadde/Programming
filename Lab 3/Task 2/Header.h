#include<iostream>
class Time {
public:
	Time(int h, int m, int s);
	~Time();
	void set_hours(int h);
	void set_minutes(int m);
	void set_seconds(int s);
	void get_hours();
	void get_minutes();
	void get_seconds();
	int get_overall_seconds();
	void time_from_midnight(int overall);
	void info();
	void add_minutes(int m);
private:
	int hours;
	int minutes;
	int seconds;
};