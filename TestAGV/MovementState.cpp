// 
// 
// 

#include "MovementState.h"


//명령어에 따른 실행부
void Movement::executeCommand(CommandType comm) {
	switch (comm)
	{
	case CommandType::STOP:
		Stop();
		
		break;
	case CommandType::SIGNAL_WAITING:
		Stop();
		break;
	case CommandType::STRAIGHT_GO:
		StraightGo();
		break;
	case CommandType::TURN_RIGHT:
		TurnRight();
		break;
	case CommandType::TURN_LEFT:
		TurnLeft();
		break;
	case CommandType::BACK:
		BackWard();
		break;
	default:
		break;
	}
};


////////////////////////////////////
//수동 움직임 관련
////////////////////////////////////

void MovementPassive::Stop() {
	Serial.println("Stop");
	analogWrite(pinPwmR, 0);
	digitalWrite(pinDirR, LOW);
	analogWrite(pinPwmL, 0);
	digitalWrite(pinDirL, HIGH);
}

void MovementPassive::StraightGo() {
	//수동 직진
	Serial.println("Straghit Go");
	analogWrite(pinPwmR, speed_L);
	digitalWrite(pinDirR, LOW);
	analogWrite(pinPwmL, speed_R);
	digitalWrite(pinDirL, HIGH);
}

void MovementPassive::TurnLeft() {
	//수동 좌회전
	Serial.println("Turn Left");
	analogWrite(pinPwmR, speed_L);
	digitalWrite(pinDirR, LOW);
	analogWrite(pinPwmL, speed_R);
	digitalWrite(pinDirL, LOW);
}

void MovementPassive::TurnRight() {
	//수동 우회전
	Serial.println("Turn Right");
	analogWrite(pinPwmR, speed_L);
	digitalWrite(pinDirR, HIGH);
	analogWrite(pinPwmL, speed_R);
	digitalWrite(pinDirL, HIGH);
}

void MovementPassive::BackWard() {
	//수동 후진
	Serial.println("BackWard");
	analogWrite(pinPwmR, iSpeed1);
	digitalWrite(pinDirR, HIGH);
	analogWrite(pinPwmL, iSpeed2);
	digitalWrite(pinDirL, LOW);
}



///////////////////////////////////
//자동 움직임 관련
///////////////////////////////////

void MovementAuto::Stop() {

}

void MovementAuto::StraightGo() {
	//자동 직진
	Serial.println("aSG");
}

void MovementAuto::TurnLeft() {
	//자동 좌회전
	Serial.println("aTL");
}

void MovementAuto::TurnRight() {
	//자동 우회전
	Serial.println("aTR");
}

void MovementAuto::BackWard() {
	//자동 후진
	Serial.println("aBW");
}