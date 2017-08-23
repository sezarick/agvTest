// Movement.h

#ifndef _MOVEMENT_h
#define _MOVEMENT_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	#include "stdarg.h"
#include "AGVState.h"
#else
	#include "WProgram.h"
#endif

class Movement : public State{
public:

	unsigned long iTime;

	virtual void executeCommand(CommandType comm) override;

public:
	virtual void Stop() = 0;
	virtual void StraightGo() = 0;
	virtual void TurnLeft() = 0;
	virtual void TurnRight() = 0;
	virtual void BackWard() = 0;
};


class MovementPassive : public Movement {
public:
	int iSpeed1 = 200, iSpeed2 = 200, speed_L = 200, speed_R = 200;
	int pinPwmR = 6;
	int pinPwmL = 5;
	int pinDirR = 7;
	int pinDirL = 4;
	MovementPassive() {
		pinMode(pinPwmR, OUTPUT);
		pinMode(pinDirR, OUTPUT);
		pinMode(pinPwmL, OUTPUT);
		pinMode(pinDirL, OUTPUT);
	}
private:
	virtual void Stop() override;
	virtual void StraightGo() override;
	virtual void TurnLeft() override;
	virtual void TurnRight() override;
	virtual void BackWard() override;
};

class MovementAuto : public Movement {

public:

private:
	virtual void Stop() override;
	virtual void StraightGo() override;
	virtual void TurnLeft() override;
	virtual void TurnRight() override;
	virtual void BackWard() override;
};
#endif

