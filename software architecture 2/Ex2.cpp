#include "main.h"

class QuackBehavior {
public:
	virtual void quack() = 0;
};
class Quack :public QuackBehavior{
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
class MallardDuck :public Duck {
public:
	MallardDuck() {
		quackBehavior = new Quack();
		flyBehavioor = new FlyWithWings();
	}
	void display() override {
		cout << "display MallardDuck" << endl;
		this->performQuack();
		this->performFly();
	}
};
class RedHeadDuck :public Duck {
public:
	RedHeadDuck() {
		quackBehavior = new Quack();
		flyBehavioor = new FlyWithWings();
	}
	void display() override {
		cout << "display RedHeadDuck" << endl;
		this->performQuack();
		this->performFly();
	}
};
class RubberDuck :public Duck {
public:
	RubberDuck() {
		quackBehavior = new Squeck();
		flyBehavioor = new FlyNoWay();
	}
};
class DecoyDuck :public Duck {
public:
	DecoyDuck() {
		quackBehavior = new Quack();
		flyBehavioor = new FlyNoWay();
	}
};
void testEx2() {
	MallardDuck* mallardDuck = new MallardDuck();
	RedHeadDuck* redHeadDuck = new RedHeadDuck();
	RubberDuck* rubberDuck = new RubberDuck();
	DecoyDuck* decoyDuck = new DecoyDuck();
	mallardDuck->display();
	cout << endl;
	redHeadDuck->display();
	cout << endl;
	rubberDuck->display();
	cout << endl;
	decoyDuck->display();
	delete mallardDuck;
	delete redHeadDuck;
	delete rubberDuck;
	delete decoyDuck;
}