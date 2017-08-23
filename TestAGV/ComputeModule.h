// ComputeModule.h

#ifndef _COMPUTEMODULE_h
#define _COMPUTEMODULE_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
	#include "CommandModule.h"
#include "InputMain.h"
#else
	#include "WProgram.h"
#endif

enum class StateType {
	WAITINGPASSIVE,
	WAITINGAUTO,
	MOVEMENTPASSIVE,
	MOVEMENTAUTO
};

class ComputeModule{
public:
	
private:
	StackList<Command> *commandList = NULL;
	AGVState *agvState = NULL;
	Command *currentCommand = NULL;
	InputModule *inputModule = NULL;

	StateType currentState;
	String currentInput;

public:
	ComputeModule();
	~ComputeModule();
	
	void inputCheck(String);		//인풋이 바뀌면 명령 내려주기 위함 - 이녀석내부에서 계속 인풋을 통한걸 체크
	StateType getState() { return currentState; }

private:

	ConditionType calculateCommand(String input);
	void exeCommand(String);
	void setagvState(StateType type);
	void agvCommExe(CommandType comm) { if(currentCommand) agvState->Execute(comm); }
};


#endif

