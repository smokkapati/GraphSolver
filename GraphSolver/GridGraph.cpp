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
}

GridNode& GridGraph::getNode(int row, int col) const {
	return m_nodes[m_numCols*row+col];
}
void GridGraph::addEdge(int row, int col, GridNode *other) {
	getNode(row, col).addEdge(other);
}

bool GridGraph::containsEdge(int row, int col, DirectionT dir) const {
	bool ans = false;

	//check out of bounds
	if (row < 0 || row >= m_numRows || col < 0 || col >= m_numCols) {
		ans = false;
	}
	else {
		switch (dir) {
		case NORTH:
			if (row == 0) {
				ans = false;
			}
			else {
				ans = getNode(row, col).containsEdge(&getNode(row - 1, col));
			}
			break;
		case EAST:
			if (col == m_numCols - 1) {
				ans = false;
			}
			else {
				ans = getNode(row,col).containsEdge(&getNode(row, col+1));
			}
			break;
		case SOUTH:
			if (row == m_numRows - 1) {
				ans = false;
			}
			else {
				ans = getNode(row,col).containsEdge(&getNode(row+1, col));
			}
			break;
		case WEST:
			if (col == 0) {
				ans = false;
			}
			else {
				ans = getNode(row,col).containsEdge(&getNode(row, col-1));
			}
			break;
		}
	}
	return ans;
}

GridGraph::~GridGraph() {
	delete [] m_nodes;
}

inline
GridNode& GridGraph::operator()(int row, int col) const {
	return m_nodes[m_numCols*row+col];
}

std::ostream& operator<<(std::ostream& os, const GridGraph& g) {

	int numCols = g.getNumCols();
	int numRows = g.getNumRows();
	for (int i=0; i < numCols; i++) { os << " _"; }
	os << std::endl;
	for (int row=0; row < numRows; row++) {
		for (int col=0; col < numCols; col++) {
			if (col==0) { os << "|"; } //left wall
			if (g.containsEdge(row,col, GridGraph::SOUTH)) {
				os << " ";
			}
			else {
				os << "_";
			}
			if (g.containsEdge(row,col, GridGraph::EAST)) {
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
	g.addEdge(0,0, &g(0,1));
	assert(g(0,0).containsEdge(&g(0,1)));
	assert(g(0,1).containsEdge(&g(0,0)));
	assert(g.containsEdge(0,0,GridGraph::EAST));
	assert(!g.containsEdge(0,0,GridGraph::SOUTH));
	assert(!g.containsEdge(0,1,GridGraph::EAST));
	assert(!g.containsEdge(0,1,GridGraph::NORTH));
}
