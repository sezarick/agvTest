// 
// 
// 

#include "MapData.h"


NodeData::NodeData() {

}

NodeData::NodeData(String nodeName, PositionState nodeState) {


	name = nodeName;
	pState = nodeState;
}

NodeData::~NodeData() {

}

void NodeData::setlinkedNode(linkedInfo link) {

	linkedData.add(link);
}


MapData::MapData() {

}

MapData::~MapData() {
	nodeData.~LinkedList();
}

void MapData::InitializeNode() {
	NodeData A("A", PositionState::ENDPOINT);
	nodeData.add(A);
	NodeData B("B", PositionState::ENDPOINT);
	nodeData.add(B);
	NodeData C("IC", PositionState::ENDPOINT);
	nodeData.add(C);
	NodeData D("BASE", PositionState::ENDPOINT);
	nodeData.add(D);
	InitializeLink();
}

void MapData::InitializeLink() {
	NodeData temp[4];
	temp[0] = nodeData.get(0);
	temp[1] = nodeData.get(1);
	temp[2] = nodeData.get(2);
	temp[3] = nodeData.get(3);
	linkedInfo lines[4];
	lines[0] = linkedInfo(0, &temp[3]);
	lines[1] = linkedInfo(90, &temp[2]);
	lines[2] = linkedInfo(180, &temp[1]);
	lines[3] = linkedInfo(270, &temp[0]);

	for (int i = 0; i < 4; i++) {
		temp[i].setlinkedNode(lines[i]);
	}


	for (int i = 0; i < 4; i++) {
		Serial.println(temp[i].getName() + " start");
		Serial.println(temp[i].getlinkedData(0).getnodeData()->getName() + " arrive");
	}


}

