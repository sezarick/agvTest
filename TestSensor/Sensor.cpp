// 
// 
// 

#include "Sensor.h"


ReadLineSensor::ReadLineSensor(int size, int* pin) {
	pinSize = size;
	pinData = pin;
	DataArray = new LinkedList<int*>();
}

ReadLineSensor::~ReadLineSensor() {
	DataArray->~LinkedList();
}

void ReadLineSensor::setData() {
	Serial.println("nofitting");
	int* readData = new int[pinSize];
	for (int i = 0; i < pinSize; i++) {
		readData[i] = digitalRead(pinData[i]);
	}

	DataArray->add(readData);
	if (DataArray->size() > 10) {
		DataArray->remove(0);
	}
}

LinkedList<int*>* ReadLineSensor::getArray() {

	return DataArray;
}