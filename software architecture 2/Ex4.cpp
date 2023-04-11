#include "main.h"

class Beverage {
protected:
	string description = "Unknow Beverage";
	double price;
public:
	virtual string getDescription() {
		return description;
	}
	virtual double cost() = 0;
};
class HouseBlend:public Beverage {
public:
	HouseBlend() {
		description = "HouseBlend";
		price = 0.89;
	}
	void setPrice(double price) {
		this->price = price;
	}
	double getPrice() {
		return price;
	}
	double cost()override {
		return price;
	}
};
class DarkRoast :public Beverage {
public:
	DarkRoast() {
		description = "DarkRoast";
		price = 0.99;
	}
	void setPrice(double price) {
		this->price = price;
	}
	double getPrice() {
		return price;
	}
	double cost()override {
		return price;
	}
};
class Espresso :public Beverage {
public:
	Espresso() {
		description = "Espresso";
		price = 1.99;
	}
	void setPrice(double price) {
		this->price = price;
	}
	double getPrice() {
		return price;
	}
	double cost()override {
		return price;
	}
};
class Decaf:public Beverage{
public:
	Decaf() {
		description = "Decaf";
		price = 1.05;
	}
	void SetPrice(double price) {
		this->price = price;
	}
	double GetPrice() {
		return price;
	}
	double cost()override {
		return price;
	}
};
class CondimentDecorator :public Beverage {
protected:
	Beverage* beverage;
public:
	virtual string getDescription()override = 0;
};
class Milk :public CondimentDecorator {
public:
	Milk(Beverage* beverage) {
		this->beverage = beverage;
		price = 0.10;
	}
	string getDescription()override {
		return beverage->getDescription() + ", Milk";
	}
	double cost()override {
		return beverage->cost() + price;
	}
};
class Mocha :public CondimentDecorator {
public:
	Mocha(Beverage* beverage) {
		this->beverage = beverage;
		price = 0.20;
	}
	string getDescription()override {
		return beverage->getDescription() + ", Mocha";
	}
	double cost()override {
		return beverage->cost() + price;
	}
};
class Soy :public CondimentDecorator {
public:
	Soy(Beverage* beverage) {
		this->beverage = beverage;
		price = .15;
	}
	string getDescription()override {
		return beverage->getDescription() + ", Soy";
	}
	double cost()override {
		return beverage->cost() + price;
	}
};
class Whip :public CondimentDecorator {
public:
	Whip(Beverage* beverage) {
		this->beverage = beverage;
		price = .10;
	}
	string getDescription()override {
		return beverage->getDescription() + ", Whip";
	}
	double cost()override {
		return beverage->cost() + price;
	}
};

void testEx4() {
	Beverage* coffee = new Whip(new Soy(new Mocha(new Mocha(new Milk(new Espresso)))));
	cout << coffee->getDescription() << endl << coffee->cost() << endl;
	delete coffee;
}