// 
// 
// 

#include "ComputeModule.h"


ComputeModule::ComputeModule() {
	commandList = new StackList<Command>();
	agvState = new AGVState(new WaitingStatePassive());
	currentState = StateType::WAITINGPASSIVE;
	currentCommand = new Command(CommandType::SIGNAL_WAITING, ConditionType::NEW_INPUT);
	inputModule = new InputModule();
}

ComputeModule::~ComputeModule() {
	commandList->~StackList();
	if (agvState) delete agvState;
	if (currentCommand) delete currentCommand;
	if (inputModule) delete inputModule;
}

//���º����ϴ� �Լ�
void ComputeModule::setagvState(StateType type) {
	switch (type)
	{
	case StateType::WAITINGPASSIVE:
		agvState->setState(new WaitingStatePassive());
		currentState = StateType::WAITINGPASSIVE;
		break;
	case StateType::WAITINGAUTO:
		agvState->setState(new WaitingStateAuto());
		currentState = StateType::WAITINGAUTO;
		break;
	case StateType::MOVEMENTPASSIVE:
		agvState->setState(new MovementPassive());
		currentState = StateType::MOVEMENTPASSIVE;
		break;
	case StateType::MOVEMENTAUTO:
		agvState->setState(new MovementAuto());
		currentState = StateType::MOVEMENTAUTO;
		break;
	default:
		break;
	}
}

void ComputeModule::inputCheck(String inputString) {

	//���⼭ ���� ����� ��Ȳ�� ���� ��ǲ ���¸� üũ�ϰ� ����� �����ؾ� ���� üũ
	if (currentCommand->getCondition() == calculateCommand(inputString)) {
		//����� ������ ������ ���⼭ ���� - ���� ���µ� ���� üũ�ؾ���
		switch (currentCommand->getCondition())
		{
		case ConditionType::NOTHING:
			break;
		case ConditionType::MEET_BRANCH:
			break;
		case ConditionType::MEET_ENDPOINT:
			break;
		case ConditionType::MEET_NFCPOINT:
			break;
		case ConditionType::NEW_INPUT:
			exeCommand(inputString);
			break;
		case ConditionType::TIMESET:
			break;
		default:
			break;
		}
	}
	else {
		//����� ���� ���� �ȉ��� ���
	}
	
}

ConditionType ComputeModule::calculateCommand(String input) {
	//��ǲ �Ľ� �κ�
	ConditionType conType = ConditionType::NOTHING;

	if (input == NULL) {
		conType = ConditionType::NOTHING;
	}
	else {
		conType = ConditionType::NEW_INPUT;
	}
	//���⼭ �ؼ��ؼ� ����� ��ȯ�ؾߴ�
	return conType;
}

void ComputeModule::exeCommand(String inputString) {

	CommandType comT = CommandType::SIGNAL_WAITING;
	ConditionType conT = ConditionType::NEW_INPUT;

	if (inputString.equals("A")) {
		setagvState(StateType::WAITINGAUTO);
		comT = CommandType::STOP;
		Serial.println("change to watitingauto");
	}
	else if (inputString.equals("S")) {
		setagvState(StateType::MOVEMENTPASSIVE);
		comT = CommandType::STOP;
		Serial.println("change to watitingpassive");
	}
	else{
		if (currentState == StateType::WAITINGPASSIVE || currentState == StateType::MOVEMENTPASSIVE) {
			if (inputString.equals("U")) {
				setagvState(StateType::MOVEMENTPASSIVE);
				comT = CommandType::STRAIGHT_GO;
			}
			else if (inputString.equals("D")) {
				setagvState(StateType::MOVEMENTPASSIVE);
				comT = CommandType::BACK;
			}
			else if (inputString.equals("L")) {
				setagvState(StateType::MOVEMENTPASSIVE);
				comT = CommandType::TURN_LEFT;
			}
			else if (inputString.equals("R")) {
				setagvState(StateType::MOVEMENTPASSIVE);
				comT = CommandType::TURN_RIGHT;
			}
		}
	}

	currentCommand->setCommand(comT, conT);
	agvCommExe(currentCommand->getCommand()); //��� ���� �Լ�
}
