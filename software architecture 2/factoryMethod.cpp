#include "main.h"

namespace factoryMethod {
	class Pizza {
		friend class PizzaStore;
	protected:
		string name;
		string dough;
		string sauce;
		vector<string> toppings;
		virtual void prepare() {
			cout << "Preparinng " << name << endl;
			cout << "Tossing dough..." << endl;
			cout << "Adding sauce..." << endl;
			cout << "Adding toppings: " << endl;
			for (string it : toppings)
				cout << "\t" << it << endl;
		}
		virtual void bake() {
			cout << "Bake for 25 minutes at 350" << endl;
		}
		virtual void cut() {
			cout << "Cutting the pizza into diagonal slices" << endl;
		}
		virtual void box() {
			cout << "Place pizza in official PizzaStore box" << endl;
		}
	public:
		string getName() {
			return name;
		}
	};
	class NYStyleCheesePizza :public Pizza {
	public:
		NYStyleCheesePizza() {
			name = "NY Style Sauce and Cheese Pizza";
			dough = "Thin Crust Dough";
			sauce = "Marinara Sauce";
			toppings.push_back("Grated Reggiano Cheese");
		}
	};
	class NYStylePepperoniPizza :public Pizza {
	public:
		NYStylePepperoniPizza() {
			name = "NY Style Pepperoni Pizza";
			dough = "Thin Crust Dough";
			sauce = "Marinara Sauce";
			toppings.push_back("Grated Reggiano Cheese");
			toppings.push_back("Sliced Pepperoni");
			toppings.push_back("Garlic");
			toppings.push_back("Onion");
			toppings.push_back("Mushrooms");
			toppings.push_back("Red Pepper");
		}
	};
	class NYStyleClamPizza :public Pizza {
	public:
		NYStyleClamPizza() {
			name = "NY Style Clam Pizza";
			dough = "Thin Crust Dough";
			sauce = "Marinara Sauce";
			toppings.push_back("Grated Reggiano Cheese");
			toppings.push_back("Fresh Clams from Long Island Sound");
		}
	};
	class NYStyleVeggiePizza :public Pizza {
	public:
		NYStyleVeggiePizza() {
			name = "NY Style Veggie Pizza";
			dough = "Thin Crust Dough";
			sauce = "Marinara Sauce";
			toppings.push_back("Grated Reggiano Cheese");
			toppings.push_back("Garlic");
			toppings.push_back("Onion");
			toppings.push_back("Mushrooms");
			toppings.push_back("Red Pepper");
		}
	};
	class ChicagoStyleCheesePizza :public Pizza {
	public:
		ChicagoStyleCheesePizza() {
			name = "Chicago Style Deep Dish Cheese Pizza";
			dough = "Extra Thick Crust Dough";
			sauce = "Plum Tomato Sauce";
			toppings.push_back("Shredded Mozzarella Cheese");
		}
		void cut()override {
			cout << "Cutting the pizza into square slices" << endl;
		}
	};
	class ChicagoStylePepperoniPizza :public Pizza {
	public:
		ChicagoStylePepperoniPizza() {
			name = "Chicago Style Pepperoni Pizza";
			dough = "Extra Thick Crust Dough";
			sauce = "Plum Tomato Sauce";
			toppings.push_back("Shredded Mozzarella Cheese");
			toppings.push_back("Black Olives");
			toppings.push_back("Spinach");
			toppings.push_back("Eggplant");
			toppings.push_back("Sliced Pepperoni");
		}
		void cut() {
			cout << "Cutting the pizza into square slices" << endl;
		}
	};
	class ChicagoStyleClamPizza :public Pizza {
	public:
		ChicagoStyleClamPizza() {
			name = "Chicago Style Clam Pizza";
			dough = "Extra Thick Crust Dough";
			sauce = "Plum Tomato Sauce";
			toppings.push_back("Shredded Mozzarella Cheese");
			toppings.push_back("Frozen Clams from Chesapeake Bay");
		}
		void cut() {
			cout << "Cutting the pizza into square slices" << endl;
		}
	};
	class ChicagoStyleVeggiePizza :public Pizza {
	public:
		ChicagoStyleVeggiePizza() {
			name = "Chicago Deep Dish Veggie Pizza";
			dough = "Extra Thick Crust Dough";
			sauce = "Plum Tomato Sauce";
			toppings.push_back("Shredded Mozzarella Cheese");
			toppings.push_back("Black Olives");
			toppings.push_back("Spinach");
			toppings.push_back("Eggplant");
		}
		void cut() {
			cout << "Cutting the pizza into square slices" << endl;
		}
	};
	class PizzaStore {
	public:
		Pizza* orderPizza(string type) {
			Pizza* pizza;
			pizza = createPizza(type);
			pizza->prepare();
			pizza->bake();
			pizza->cut();
			pizza->box();

			return pizza;
		}
	protected:
		virtual Pizza* createPizza(string type) = 0;
	};
	class ChicagoPizzaStore :public PizzaStore {
	public:
		Pizza* createPizza(string type)override {
			if (type == "cheese") {
				return new ChicagoStyleCheesePizza;
			}
			else if (type == "pepperoni") {
				return new ChicagoStylePepperoniPizza;
			}
			else if (type == "clam") {
				return new ChicagoStyleClamPizza;
			}
			else if (type == "veggie") {
				return new ChicagoStyleVeggiePizza;
			}
		}
	};
	class NYPizzaStore :public PizzaStore {
	public:
		Pizza* createPizza(string type)override {
			if (type == "cheese") {
				return new NYStyleCheesePizza;
			}
			else if (type == "pepperoni") {
				return new NYStylePepperoniPizza;
			}
			else if (type == "clam") {
				return new NYStyleClamPizza;
			}
			else if (type == "veggie") {
				return new NYStyleVeggiePizza;
			}
		}
	};
	void testEx5() {
		shared_ptr<NYPizzaStore> nyPizzaStore(new NYPizzaStore);
		shared_ptr<Pizza> pizzaNY(nyPizzaStore->orderPizza("cheese"));
		cout << "Ethon ordered a " << pizzaNY->getName() << endl << endl;
		shared_ptr<ChicagoPizzaStore> chicagoPizzaStore(new ChicagoPizzaStore);
		shared_ptr<Pizza> pizzaChicago(chicagoPizzaStore->orderPizza("cheese"));
		cout << "Joel ordered a " << pizzaChicago->getName() << endl << endl;
	}
}