// Communicate.h

#ifndef _COMMUNICATE_h
#define _COMMUNICATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#include <QueueList.h>
#include <StackList.h>
#include <LinkedList.h>
#include <SoftwareSerial.h>
#else
	#include "WProgram.h"
#endif


class CommunicateModuel {

};




//패시브 일때만 객체 생성 및 활동
class BTModule : public CommunicateModuel {
public:
	BTModule();
	~BTModule();
	char ReadBTData();

private:
	String buffData, currentData;
	char buffChar, currentChar;
	SoftwareSerial* BTSerial = NULL;
};


//자동 모드 일때만 (pager) 활동
class RFModule : public CommunicateModuel {
public:
	String buffData;

	void ReadRFData();

private:

};

#endif

