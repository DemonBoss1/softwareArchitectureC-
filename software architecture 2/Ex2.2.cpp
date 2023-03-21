#include "main.h"

class WeaponBehavior {
public:
	virtual void useWeapon() = 0;
};
class KnifeBehavior :public WeaponBehavior {
public:
	void useWeapon() override {
		cout << "Knife attack" << endl;
	}
};
class BowAndArrowBehavior :public WeaponBehavior {
public:
	void useWeapon() override {
		cout << "Archery" << endl;
	}
};
class AxeBehavior :public WeaponBehavior {
	void useWeapon() override {
		cout << "Axe attack" << endl;
	}
};
class SwordBehavior :public WeaponBehavior {
	void useWeapon() override {
		cout << "Sword attack" << endl;
	}
};
class Character {
public:
	WeaponBehavior* weaponBehavior;
	virtual void fight() = 0;
	void setWeapon(WeaponBehavior* w) {
		this->weaponBehavior = w;
	}
};
class Queen :public Character {
public:
	Queen() {
		weaponBehavior = new KnifeBehavior();
	}
	void fight() override {
		cout << "Queen" << endl;
		weaponBehavior->useWeapon();
	}
};
class King :public Character {
public:
	King() {
		weaponBehavior = new KnifeBehavior();
	}
	void fight() override {
		cout << "King" << endl;
		weaponBehavior->useWeapon();
	}
};
class Troll :public Character {
public:
	Troll() {
		weaponBehavior = new AxeBehavior();
	}
	void fight() override {
		cout << "Troll" << endl;
		weaponBehavior->useWeapon();
	}
};
class Knight :public Character {
public:
	Knight() {
		weaponBehavior = new SwordBehavior();
	}
	void fight() override {
		cout << "Knight" << endl;
		weaponBehavior->useWeapon();
	}
};
void testEx2_2() {
	Queen* queen = new Queen();
	King* king = new King();
	Troll* troll = new Troll();
	Knight* knight = new Knight();
	queen->fight();
	king->fight();
	troll->fight();
	knight->fight();
	knight->setWeapon(new BowAndArrowBehavior());
	knight->fight();
	delete queen;
	delete king;
	delete troll;
	delete knight;

}