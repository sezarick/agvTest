// 
// 
// 

#include "InputMain.h"


InputModule::InputModule() {
	BtModule = new BTModule();
}

InputModule::~InputModule() {
	if (BtModule) delete BtModule;
}

char InputModule::getInput() {
	return BtModule->ReadBTData();
}