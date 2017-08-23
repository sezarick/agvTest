// WaitingState.h

#ifndef _WAITINGSTATE_h
#define _WAITINGSTATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	#include "AGVState.h"
#else
	#include "WProgram.h"
#endif

class WaitingState : public State {
public:
	virtual void executeCommand(CommandType comm) override;

private:
};

class WaitingStatePassive : public WaitingState {
public:

private:

};

class WaitingStateAuto : public WaitingState {
public:

private:

};
#endif

