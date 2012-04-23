/*
 * GridGraph.cpp
 *
 *  Created on: Apr 8, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#include "GridGraph.h"
#include "GridNode.h"
#include <assert.h>

//A 2D grid of nodes is stored as a 1D array of size (numRows*numCols)
//They are stored row by row, so the index pattern is:
//index = (row*numCols)+col
//so getting to row 2, col3 = (2*numCols) + 3

GridGraph::GridGraph(int numRows, int numCols) : m_numRows(numRows), m_numCols(numCols) {
	m_nodes = new GridNode[m_numRows*m_numCols];
	for (int row=0; row < m_numRows; row++) {
		for (int col=0; col < m_numCols; col++) {
			getNode(row, col).setIndex(row, col); //each node knows where it is in the grid
		}
	}
}

GridNode& GridGraph::operator()(int row, int col) const {
	return getNode(row, col);
}

GridNode& GridGraph::getNode(int row, int col) const {
	assert(row >=0 && row < m_numRows && col >=0 && col < m_numCols);
	return m_nodes[m_numCols*row+col];
}

GridNode& GridGraph::getNode(int row, int col, int dir) const {
	switch (dir) {
	case GridNode::NORTH:
		row -= 1;
		break;
	case GridNode::EAST:
		col += 1;
		break;
	case GridNode::SOUTH:
		row += 1;
		break;
	case GridNode::WEST:
		col -= 1;
		break;
	}
	return getNode(row, col);
}

void GridGraph::addEdge(int row, int col, int dir) {
	switch (dir) {
	case GridNode::NORTH:
		if (row > 0) {
			getNode(row, col).addEdge(&getNode(row, col, dir), dir);
		}
		break;
	case GridNode::EAST:
		if (col < m_numCols-1) {
			getNode(row, col).addEdge(&getNode(row, col, dir), dir);
		}
		break;
	case GridNode::SOUTH:
		if (row < m_numRows-1) {
			getNode(row, col).addEdge(&getNode(row, col, dir), dir);
		}
		break;
	case GridNode::WEST:
		if (col > 0) {
			getNode(row, col).addEdge(&getNode(row, col, dir), dir);
		}
		break;
	}
}


void GridGraph::removeEdge(int row, int col, int dir) {
	if(row >=0 && row < m_numRows && col >=0 && col < m_numCols) {
		getNode(row, col).removeEdge(dir);
	}
}

bool GridGraph::containsEdge(int row, int col, int dir) const {
	bool ans = false;

	//check out of bounds
	if (row < 0 || row >= m_numRows || col < 0 || col >= m_numCols) {
		ans = false;
	}
	return (getNode(row,col).containsEdge(dir));
}

GridGraph::~GridGraph() {
	delete [] m_nodes;
}



std::ostream& operator<<(std::ostream& os, const GridGraph& g) {

	int numCols = g.getNumCols();
	int numRows = g.getNumRows();
	for (int i=0; i < numCols; i++) { os << " _"; }
	os << std::endl;
	for (int row=0; row < numRows; row++) {
		for (int col=0; col < numCols; col++) {
			if (col==0) { os << "|"; } //left wall
			if (g.containsEdge(row,col, GridNode::SOUTH)) {
				os << " ";
			}
			else {
				os << "_";
			}
			if (g.containsEdge(row,col, GridNode::EAST)) {
				os << " ";
			}
			else {
				os << "|";
			}
		}
		os << std::endl;
	}

	return os;
}

void GridGraph::test() {
	GridGraph g(1,2);
	g.addEdge(0,0, GridNode::EAST);
	assert(g.containsEdge(0,0, GridNode::EAST));
	assert(g.containsEdge(0,1, GridNode::WEST));
	assert(!g.containsEdge(0,0,GridNode::SOUTH));
	assert(!g.containsEdge(0,1,GridNode::EAST));
	assert(!g.containsEdge(0,1,GridNode::NORTH));
}
