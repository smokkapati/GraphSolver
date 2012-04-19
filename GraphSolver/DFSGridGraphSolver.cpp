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
	m_start->setVisited(true);
	PathNodeT p(m_start);
	m_path.push_back(p);
}


GridGraphSolver::SolveStateT DFSGridGraphSolver::step() {
	if  (m_state == STEPPING) {

	}
	return m_state;
}

//bogus version
//GridGraphSolver::SolveStateT DFSGridGraphSolver::solve() {
//	m_path.push_back(m_start);
//	GridNode *node = m_start->getNeighbor(GridNode::EAST);
//	m_path.push_back(node);
//	node = node->getNeighbor(GridNode::SOUTH);
//	m_path.push_back(node);
//	node = node->getNeighbor(GridNode::WEST);
//	m_path.push_back(node);
//	return GridGraphSolver::STEPPING;
//}
GridGraphSolver::SolveStateT DFSGridGraphSolver::solve() { //start starts on stack
	if (m_path.back().node == m_finish) {
		return SOLVED;
	}
	else {
		PathNodeT current = m_path.back(); //get last element off stack
		for (int dir=0; dir < GridNode::NUM_DIRS; dir++) {
			if (current.node->containsEdge(dir) && !current.node->getNeighbor(dir)->isVisited()) {
				PathNodeT next(current.node->getNeighbor(dir));
				next.node->setVisited(true);
				m_path.push_back(next);
				if (SOLVED == this->solve()) {
					return SOLVED;
				}
			}
		}
		current.node->setVisited(false); //we are unwinding our path
		m_path.pop_back(); //pop this element - maze not solveable from here
		return UNSOLVED;
	}
}

void DFSGridGraphSolver::render()
{
	glColor3f(0, 1, 0); //pure green
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


