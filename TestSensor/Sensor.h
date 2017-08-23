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
	ReadLineSensor(int size, int* pin);	//라인센서 초기화 함수입니다. 핀 사이즈와, 핀 정보를 입력합니다
	~ReadLineSensor();

	LinkedList<int*>* getArray();		//리스트를 불러옵니다 10개까지 저장됩니다
	void setData();						//데이터를 센서로부터 1회 읽어옵니다. 


	int pinSize = 0;
	int* pinData;
	LinkedList<int*> *DataArray;
private:
};



#endif

