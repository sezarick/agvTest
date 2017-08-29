// AGVBody.h

#ifndef _AGVBODY_h
#define _AGVBODY_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#include "ComputeModule.h"
#else
	#include "WProgram.h"
#endif



class AGVBody {
	
public:
	AGVBody();
	~AGVBody();
	
	void Progress();
	static int myDegree;
	static String currentLocation;
private:
	ComputeModule* computeModule = NULL;
	InputModule* inputModule = NULL;
};

#endif

