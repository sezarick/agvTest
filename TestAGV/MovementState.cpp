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

}

void MovementPassive::StraightGo() {
	//���� ����
	Serial.println("pSG");
}

void MovementPassive::TurnLeft() {
	//���� ��ȸ��
	Serial.println("pTL");
}

void MovementPassive::TurnRight() {
	//���� ��ȸ��
	Serial.println("pTR");
}

void MovementPassive::BackWard() {
	//���� ����
	Serial.println("pBW");
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