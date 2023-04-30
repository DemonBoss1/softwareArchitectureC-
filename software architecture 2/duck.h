#pragma once
#include "main.h"

class QuackBehavior {
public:
	virtual void quack() = 0;
};
class Quack :public QuackBehavior {
public:
	void quack() override {
		cout << "Quack" << endl;
	}
};
class Squeck :public QuackBehavior {
public:
	void quack() override {
		cout << "Squeck" << endl;
	}
};
class MuteQuach :public QuackBehavior {
public:
	void quack() override {
		cout << "Mute" << endl;
	}
};
class FlyBehavior {
public:
	virtual void fly() = 0;
};
class FlyWithWings :public FlyBehavior {
public:
	void fly() override {
		cout << "fly" << endl;
	}
};
class FlyNoWay :public FlyBehavior {
public:
	void fly() override {
		cout << "no fly" << endl;
	}
};
class Duck {
protected:
	QuackBehavior* quackBehavior;
	FlyBehavior* flyBehavioor;
public:
	void performQuack() {
		quackBehavior->quack();
	}
	void performFly() {
		flyBehavioor->fly();
	}
	virtual void display() {
		this->performQuack();
		this->performFly();
	}
	void swim() {
		cout << "swin" << endl;
	}
};