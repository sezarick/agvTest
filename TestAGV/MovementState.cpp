// 
// 
// 

#include "MovementState.h"


//��ɾ ���� �����
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
//���� ������ ����
////////////////////////////////////

void MovementPassive::Stop() {
	Serial.println("Stop");
	analogWrite(pinPwmR, 0);
	digitalWrite(pinDirR, LOW);
	analogWrite(pinPwmL, 0);
	digitalWrite(pinDirL, HIGH);
}

void MovementPassive::StraightGo() {
	//���� ����
	Serial.println("Straghit Go");
	analogWrite(pinPwmR, speed_L);
	digitalWrite(pinDirR, LOW);
	analogWrite(pinPwmL, speed_R);
	digitalWrite(pinDirL, HIGH);
}

void MovementPassive::TurnLeft() {
	//���� ��ȸ��
	Serial.println("Turn Left");
	analogWrite(pinPwmR, speed_L);
	digitalWrite(pinDirR, LOW);
	analogWrite(pinPwmL, speed_R);
	digitalWrite(pinDirL, LOW);
}

void MovementPassive::TurnRight() {
	//���� ��ȸ��
	Serial.println("Turn Right");
	analogWrite(pinPwmR, speed_L);
	digitalWrite(pinDirR, HIGH);
	analogWrite(pinPwmL, speed_R);
	digitalWrite(pinDirL, HIGH);
}

void MovementPassive::BackWard() {
	//���� ����
	Serial.println("BackWard");
	analogWrite(pinPwmR, iSpeed1);
	digitalWrite(pinDirR, HIGH);
	analogWrite(pinPwmL, iSpeed2);
	digitalWrite(pinDirL, LOW);
}



///////////////////////////////////
//�ڵ� ������ ����
///////////////////////////////////

void MovementAuto::Stop() {

}

void MovementAuto::StraightGo() {
	//�ڵ� ����
	Serial.println("aSG");
}

void MovementAuto::TurnLeft() {
	//�ڵ� ��ȸ��
	Serial.println("aTL");
}

void MovementAuto::TurnRight() {
	//�ڵ� ��ȸ��
	Serial.println("aTR");
}

void MovementAuto::BackWard() {
	//�ڵ� ����
	Serial.println("aBW");
}