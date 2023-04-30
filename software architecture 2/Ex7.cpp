#include "main.h"
#include "Ex7_Devices.h"

class Command {
public:
	virtual void execute() = 0;
	virtual void undo() = 0;
};
class NoCommand :public Command {
public:
	void execute()override {}
	void undo()override {}
};
class CeilingFanCommand :public Command {
protected:
	CeilingFan* ceilingFan;
	int prevSpeed;
public:
	virtual void execute() = 0;
	void undo()override {
		if (prevSpeed == CeilingFan::HIGH) {
			ceilingFan->high();
		}
		else if (prevSpeed == CeilingFan::MEDIUM) {
			ceilingFan->medium();
		}
		else if (prevSpeed == CeilingFan::LOW) {
			ceilingFan->low();
		}
		else if (prevSpeed == CeilingFan::OFF) {
			ceilingFan->off();
		}
	}
};
class CeilingFanHighCommand :public CeilingFanCommand {
public:
	CeilingFanHighCommand(CeilingFan* ceilingFan) {
		this->ceilingFan = ceilingFan;
	}
	void execute()override {
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->high();
	}
};
class CeilingFanMediumCommand :public CeilingFanCommand {
public:
	CeilingFanMediumCommand(CeilingFan* ceilingFan) {
		this->ceilingFan = ceilingFan;
	}
	void execute()override {
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->medium();
	}
};
class CeilingFanLowCommand :public CeilingFanCommand {
public:
	CeilingFanLowCommand(CeilingFan* ceilingFan) {
		this->ceilingFan = ceilingFan;
	}
	void execute()override {
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->low();
	}
};
class CeilingFanOffCommand :public CeilingFanCommand {
public:
	CeilingFanOffCommand(CeilingFan* ceilingFan) {
		this->ceilingFan = ceilingFan;
	}
	void execute()override {
		prevSpeed = ceilingFan->getSpeed();
		ceilingFan->off();
	}
};
class LightOffCommand :public Command {
	Light* light;
public:
	LightOffCommand(Light* light) {
		this->light = light;
	}
	void execute()override {
		light->off();
	}
	void undo()override {
		light->on();
	}

};
class LightOnCommand :public Command {
	Light* light;
public:
	LightOnCommand(Light* light) {
		this->light = light;
	}
	void execute()override {
		light->on();
	}
	void undo()override {
		light->off();
	}

};
class RemoteControl {
private:
	Command** onCommands;
	Command** offCommands;
	Command* undoCommand;
	int size;
public:
	RemoteControl(int size) {
		this->size = size;
		onCommands = new Command * [size];
		offCommands = new Command * [size];
		shared_ptr<Command> noCommand(new NoCommand());
		for (int i = 0; i < size; i++) {
			onCommands[i] = noCommand.get();
			offCommands[i] = noCommand.get();
		}
		undoCommand = noCommand.get();
	}
	void setCommand(int slot, Command* onCommand, Command* offCommand) {
		if (slot >= size) return;
		onCommands[slot] = onCommand;
		offCommands[slot] = offCommand;
	}
	void onButtonWasPushed(int slot) {
		onCommands[slot]->execute();
		undoCommand = onCommands[slot];
	}
	void offButtonWasPushed(int slot) {
		offCommands[slot]->execute();
		undoCommand = offCommands[slot];
	}
	void undoButtonWasPushed() {
		undoCommand->undo();
	}
	string toString() {
		string str = "";
		str += "\n------ Remote Control -------\n";
		for (int i = 0; i < size; i++) {
			str += "[slot " + to_string(i) + "] " + typeid(onCommands[i]).name() + "    " + typeid(offCommands[i]).name() + "\n";
		}
		str += string("[undo] ") + typeid(undoCommand).name() + "\n";
		return str;
	}
	~RemoteControl() {
		delete onCommands;
		delete offCommands;
	}
};

void testEx7() {
	RemoteControl remoteControl(5);
	Light light("Living Room");
	LightOffCommand lightOff(&light);
	LightOnCommand lightOn(&light);
	CeilingFan ceilingFan("Living Room");
	CeilingFanHighCommand ceilingHigh(&ceilingFan);
	CeilingFanMediumCommand ceilingMedium(&ceilingFan);
	CeilingFanLowCommand ceilingLow(&ceilingFan);
	CeilingFanOffCommand ceilingOff(&ceilingFan);

	remoteControl.setCommand(0, &lightOn, &lightOff);
	remoteControl.setCommand(1, &ceilingLow, &ceilingOff);
	remoteControl.setCommand(2, &ceilingMedium, &ceilingOff);
	remoteControl.setCommand(3, &ceilingHigh, &ceilingOff);

	remoteControl.onButtonWasPushed(0);
	remoteControl.offButtonWasPushed(0);
	cout << endl;
	remoteControl.undoButtonWasPushed();
	remoteControl.offButtonWasPushed(0);
	remoteControl.onButtonWasPushed(0);
	cout << endl;
	remoteControl.undoButtonWasPushed();
	cout << endl;
	remoteControl.onButtonWasPushed(2);
	remoteControl.offButtonWasPushed(2);
	cout << endl;
	remoteControl.undoButtonWasPushed();
	remoteControl.onButtonWasPushed(3);
	cout << endl;
	remoteControl.undoButtonWasPushed();

}