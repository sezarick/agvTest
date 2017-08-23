// 
// 
// 

#include "Communicate.h"


BTModule::BTModule() {
	BTSerial = new SoftwareSerial(10, 11);
	BTSerial->begin(9600);
}

BTModule::~BTModule() {
	if (BTSerial) delete BTSerial;
}



char BTModule::ReadBTData() {
	
	if (BTSerial->available() > 0) {
		buffChar = BTSerial->read();
		if (currentChar != buffChar) {
			currentChar = buffChar;
			return currentChar;
		}
	}
	return NULL;
}



void RFModule::ReadRFData() {

}

