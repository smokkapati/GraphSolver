/*
 * DFSGridGraphSolver.cpp
 *
 *  Created on: Apr 15, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#include "DFSGridGraphSolver.h"
#include "gl.h"
#include "GridNode.h"
#include "GridGraph.h"

DFSGridGraphSolver::DFSGridGraphSolver(const GridGraphSolverCInfoT& info) {
	init(info);
	m_path.push_back(m_start);
}

void DFSGridGraphSolver::step() { }

//bogus version
void DFSGridGraphSolver::solve() {
	m_path.push_back(m_start);
	GridNode *node = m_start->getNode(GridNode::EAST);
	m_path.push_back(node);
	node = node->getNode(GridNode::SOUTH);
	m_path.push_back(node);
	node = node->getNode(GridNode::WEST);
	m_path.push_back(node);
}

void DFSGridGraphSolver::render()
{
	glColor(0,1,0);
	std::vector<PathNodeT>::iterator iter;
	GridNode* from = m_start;
	for (iter = m_path.begin(); iter != m_path.end(); iter++) {
		drawPathSegment(from, (*iter).node);
		from = (*iter).node;
	}
}

void DFSGridGraphSolver::drawPathSegment(GridNode *from, GridNode *to) {
	glBegin(GL_LINES);
	//offset to start of maze, then index over by rows, then add offset to center of cell
	glVertex2f(m_x+ from->getCol()*m_cellWidth + m_offsetX, m_y+ from->getRow()*m_cellHeight + m_offsetY);
	glVertex2f(m_x+ to->getCol()*m_cellWidth + m_offsetX, m_y+ to->getRow()*m_cellHeight + m_offsetY);
	glEnd();
}


