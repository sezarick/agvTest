// MapData.h

#ifndef _MAPDATA_h
#define _MAPDATA_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#include <LinkedList.h>
#include <StackList.h>
#else
	#include "WProgram.h"
#endif

enum class PositionState {
	BRANCH,
	ENDPOINT,
	ROAD,
	BASE,
	ETC
};

class linkedInfo {
public:
	linkedInfo(int startDeg, NodeData* node): degree(startDeg), nodeData(node) {}

private:
	int degree;
	NodeData* nodeData;
};

class NodeData {
public:
	NodeData(String, PositionState);
	~NodeData();

	bool setlinkedNode(linkedInfo* link) { linkedNode->add(*link); }

private:
	String name;
	PositionState pState;
	LinkedList<linkedInfo> *linkedNode;	
};


class MapData {
public:
	MapData();
	~MapData();

private:
	LinkedList<NodeData> *nodes;

	void InitializeNode();
	void InitializeLink();
};
#endif

