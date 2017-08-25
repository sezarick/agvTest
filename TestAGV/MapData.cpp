// 
// 
// 

#include "MapData.h"


NodeData::NodeData(String nodeName, PositionState nodeState) {
	linkedNode = new LinkedList<linkedInfo>();
	
	name = nodeName;
	pState = nodeState;
}

NodeData::~NodeData() {
	if (linkedNode) delete linkedNode;
}




MapData::MapData() {

}

MapData::~MapData() {
	if (nodes->size > 0) nodes->clear();
}

void MapData::InitializeNode() {
	nodes = new LinkedList<NodeData>();

	NodeData A("A", PositionState::ENDPOINT);
	NodeData B("B", PositionState::ENDPOINT);
	NodeData C("Base", PositionState::BASE);
	NodeData D("IC", PositionState::BRANCH);

	nodes->add(A);
	nodes->add(B);
	nodes->add(C);
	nodes->add(D);
}

void MapData::InitializeLink() {
	
	NodeData A = nodes->get(0);
	NodeData B = nodes->get(1);
	NodeData BASE = nodes->get(2);
	NodeData IC = nodes->get(3);
    

	nodes->get(0).setlinkedNode(new linkedInfo(0, &IC));
	nodes->get(1).setlinkedNode(new linkedInfo(180, &IC));
	nodes->get(2).setlinkedNode(new linkedInfo(270, &IC));
	nodes->get(3).setlinkedNode(new linkedInfo(0, &B));
	nodes->get(3).setlinkedNode(new linkedInfo(90, &BASE));
	nodes->get(3).setlinkedNode(new linkedInfo(180, &A));
}

