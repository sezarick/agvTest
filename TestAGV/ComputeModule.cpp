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

//상태변경하는 함수
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

	//여기서 이제 컨디션 상황에 따라서 인풋 상태를 체크하고 명령을 수행해야 할지 체크
	if (currentCommand->getCondition() == calculateCommand(inputStrings)) {
		//컨디션 조건이 맞으면 여기서 실행 - 현재 상태도 같이 체크해야함
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
		//컨디션 조건 충족 안됬을 경우
		Serial.println("NO");
	}

	agvCommExe(currentCommand->getCommand()); //명령 실행 함수
}




ConditionType ComputeModule::calculateCommand(String input) {
	//인풋 파싱 부분
	ConditionType conType = ConditionType::NEW_INPUT;
	if (input == "A") {
		conType = ConditionType::NEW_INPUT;
	}
	else if (input == "B") {
		conType = ConditionType::TIMESET;
	}
	//여기서 해석해서 컨디션 반환해야댐
	return conType;
}


