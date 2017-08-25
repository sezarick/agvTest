// 
// 
// 

#include "AGVBody.h"

AGVBody::AGVBody() {
	computeModule = new ComputeModule();
	inputModule = new InputModule();
}

AGVBody::~AGVBody() {
	if (computeModule) delete computeModule;
	if (inputModule) delete inputModule;
}


void AGVBody::Progress() {
	//char c = NULL;
	//if (Serial.available() > 0) {
	//	c = Serial.read();
	//}
	//computeModule->inputCheck(String(c));
	computeModule->inputCheck(String(inputModule->getInput()));
}
