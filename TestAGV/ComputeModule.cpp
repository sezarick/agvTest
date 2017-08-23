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

void ComputeModule::inputCheck(String inputStrings) {

	//���⼭ ���� ����� ��Ȳ�� ���� ��ǲ ���¸� üũ�ϰ� ����� �����ؾ� ���� üũ
	if (currentCommand->getCondition() == calculateCommand(inputStrings)) {
		//����� ������ ������ ���⼭ ���� - ���� ���µ� ���� üũ�ؾ���
		switch (currentCommand->getCondition())
		{
		case ConditionType::MEET_BRANCH:
			break;
		case ConditionType::MEET_ENDPOINT:
			break;
		case ConditionType::MEET_NFCPOINT:
			break;
		case ConditionType::NEW_INPUT:
			Serial.println("NEW_INPUT");
			break;
		case ConditionType::TIMESET:
			break;
		default:
			break;
		}
	}
	else {
		//����� ���� ���� �ȉ��� ���
		Serial.println("NO");
	}

	agvCommExe(currentCommand->getCommand()); //��� ���� �Լ�
}




ConditionType ComputeModule::calculateCommand(String input) {
	//��ǲ �Ľ� �κ�
	ConditionType conType = ConditionType::NEW_INPUT;
	if (input == "A") {
		conType = ConditionType::NEW_INPUT;
	}
	else if (input == "B") {
		conType = ConditionType::TIMESET;
	}
	//���⼭ �ؼ��ؼ� ����� ��ȯ�ؾߴ�
	return conType;
}


