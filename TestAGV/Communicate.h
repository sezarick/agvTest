// Communicate.h

#ifndef _COMMUNICATE_h
#define _COMMUNICATE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#include <QueueList.h>
#include <StackList.h>
#include <LinkedList.h>
#else
	#include "WProgram.h"
#endif


class CommunicateModuel {

};


//�ڵ� ��� �϶��� (pager) Ȱ��
class RFModule : public CommunicateModuel {
public:
	String buffData;

	void ReadRFData();

private:

};

//�нú� �϶��� ��ü ���� �� Ȱ��
class BTModule : public CommunicateModuel {
public:
	String buffData, currentData;

	void ReadBTData();

private:
	
};

#endif

