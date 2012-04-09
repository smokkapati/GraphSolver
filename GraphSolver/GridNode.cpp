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

void GridNode::addEdge(GridNode *other) {
	if (!containsEdge(other)) {
		m_edges.push_back(other);
		other->addEdge(this); //all edges go both ways
	}
}

bool GridNode::containsEdge(GridNode *other) {
	vector< GridNode* >::const_iterator index;
	index = find(m_edges.begin(), m_edges.end(), other);

	index = find(m_edges.begin(), m_edges.end(), other);
	return !(index == m_edges.end()); //if index is in range
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
	node1.addEdge(&node2);
	assert(node2.containsEdge(&node1));
	assert(node1.containsEdge(&node2));
}
