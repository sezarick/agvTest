// CommandModule.h

#ifndef _COMMANDMODULE_h
#define _COMMANDMODULE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	#include "AGVState.h"
	#include "MovementState.h"
	#include "WaitingState.h"
#include <StackList.h>

#else
	#include "WProgram.h"
#endif



enum class ConditionType {
	NOTHING,
	TIMESET,	
	MEET_BRANCH,
	MEET_ENDPOINT,
	MEET_NFCPOINT,
	NEW_INPUT
};


class Command {

private:
	CommandType command;
	ConditionType condition;

public:
	Command(){}
	Command(CommandType comm, ConditionType con) : command(comm), condition(con){ }
	~Command(){}

	void setCommand(CommandType comm, ConditionType con) { command = comm; condition = con; }
	CommandType getCommand() { return command; }
	ConditionType getCondition() { return condition; }
	bool Command::Equals(Command comm) {
		if (command == comm.command && condition == comm.condition) {
			return true;
		}
		else {
			return false;
		}
	}

};

class Route {


};


class CommandModule {
public:

	
private:

	

public:
	CommandModule();
	~CommandModule();


private:

};



#endif

