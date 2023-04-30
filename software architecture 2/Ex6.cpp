#include "main.h"

class ChocolateBoiler {
private:
	bool empty;
	bool boiled;
	ChocolateBoiler() {
		empty = true;
		boiled = false;
	}
	ChocolateBoiler(const ChocolateBoiler&);
	ChocolateBoiler& operator = (ChocolateBoiler& other) {
		return other;
	}
public:
	static ChocolateBoiler& getInstance() {
		static ChocolateBoiler instance;
		return instance;
	}
	bool isBoiled() {
		return boiled;
	}
	bool isEmpty() {
		return empty;
	}
	void fill() {
		if (isEmpty()) {
			empty = false;
			boiled = false;
			cout << "fill" << endl;
		}
	}
	void drain() {
		if (!isEmpty() && isBoiled()) {
			empty = true;
			cout << "drain" << endl;
		}
	}
	void boid() {
		if (!isEmpty() && !isBoiled()) {
			boiled = true;
			cout << "boid" << endl;
		}
	}
};
void testEx6() {
	ChocolateBoiler& boiler = ChocolateBoiler::getInstance();
	boiler.fill();

	ChocolateBoiler& boiler1 = ChocolateBoiler::getInstance();
	boiler1.drain();
	
	ChocolateBoiler& boiler2 = ChocolateBoiler::getInstance();
	boiler2.boid();
	
	ChocolateBoiler& boiler3 = ChocolateBoiler::getInstance();
	boiler3.drain();
	
	ChocolateBoiler& boiler4 = ChocolateBoiler::getInstance();
	boiler4.fill();

}
