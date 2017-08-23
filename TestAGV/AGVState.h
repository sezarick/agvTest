// AGVState.h

#ifndef _AGVSTATE_h
#define _AGVSTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

enum class CommandType {
	STOP,
	SIGNAL_WAITING,
	STRAIGHT_GO,
	TURN_RIGHT,
	TURN_LEFT,
	BACK
};

class State {



public:
	virtual void executeCommand(CommandType comm) = 0;


	
};


class AGVState {
private:
	CommandType comm = CommandType::STOP;
	State* pState;

public:
	AGVState(State* state) : pState(state) { }
	~AGVState() { if (pState) delete pState; }

	void setState(State* state) { if (pState) delete pState; pState = state; }
	void Execute(CommandType comm) { pState->executeCommand(comm); }
public:

	

};







#endif

