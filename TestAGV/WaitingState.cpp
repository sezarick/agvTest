// 
// 
// 

#include "WaitingState.h"


void WaitingState::executeCommand(CommandType comm) {
	switch (comm)
	{
	case CommandType::STOP:
		Stop();
		break;
	case CommandType::SIGNAL_WAITING:
		Stop();
		break;
	default:
		break;
	}
}

void WaitingStatePassive::Stop() {
	Serial.println("Stop");
	analogWrite(pinPwmR, 0);
	digitalWrite(pinDirR, LOW);
	analogWrite(pinPwmL, 0);
	digitalWrite(pinDirL, HIGH);
}

void WaitingStateAuto::Stop() {
	Serial.println("Stop");
	analogWrite(pinPwmR, 0);
	digitalWrite(pinDirR, LOW);
	analogWrite(pinPwmL, 0);
	digitalWrite(pinDirL, HIGH);

}