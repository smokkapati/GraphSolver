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
	PathNodeT *p = new PathNodeT(NULL, m_start);
	m_open_list.push_front(p);
	incrementStepCount();
}

GridGraphSolver::SolveStateT BFSGridGraphSolver::solve() {
	while (STEPPING == step())
		;
	return m_state;
}

GridGraphSolver::SolveStateT BFSGridGraphSolver::step() {
    
	if (m_state == STEPPING) {
		if (m_open_list.empty()) {
			m_state = UNSOLVED;
			return m_state;
		}
        
		std::list<PathNodeT *> m_temp_list;
		while(!m_open_list.empty()) {
			PathNodeT* current = m_open_list.back();
			incrementStepCount();
			m_open_list.pop_back();
			m_closed_list.push_back(current);
			if (current->m_node == m_finish) {
				m_state = SOLVED;
				computePath(current);
				return m_state;
			}
			for (int dir=0; dir < GridNode::NUM_DIRS; dir++) {
				if (current->m_node->containsEdge(dir) && !current->m_node->getNeighbor(dir)->isVisited()) {
					current->m_node->getNeighbor(dir)->setVisited(true);
					PathNodeT *next = new PathNodeT(current, current->m_node->getNeighbor(dir));
					m_temp_list.push_back(next);
				}
			}
		}
		m_open_list = m_temp_list;
	}
	return m_state;
}

void BFSGridGraphSolver::computePath(PathNodeT *end) {
    
	while (end != NULL) {
		m_path.push_back(end);
		end = end->m_parent;
	}
}

void BFSGridGraphSolver::render() {
    
	renderOpenAndClosedLists();
    
	if (m_state == SOLVED) {
		glColor3f(0, 1, 0); //pure green
		std::vector<PathNodeT *>::iterator iter;
		PathNodeT* from = *m_path.begin();
		for (iter = m_path.begin(); iter != m_path.end(); iter++) {
			drawPathSegment(from->m_node, (*iter)->m_node);
			from = (*iter);
		}
	}
	renderStart();
	renderFinish();
}

void BFSGridGraphSolver::drawPathSegment(GridNode *from, GridNode *to) {
	glBegin(GL_LINES);
	//offset to start of maze, then index over by rows, then add offset to center of cell
	glVertex2f(m_x + from->getCol() * m_cellWidth + m_offsetX,
               m_y + from->getRow() * m_cellHeight + m_offsetY);
	glVertex2f(m_x + to->getCol() * m_cellWidth + m_offsetX,
               m_y + to->getRow() * m_cellHeight + m_offsetY);
	glEnd();
}

void BFSGridGraphSolver::renderOpenAndClosedLists() {
	std::list<PathNodeT *>::iterator iter;
    
	glColor3f(0.5f, 0.5f, 0.5f);
	for (iter = m_closed_list.begin(); iter != m_closed_list.end(); iter++) {
		drawListNode(*iter);
		drawListNodeTail(*iter);
        
	}
    
	glColor3f(0.25f, 0.75f, 0.75f);
	for (iter = m_open_list.begin(); iter != m_open_list.end(); iter++) {
		drawListNode(*iter);
		drawListNodeTail(*iter);
	}
}

void BFSGridGraphSolver::drawListNode(PathNodeT *p) {
	drawCircle(p->m_node->getCol(), p->m_node->getRow(), m_cellWidth / 8);
}

void BFSGridGraphSolver::drawListNodeTail(PathNodeT *p) {
    
    //	draw tail
	if (p && p->m_parent) {
		int deltaX = p->m_parent->m_node->getCol() - p->m_node->getCol();
		int deltaY = p->m_parent->m_node->getRow() - p->m_node->getRow();
        
		//center of circle, then offset to edge of circle
		float x = (m_x + p->m_node->getCol() * m_cellWidth + m_offsetX)
        + deltaX * (m_cellWidth / 8);
		float y = (m_y + p->m_node->getRow() * m_cellHeight + m_offsetY)
        + deltaY * (m_cellWidth / 8);
        
		glBegin(GL_LINES);
		glVertex2f(x, y); //starts line on edge of circle
		x += deltaX * (m_cellWidth / 6);
		y += deltaY * (m_cellWidth / 6);
		glVertex2f(x, y); //starts line on edge of circle
		glEnd();
	}
}

BFSGridGraphSolver::~BFSGridGraphSolver() {
	//clean up anything in either open or closed lists
	std::list<PathNodeT *>::iterator iter;
	for (iter = m_open_list.begin(); iter != m_open_list.end(); iter++) {
		delete *iter;
	}
	m_open_list.clear();
    
	for (iter = m_closed_list.begin(); iter != m_closed_list.end(); iter++) {
		delete *iter;
	}
	m_closed_list.clear();
}


