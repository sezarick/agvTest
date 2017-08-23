// Sensor.h

#ifndef _SENSOR_h
#define _SENSOR_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#include <LinkedList.h>
#else
	#include "WProgram.h"
#endif

class SensorModule {

};


class ReadLineSensor : public SensorModule {
public:
	ReadLineSensor() {}
	ReadLineSensor(int size, int* pin);	//���μ��� �ʱ�ȭ �Լ��Դϴ�. �� �������, �� ������ �Է��մϴ�
	~ReadLineSensor();

	LinkedList<int*>* getArray();		//����Ʈ�� �ҷ��ɴϴ� 10������ ����˴ϴ�
	void setData();						//�����͸� �����κ��� 1ȸ �о�ɴϴ�. 


	int pinSize = 0;
	int* pinData;
	LinkedList<int*> *DataArray;
private:
};



#endif

