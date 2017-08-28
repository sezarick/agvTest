// InputMain.h

#ifndef _INPUTMAIN_h
#define _INPUTMAIN_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#include "Communicate.h"


#else
	#include "WProgram.h"
#endif


class InputModule{
public:
		InputModule();
		~InputModule();

		char getInput();
private:

public:
private:
	BTModule* BtModule;
};

	


#endif

