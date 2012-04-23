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
	m_width(info.width), //total width
	m_height(info.height), //total height
	m_x(info.xOrigin),
	m_y(info.yOrigin)
{
	m_cellWidth = (m_width) / m_graph->getNumCols();
	m_cellHeight = (m_height) / m_graph->getNumRows();
	m_widthOffset = m_cellWidth/2;
	m_heightOffset = m_cellHeight/2;

}


GridGraphRenderer::~GridGraphRenderer() {
}

void GridGraphRenderer::render() {
	for (int row=0; row < m_graph->getNumRows(); row++) {
		for (int col=0; col < m_graph->getNumCols(); col++) {
			drawCell(row, col);
		}
	}

}



//some shitty hack-fu
#define WALL_COLOR 1,0,0 //pure red
#define NO_WALL_COLOR .25f, .25f, .25f //gray

void GridGraphRenderer::drawCell(int row, int col) {

	if (!m_graph->containsEdge(row, col, GridNode::NORTH)) {
		glColor3f(WALL_COLOR);

	} else {
		glColor3f(NO_WALL_COLOR);
	}
	//draw TOP border

	glBegin(GL_LINES);
	glVertex2f(m_x + m_cellWidth * col, m_y + m_cellHeight * row);
	glVertex2f(m_x + m_cellWidth * (col + 1), m_y + m_cellHeight * row);
	glEnd();

	if (!m_graph->containsEdge(row, col, GridNode::EAST)) {
		glColor3f(WALL_COLOR);

	} else {
		glColor3f(NO_WALL_COLOR);
	}
	//draw RIGHT border
	glBegin(GL_LINES);
	glVertex2f(m_x + m_cellWidth * (col + 1), m_y + m_cellHeight * row);
	glVertex2f(m_x + m_cellWidth * (col + 1), m_y + m_cellHeight * (row + 1));
	glEnd();

	if (!m_graph->containsEdge(row, col, GridNode::SOUTH)) {
		glColor3f(WALL_COLOR);

	} else {
		glColor3f(NO_WALL_COLOR);
	}
	//draw TOP border
	glBegin(GL_LINES);
	glVertex2f(m_x + m_cellWidth * (col + 1), m_y + m_cellHeight * (row + 1));
	glVertex2f(m_x + m_cellWidth * col, m_y + m_cellHeight * (row + 1));
	glEnd();

	if (!m_graph->containsEdge(row, col, GridNode::WEST)) {
		glColor3f(WALL_COLOR);

	} else {
		glColor3f(NO_WALL_COLOR);
	}
	//draw LEFT border
	glBegin(GL_LINES);
	glVertex2f(m_x + m_cellWidth * col, m_y + m_cellHeight * (row + 1));
	glVertex2f(m_x + m_cellWidth * col, m_y + m_cellHeight * row);
	glEnd();

}

