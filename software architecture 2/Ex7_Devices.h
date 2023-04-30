#ifndef EX7_DEVICES_H
#define EX7_DEVICES_H

#include "main.h"

class CeilingFan {
private:
	string location;
	int speed;
public:
	static int HIGH;
	static int MEDIUM;
	static int LOW;
	static int OFF;
	CeilingFan(string location) {
		this->location = location;
	}
	void high() {
		speed = HIGH;
		cout << location << " ceiling fan is on high" << endl;
	}
	void medium() {
		speed = MEDIUM;
		cout << location << " ceiling fan is on medium" << endl;
	}
	void low() {
		speed = LOW;
		cout << location << " ceiling fan is on low" << endl;
	}
	void off() {
		speed = OFF;
		cout << location << " ceiling fan is off" << endl;
	}
	int getSpeed() {
		return speed;
	}
};
int CeilingFan::HIGH = 3;
int CeilingFan::MEDIUM = 2;
int CeilingFan::LOW = 1;
int CeilingFan::OFF = 0;

class Light {
private:
	string location;
public:
	Light(string location) {
		this->location = location;
	}
	void on() {
		cout << "Light is on" << endl;
	}
	void off() {
		cout << "Light is off" << endl;
	}
};
#endif // !