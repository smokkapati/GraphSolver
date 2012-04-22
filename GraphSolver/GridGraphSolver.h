/*
 * GraphSolver.h
 *
 *  Created on: Apr 15, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#ifndef GRAPHSOLVER_H_
#define GRAPHSOLVER_H_

#include "GridGraph.h"
class GridNode;

typedef struct GridGraphSolverCInfoT {
	GridGraph *graph;
	GridNode *from;
	GridNode *to;
	int xOrigin, yOrigin, width, height;
} GridGraphSolverCInfoT;

class GridGraphSolver {


public:

	typedef enum SolveStateT { STEPPING, SOLVED, UNSOLVED };
	void init(const GridGraphSolverCInfoT& info) {
		m_graph = info.graph;
		m_start = info.from;
		m_finish = info.to;
		m_x = info.xOrigin;
		m_y = info.yOrigin;
		m_cellWidth = (info.width) / m_graph->getNumCols();
		m_cellHeight = (info.height) / m_graph->getNumRows();
		m_offsetX = m_cellWidth/2;
		m_offsetY = m_cellHeight/2;
		m_stepCount = 0; //tracks # of "steps" to solution (every path addition or removal)
		m_state = STEPPING;
	}

	virtual SolveStateT step() = 0;
	virtual SolveStateT solve() = 0;
	virtual SolveStateT getState() { return m_state; }
	int getStepCount() { return m_stepCount; }
	void incrementStepCount() { m_stepCount++; }

	virtual void render() = 0;
	virtual ~GridGraphSolver() {};

protected:
	GridGraph *m_graph;
	GridNode *m_start;
	GridNode *m_finish;
	SolveStateT m_state;
	int m_stepCount;
	//rendering information should not be here but in the interests of time Ive put them here
	int m_x, m_y, m_cellWidth, m_cellHeight, m_offsetX, m_offsetY;
};

#endif /* GRAPHSOLVER_H_ */
