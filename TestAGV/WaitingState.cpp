// 
// 
// 

#include "WaitingState.h"


void WaitingState::executeCommand(CommandType comm) {
	switch (comm)
	{
	case CommandType::STOP:
		break;
	case CommandType::SIGNAL_WAITING:
		break;
	case CommandType::STRAIGHT_GO:
		break;
	case CommandType::TURN_RIGHT:
		break;
	case CommandType::TURN_LEFT:
		break;
	case CommandType::BACK:
		break;
	default:
		break;
	}
}