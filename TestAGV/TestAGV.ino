/*
 Name:		TestAGV.ino
 Created:	8/9/2017 12:31:38 PM
 Author:	smsong
*/

// the setup function runs once when you press reset or power the board


//#include <StackArray.h>


#include <LinkedList.h>
#include <SoftwareSerial.h>
#include "MapData.h"
#include "CommandModule.h"
#include "ComputeModule.h"
#include "Communicate.h"
#include "AGVBody.h"
#include <MsTimer2.h>

AGVBody agvBody;


void setup() {
	Serial.begin(9600);

	Serial.println("InitSuccess");

	AGVBody::myDegree = 0;
	AGVBody::currentLocation = "BASE";

}

// the loop function runs over and over again until power down or reset
void loop() {
	//agvBody.Progress();

	Serial.println("ready");
	delay(3000);

}
	