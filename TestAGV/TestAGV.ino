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

	LinkedList<String> temp = LinkedList<String>();

	temp.add("0");
	temp.add("1");
	temp.add("2");
	temp.add("3");
	temp.add("4");

	for (int i = 0; i < temp.size(); i++) {
		Serial.println(temp.get(i));
	}

	temp.remove(0);

	for (int i = 0; i < temp.size(); i++) {
		Serial.println(temp.get(i));
	}
}

// the loop function runs over and over again until power down or reset
void loop() {
	//agvBody.Progress();

	Serial.println("ready");
	delay(3000);

}
	