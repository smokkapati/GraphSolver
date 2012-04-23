/*
 * GridGraphSolver.cpp
 *
 *  Created on: Apr 22, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#include "GridGraphSolver.h"
#include "gl.h"
#include <math.h>

	 void GridGraphSolver::renderPath() {

	 }
	 void GridGraphSolver::renderStart() {
		 	glColor3f(0, 1, 0); //pure green
		 	//draw start
		 	drawCircle(m_start->getCol(), m_start->getRow(), m_cellWidth/4);
	 }
	 void GridGraphSolver::renderFinish() {
		 	//draw end
		 	glColor3f(0,0,1);
		 	drawCircle(m_finish->getCol(), m_finish->getRow(), m_cellWidth/4);
	 }

	 void GridGraphSolver::drawCircle(int x, int y, int radius) {
	 	glBegin(GL_LINE_LOOP);
	 	double dtor = 3.1415 / 180;
	 	int angle = 0;
	 	for (angle = 0; angle <= 360; angle++) {
	 		glVertex2f(m_x+ x*m_cellWidth + m_offsetX+sin(dtor * angle) * ((double) radius),
	 				m_y+ y*m_cellHeight + m_offsetY + cos(dtor * angle) * ((double) radius));
	 	}
	 	glEnd();
	 }



