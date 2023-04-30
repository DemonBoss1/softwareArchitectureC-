#include "main.h"
#include "duck.h"

class Turkey {
public:
	virtual void gobble() = 0;
	virtual void fly() = 0;
};
class WildTurkey :public Turkey {
public:
	void gobble()override {
		cout << "Gobble gobble" << endl;
	}
	void fly()override {
		cout << "I'm flying a short distance" << endl;
	}
};

class TurkeyAdapter :public Duck {
private:
	Turkey* turkey;
public:
	TurkeyAdapter(Turkey* turkey) {
		this->turkey = turkey;
	}
	void quack() {
		turkey->gobble();
	}
	void fly() {
		for (int i = 0; i < 5; i++)
			turkey->fly();
	}
};
class WildTurkeyAdapter :public Duck, public WildTurkey {
public:
	void quack() {
		gobble();
	}
	void fly() {
		for (int i = 0; i < 5; i++)
			WildTurkey::fly();
	}
};

void testEx8() {
	WildTurkey duck;
	TurkeyAdapter turkeyAdapter(&duck);
	WildTurkeyAdapter wildTurkeyAdapter;

	cout << "turkeyAdapter" << endl;
	turkeyAdapter.quack();
	turkeyAdapter.fly();

	cout << endl << endl << "wildTurkeyAdapter" << endl;
	wildTurkeyAdapter.quack();
	wildTurkeyAdapter.fly();

}