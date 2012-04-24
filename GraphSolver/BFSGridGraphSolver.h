/*
 * BFSGridGraphSolver.h
 *
 *  Created on: Apr 20, 2012
 *      Author: SnigdhaChaitanya
 */

#ifndef BFSGRIDGRAPHSOLVER_H_
#define BFSGRIDGRAPHSOLVER_H_

#include "GridGraphSolver.h"

#include <list>

class GridNode;

class BFSGridGraphSolver : public GridGraphSolver {
public:
	BFSGridGraphSolver(const GridGraphSolverCInfoT& info);
	SolveStateT step();
	SolveStateT solve();
	void render();

	virtual ~BFSGridGraphSolver() {};

protected:
	void drawPathSegment(GridNode *from, GridNode *to);
	void drawCircle(int x, int y, int radius);

	typedef struct PathNodeT {
		int nextSearchEdge;
		GridNode *node;
		PathNodeT(GridNode *n) {
			nextSearchEdge = 0;
			node = n;
		}
	} PathNodeT;
	std::vector <PathNodeT> m_path;
	std::list <PathNodeT> m_list_path;
};



#endif /* BFSGRIDGRAPHSOLVER_H_ */
