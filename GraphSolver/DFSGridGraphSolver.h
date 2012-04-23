/*
 * DFSGridGraphSolver.h
 *
 *  Created on: Apr 15, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#ifndef DFSGRIDGRAPHSOLVER_H_
#define DFSGRIDGRAPHSOLVER_H_

#include <vector>
#include "GridGraphSolver.h"

class GridNode;

class DFSGridGraphSolver : public GridGraphSolver {
public:
	DFSGridGraphSolver(const GridGraphSolverCInfoT& info);
	SolveStateT step();
	SolveStateT solve();
	void render();

	virtual ~DFSGridGraphSolver() {};

protected:
	void drawPathSegment(GridNode *from, GridNode *to);

	typedef struct PathNodeT {
		int nextSearchEdge; //starts at 0, when = NUM_DIRS, the node can be popped
		GridNode *node;
		PathNodeT(GridNode *n) {
			nextSearchEdge = 0;
			node = n;
		}
	} PathNodeT;
	std::vector <PathNodeT> m_path;
};

#endif /* DFSGRIDGRAPHSOLVER_H_ */
