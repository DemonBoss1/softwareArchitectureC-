#include "main.h"

class Employee;

class Unit {
public:
	virtual int getPersonCount() = 0;
};

class Department: public Unit{
private:
	string name;
	list <Employee*> employees;
public:
	Department(string name) {
		this->name = name;
	}
	void setName(string newName) {
		name = newName;
	}
	string getName() {
		return name;
	} 
	void addEmployee(Employee* newEmployee) { employees.push_back(newEmployee); }
	list<Employee*> getEmployees() {
		return employees;
	}
	void removeEmployee(Employee * e) {};
	~Department() {

	}
	int getPersonCount() override {
		return employees.size();
	}
};

class PastPosition {
private:
	string name;
	Department* department;
public:
	PastPosition(string position, Department* dep) {
		name = position;
		department = dep;
	}
	~PastPosition() {

	}
	void setName(string newName) {
		name = newName;
	}
	string getName() { return name; };
	void setDepartment(Department* d) { department = d; };
	Department* getDepartment() { return department; };
	bool operator ==(const PastPosition& other) {
		return this->name == other.name && this->department == other.department;
	}
};

class Room {
private:
	int number;
public:
	Room(int n) {
		number = n;
	}
	~Room() {};
	void setNumber(int newNumber) { number = newNumber; };
	int getNumber() { return number; };
};

class IdCart {
private:
	int number;
	string dateExpire;
public:
	IdCart(int n) {
		number = n;
	}
	~IdCart() {};
	void setNumber(int newNumber) { number = newNumber; };
	int getNumber() { return number; };
	void setDateExpire(string d) { dateExpire = d; };
	string getDateExpire() { return dateExpire; };
};

class Man {
protected:
	string name;
	string surname;
public:
	void setName(string newName) { name = newName; };
	string getName() { return name; };
	void setSurname(string newSurname) { surname = newSurname; };
	string getSurname() { return surname; };
};

class Employee : public Man {
private:
	string position;
	IdCart* cart;
	list<Room*> room;
	Department* department;
	list<PastPosition> pastPosition;
public:
	Employee(string n, string s, string p) {
		this->name = n;
		this->surname = s;
		this->position = p;
	}
	~Employee() {
		this->department->removeEmployee(this);
	}
	void setPosition(string newPosition) { position = newPosition; };
	string getPosition() { return position; };
	void setIdCart(IdCart* newIdCart) { cart = newIdCart; };
	IdCart* getIdCart() { return cart; };
	void setRoom(Room* newRoom) { room.push_back(newRoom); };
	list<Room*> getRoom() { return room; };
	void deleteRoom(Room* r) { room.erase(find(room.begin(), room.end(), r)); };
	void setDepartment(Department* d) { department = d; };
	Department* getDepartment() { return department; };
	void setPastPosition(PastPosition p) { pastPosition.push_back(p); };
	list<PastPosition> getPastPosition() { return pastPosition; };
	void deletePastPosition(PastPosition p) { pastPosition.erase(find(pastPosition.begin(), pastPosition.end(), p)); };
};

class Menu {
public:
	static void showEmployees(Employee* employees) {
		cout << employees->getName() << " " << employees->getSurname() << " " << employees->getPosition() << endl;
		if (employees->getIdCart()!=nullptr)
			cout << "Номер карты: " << employees->getIdCart()->getNumber() << endl;
		list<Room*> r = employees->getRoom();
		for (list<Room*>::iterator it = r.begin(); it != r.end(); ++it) {
			if (it == r.begin())
				cout << "Комнаты в которых работает сотрудник" << endl;
			cout << (*it)->getNumber() << endl;
		}
		cout << "Работает в отделе: " << employees->getDepartment()->getName() << endl;
		list<PastPosition> p = employees->getPastPosition();
		for (list<PastPosition>::iterator it = p.begin(); it != p.end(); ++it) {
			if (it == p.begin())
				cout << "Предыдущие места работы" << endl;
			cout << it->getDepartment()->getName() << "\t" << it->getName() << endl;
		}
		cout << endl;
	};
};

void testEx1() {
	Department* itDepartment = new Department("It department");
	Department* legalDepartment = new Department("Legal department");
	Employee* person1 = new Employee("Ivan", "Ivanov", "Software engineer");
	person1->setIdCart(new IdCart(123456));
	person1->setRoom(new Room(101));
	person1->setRoom(new Room(104));
	person1->setDepartment(itDepartment);
	person1->setPastPosition(PastPosition("Copywriter", legalDepartment));
	person1->setPastPosition(PastPosition("Programmer", itDepartment));
	itDepartment->addEmployee(person1);
	Employee* person2 = new Employee("Федор", "Козырев", "Software engineer");
	person2->setDepartment(itDepartment);
	itDepartment->addEmployee(person2);
	Menu::showEmployees(person1);
	Menu::showEmployees(person2);
	delete itDepartment;
	delete legalDepartment;
	delete person1;
	delete person2;

}