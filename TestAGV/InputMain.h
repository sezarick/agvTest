// InputMain.h

#ifndef _INPUTMAIN_h
#define _INPUTMAIN_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#include "Communicate.h"
#include <SoftwareSerial.h>

#else
	#include "WProgram.h"
#endif


class InputModule{

public:
	
	

private:

public:
		InputModule();
		~InputModule();

		String getInput();
private:
};

	


#endif

