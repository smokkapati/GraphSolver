/*
 * GridNode.cpp
 *
 *  Created on: Apr 8, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#include "GridNode.h"
#include <assert.h>
#include <algorithm>

using namespace std;

GridNode::GridNode() : m_row(0), m_col(0), m_isVisited(false) {
	for (int i=0; i < NUM_DIRS; i++) {
		m_neighbor[i]= NULL;
	}
}

void GridNode::setIndex(int row, int col) {
	m_row = row;
	m_col = col;
}

inline
int GridNode::opposite(int dir) {
	int opposite = NORTH;
	switch (dir) {
	case NORTH: return SOUTH;
	case EAST: return WEST;
	case WEST: return EAST;
	case SOUTH: return NORTH;
	default: return dir;
	}
	return opposite;
}

void GridNode::addEdge(GridNode *other, int dir) {
	m_neighbor[dir] = other;
	other->m_neighbor[opposite(dir)] = this;
}

void GridNode::removeEdge(int dir) {
	if (m_neighbor[dir]) {
		m_neighbor[dir]->m_neighbor[opposite(dir)] = NULL;
	}
	m_neighbor[dir] = NULL;
}

bool GridNode::containsEdge(GridNode *other) {
	for (int i=0; i < NUM_DIRS; i++) {
		if (m_neighbor[i] == other) { return true; }
	}
	return false;
}

bool GridNode::containsEdge(int dir) {
	if (dir < 0 || dir >= NUM_DIRS) { return false; }
	return (m_neighbor[dir] != NULL);
}

GridNode* GridNode::getNeighbor(int dir) {
	assert (dir >=0 && dir < NUM_DIRS);
	return m_neighbor[dir];
}



std::ostream& operator<<(std::ostream& os, const GridNode& node) {
	std::vector< GridNode* >::const_iterator index;
//	os << "[";
//	for (index = node.m_edges.begin(); index != node.m_edges.end(); ++index) {
//		//something here?
//	}
//	os << "]";
	return os;
}


void GridNode::test() {
	GridNode node1, node2;
	node1.addEdge(&node2, NORTH);
	assert(node2.containsEdge(&node1));
	assert(node1.containsEdge(&node2));
}
