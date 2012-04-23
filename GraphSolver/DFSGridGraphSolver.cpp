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
	incrementStepCount();
}


GridGraphSolver::SolveStateT DFSGridGraphSolver::step() {
	if (m_path.size() == 0) { //we've tried every node and ended up popping all path
		return UNSOLVED;
	}

	if  (m_state == STEPPING) {
		PathNodeT current = m_path.back();
		if (current.node == m_finish) {
			return SOLVED;
		}
		for (int dir = current.nextSearchEdge; dir < GridNode::NUM_DIRS; dir++) {
			if (current.node->containsEdge(dir) && !current.node->getNeighbor(dir)->isVisited()) {
				current.nextSearchEdge++; //next time this node is considered, it will look at next edge
				PathNodeT next(current.node->getNeighbor(dir));
				next.node->setVisited(true);
				m_path.push_back(next);
				incrementStepCount();
				return STEPPING;
			}
		}
		//couldnt solve maze from here
		m_path.pop_back();
		incrementStepCount();
		return STEPPING;
	}
	return m_state;
}

//solves it all in one go
GridGraphSolver::SolveStateT DFSGridGraphSolver::solve() {
	while (step() == STEPPING); //will go through all the steps to a solution
	return m_state;
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

	renderStart();
	renderFinish();
}


void DFSGridGraphSolver::drawPathSegment(GridNode *from, GridNode *to) {
	glBegin(GL_LINES);
	//offset to start of maze, then index over by rows, then add offset to center of cell
	glVertex2f(m_x+ from->getCol()*m_cellWidth + m_offsetX, m_y+ from->getRow()*m_cellHeight + m_offsetY);
	glVertex2f(m_x+ to->getCol()*m_cellWidth + m_offsetX, m_y+ to->getRow()*m_cellHeight + m_offsetY);
	glEnd();
}


