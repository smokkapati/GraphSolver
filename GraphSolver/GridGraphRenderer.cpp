/*
 * GridGraphRenderer.cpp
 *
 *  Created on: Apr 13, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#include "GridGraphRenderer.h"
#include "GridGraph.h"
#include "gl.h"
#include "GridGraphSolver.h"

GridGraphRenderer::GridGraphRenderer(const GridGraphRendererCInfoT& info) :
	m_graph(info.graph),
	m_solver(info.solver),
	m_width(info.width), //total width
	m_height(info.height), //total height
	m_x(info.xOrigin),
	m_y(info.yOrigin)
{
	m_cellWidth = (m_width) / m_graph->getNumCols();
	m_cellHeight = (m_height) / m_graph->getNumRows();
	m_widthOffset = m_cellWidth/2;
	m_heightOffset = m_cellHeight/2;

	if (m_solver) {
		m_solver->render();
	}
}


GridGraphRenderer::~GridGraphRenderer() {
}

void GridGraphRenderer::render() {
	glColor3f(1, 0, 0); //pure red
	for (int row=0; row < m_graph->getNumRows(); row++) {
		for (int col=0; col < m_graph->getNumCols(); col++) {
			drawCell(row, col);
		}
	}
	if (m_solver) {
		//m_solver->render();
	}
}

void GridGraphRenderer::drawCell(int row, int col) {

	if (!m_graph->containsEdge(row, col, GridNode::NORTH)) {
		//draw TOP border
		glBegin(GL_LINES);
		glVertex2f(m_x+m_cellWidth*col, m_y+m_cellHeight*row);
		glVertex2f(m_x+m_cellWidth*(col+1), m_y+m_cellHeight*row);
		glEnd();
	}
	if (!m_graph->containsEdge(row, col, GridNode::EAST)) {
		//draw RIGHT border
		glBegin(GL_LINES);
		glVertex2f(m_x+m_cellWidth*(col+1), m_y+m_cellHeight*row);
		glVertex2f(m_x+m_cellWidth*(col+1), m_y+m_cellHeight*(row+1));
		glEnd();
	}
	if (!m_graph->containsEdge(row, col, GridNode::SOUTH)) {
		//draw TOP border
		glBegin(GL_LINES);
		glVertex2f(m_x+m_cellWidth*(col+1), m_y+m_cellHeight*(row+1));
		glVertex2f(m_x+m_cellWidth*col, m_y+m_cellHeight*(row+1));
		glEnd();
	}
	if (!m_graph->containsEdge(row, col, GridNode::WEST)) {
		//draw LEFT border
		glBegin(GL_LINES);
		glVertex2f(m_x+m_cellWidth*col, m_y+m_cellHeight*(row+1));
		glVertex2f(m_x+m_cellWidth*col, m_y+m_cellHeight*row);
		glEnd();
	}
}

