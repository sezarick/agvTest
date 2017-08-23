/*
 Name:		TestAGV.ino
 Created:	8/9/2017 12:31:38 PM
 Author:	smsong
*/

// the setup function runs once when you press reset or power the board


//#include <StackArray.h>


#include "MapData.h"
#include "CommandModule.h"
#include "ComputeModule.h"
#include <StackList.h>
#include <QueueList.h>
#include <LinkedList.h>
#include "Communicate.h"
#include "AGVBody.h"
#include <MsTimer2.h>

AGVBody agvBody;

void setup() {
	
	Serial.begin(9600);

}

// the loop function runs over and over again until power down or reset
void loop() {
	agvBody.computeModule.inputCheck("A");
	agvBody.computeModule.inputCheck("B");
}
	