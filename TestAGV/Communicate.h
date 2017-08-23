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




//�нú� �϶��� ��ü ���� �� Ȱ��
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


//�ڵ� ��� �϶��� (pager) Ȱ��
class RFModule : public CommunicateModuel {
public:
	String buffData;

	void ReadRFData();

private:

};

#endif

