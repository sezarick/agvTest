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
	virtual void Stop() = 0;
};

class WaitingStatePassive : public WaitingState {
public:
	WaitingStatePassive() {
		pinMode(pinPwmR, OUTPUT);
		pinMode(pinDirR, OUTPUT);
		pinMode(pinPwmL, OUTPUT);
		pinMode(pinDirL, OUTPUT);
	}
private:
	virtual void Stop() override;

private:
	int pinPwmR = 6;
	int pinPwmL = 5;
	int pinDirR = 7;
	int pinDirL = 4;
};

class WaitingStateAuto : public WaitingState {
public:
	WaitingStateAuto() {
		pinMode(pinPwmR, OUTPUT);
		pinMode(pinDirR, OUTPUT);
		pinMode(pinPwmL, OUTPUT);
		pinMode(pinDirL, OUTPUT);
	}
private:
	virtual void Stop() override;

private:
	int pinPwmR = 6;
	int pinPwmL = 5;
	int pinDirR = 7;
	int pinDirL = 4;
};
#endif

