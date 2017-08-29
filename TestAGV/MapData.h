// MapData.h

#ifndef _MAPDATA_h
#define _MAPDATA_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#include <LinkedList.h>

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
class NodeData;
class linkedInfo;

class linkedInfo {
public:
	linkedInfo() {}
	~linkedInfo() {}
	linkedInfo(int startDeg, NodeData* node) { degree = startDeg; nodeData = node; }
public:
	int getDegree() { return degree; }
	NodeData* getnodeData() { return nodeData; }

private:
	int degree;
	NodeData* nodeData;
	
};


class NodeData {
public:
	NodeData();
	NodeData(String, PositionState);
	~NodeData();

	void setlinkedNode(linkedInfo);


public:
	String getName() { return name; }
	PositionState getState() { return pState; }
	linkedInfo getlinkedData(int index) { if(linkedData.size() > index) return linkedData.get(index); }

private:
	String name;
	PositionState pState;
	LinkedList<linkedInfo> linkedData = LinkedList<linkedInfo>();
};


class MapData {
public:
	MapData();
	~MapData();
	void InitializeNode();

private:

	void InitializeLink();
	LinkedList<NodeData> nodeData;

};
#endif

