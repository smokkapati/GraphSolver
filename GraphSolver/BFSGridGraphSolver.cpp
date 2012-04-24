/*
 * BFSGridGraphSolver.cpp
 *
 *  Created on: Apr 20, 2012
 *      Author: SnigdhaChaitanya
 */

#include "BFSGridGraphSolver.h"
#include "gl.h"
#include "GridNode.h"
#include "GridGraph.h"
#include <math.h>

BFSGridGraphSolver::BFSGridGraphSolver(const GridGraphSolverCInfoT& info) {
	init(info);
	m_start->setVisited(true);
	m_start->setStatus("waiting");
	PathNodeT p(m_start);
	m_list_path.push_back(p);
}

GridGraphSolver::SolveStateT BFSGridGraphSolver::step() {
	if  (m_state == STEPPING) {

	}
	return m_state;
}

GridGraphSolver::SolveStateT BFSGridGraphSolver::solve() {

	std::list<PathNodeT>::iterator it;
	for (it=m_list_path.begin(); it != m_list_path.end(); it++) {
		if ((*it).node == m_finish) {
			return SOLVED;
		}
	}

	for (it=m_list_path.begin(); it != m_list_path.end(); it++) {
			PathNodeT current = *it;
			if (current.node->getStatus().compare("waiting") == 0) {
				std::vector <PathNodeT> m_temp_path;
				current.node->setStatus("done");
				current.node->setChildCount(0);
				for (int dir=0; dir < GridNode::NUM_DIRS; dir++) {
					if (current.node->containsEdge(dir) && !current.node->getNeighbor(dir)->isVisited()) {
						PathNodeT next(current.node->getNeighbor(dir));
						next.node->setVisited(true);
						next.node->setStatus("waiting");
						next.node->setParent(current.node);
						current.node->setChildCount(current.node->getChildCount()+1);
						m_temp_path.push_back(next);
					}
				}
				m_list_path.insert(m_list_path.end(), m_temp_path.begin(), m_temp_path.end());
				incrementStepCount();
			}
		}

	if (SOLVED == this->solve()) {
		//incrementStepCount();
		return SOLVED;
	}
	return UNSOLVED;
}

void BFSGridGraphSolver::render() {

	std::list<PathNodeT>::reverse_iterator rit;
	std::list<PathNodeT> m_to_be_removed;
	std::list<PathNodeT>::iterator iter;

	for (rit = m_list_path.rbegin(); rit != m_list_path.rend(); rit++) {
		if ((*rit).node->getChildCount() == 0 && (*rit).node != m_finish) {
			m_to_be_removed.push_back(*rit);
		}
	}

	while (!m_to_be_removed.empty()) {
		PathNodeT current = m_to_be_removed.front();
		m_to_be_removed.pop_front();

		for (iter = m_list_path.begin(); iter != m_list_path.end(); iter++) {
			if ((*iter).node == current.node) {
				m_list_path.erase(iter);
				break;
			}
		}

		//GridNode* parent = current.node->getParent();
		for(iter = m_list_path.begin(); iter != m_list_path.end(); iter++) {
			if ((*iter).node == current.node->getParent() && (*iter).node != m_finish) {
				(*iter).node->setChildCount((*iter).node->getChildCount()-1);
				if ((*iter).node->getChildCount() == 0) {
					m_to_be_removed.push_back(*iter);
				}
				break;
			}
		}
	}

	glColor3f(0, 1, 0); //pure green

	GridNode* from = m_start;
	for (iter = m_list_path.begin(); iter != m_list_path.end(); iter++) {
		drawPathSegment(from, (*iter).node);
		from = (*iter).node;
	}

	//draw start
	drawCircle(m_start->getCol(), m_start->getRow(), m_cellWidth/4);
	//draw end
	glColor3f(0,0,1);
	drawCircle(m_finish->getCol(), m_finish->getRow(), m_cellWidth/4);
}

void BFSGridGraphSolver::drawCircle(int x, int y, int radius) {
	glBegin(GL_LINE_LOOP);
	double dtor = 3.1415 / 180;
	int angle = 0;
	for (angle = 0; angle <= 360; angle++) {
		glVertex2f(m_x+ x*m_cellWidth + m_offsetX+sin(dtor * angle) * ((double) radius),
				m_y+ y*m_cellHeight + m_offsetY + cos(dtor * angle) * ((double) radius));
	}
	glEnd();
}

void BFSGridGraphSolver::drawPathSegment(GridNode *from, GridNode *to) {
	glBegin(GL_LINES);
		//offset to start of maze, then index over by rows, then add offset to center of cell
		glVertex2f(m_x+ from->getCol()*m_cellWidth + m_offsetX, m_y+ from->getRow()*m_cellHeight + m_offsetY);
		glVertex2f(m_x+ to->getCol()*m_cellWidth + m_offsetX, m_y+ to->getRow()*m_cellHeight + m_offsetY);
		glEnd();
}


