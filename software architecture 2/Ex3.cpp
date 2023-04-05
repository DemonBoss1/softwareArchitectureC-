#include "main.h"

class Observer {
public:
	virtual void update(float temperature, float humidity, float pressure) = 0;
};

class Displayer {
public:
	virtual void display() = 0;
};

class Subject {
public:
	virtual void registerObserver(Observer* observer) = 0;
	virtual void remoteObserver(Observer* observer) = 0;
	virtual void notifyObserver() = 0;
};

class WeatherData :public Subject {
private:
	list<Observer*>* observers;

	float temperature;
	float humidity;
	float pressure;

	void notifyObserver()override {
		for (list<Observer*>::iterator it = observers->begin(); it != observers->end(); it++) {
			(*it)->update(temperature, humidity, pressure);
		}
	}

	void measurementsChanged() {
		notifyObserver();
	}

public:
	WeatherData() {
		observers = new list<Observer*>;
	}
	~WeatherData() {
		delete observers;
	}
	void registerObserver(Observer* observer)override {
		observers->push_front(observer);
	}
	void remoteObserver(Observer* observer)override {
		list<Observer*>::iterator it = find(observers->begin(), observers->end(), observer);
		observers->erase(it);
	}
	void setMeasurements(float temperature, float humidity, float pressure) {
		this->temperature = temperature;
		this->humidity = humidity;
		this->pressure = pressure;
		measurementsChanged();
	}

};
class CurentConditionDisplay :public Observer, Displayer {
private:
	Subject* weatherData;
	float temperature;
	float humidity;
public:
	CurentConditionDisplay(Subject* weatherData) {
		this->weatherData = weatherData;
		this->weatherData->registerObserver(this);
	}
	void update(float temperature, float humidity, float pressure)override {
		this->temperature = temperature;
		this->humidity = humidity;
		display();
	}
	void display()override {
		cout << "Current conditions : " << temperature << "F degrees and " << humidity << " % humidity" << endl;
	}
};
class ForecastDisplay :public Observer, Displayer {
private:
	Subject* weatherData;
	float currentPressure = 29.92f;
	float lastPressure;
public:
	ForecastDisplay(Subject* weatherData) {
		this->weatherData = weatherData;
		this->weatherData->registerObserver(this);
	}
	void update(float temperature, float humidity, float pressure)override {
		lastPressure = currentPressure;
		currentPressure = pressure;
		display();
	}
	void display()override {
		cout << "Forecast: ";
		if (currentPressure > lastPressure) {
			cout << "Improving weather on the way!";
		}
		else if (currentPressure == lastPressure) {
			cout << "More of the same";
		}
		else if (currentPressure < lastPressure) {
			cout << "Watch out for cooler, rainy weather";
		}
		cout << endl;
	}
};
void testEx3() {
	WeatherData* weatherData = new WeatherData;

	CurentConditionDisplay curentConditionDisplay(weatherData);
	ForecastDisplay forecastDisplay(weatherData);

	weatherData->setMeasurements(80, 65, 30.4f);
	weatherData->setMeasurements(82, 70, 29.2f);
	weatherData->setMeasurements(78, 90, 29.2f);
}