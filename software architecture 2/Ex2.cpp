#include "main.h"
#include "duck.h"

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