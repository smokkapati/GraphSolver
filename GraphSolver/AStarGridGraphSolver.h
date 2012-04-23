/*
 * AStarGridGraphSolver.h
 *
 *  Created on: Apr 22, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#ifndef ASTARGRIDGRAPHSOLVER_H_
#define ASTARGRIDGRAPHSOLVER_H_

#include "GridGraphSolver.h"
#include <queue>

class AStarGridGraphSolver: public GridGraphSolver {
public:
	AStarGridGraphSolver(const GridGraphSolverCInfoT& info);
	virtual ~AStarGridGraphSolver();
	virtual SolveStateT step();
	virtual SolveStateT solve();
	virtual void render();

protected:

	//My path node type
	typedef struct PathNodeT {
		GridNode *m_parent; //starts at 0, when = NUM_DIRS, the node can be popped
		GridNode *m_node;
		int m_score; //represents F=H+G
		PathNodeT(GridNode *parent, GridNode *n) {
			this->m_parent = parent;
			this->m_node = n;
		}
		const bool operator<(const PathNodeT& other) const { return (m_score > other.m_score);} //we are using a cost function
	} PathNodeT;

	std::priority_queue< PathNodeT > m_openList;
	std::vector <PathNodeT> m_closedList;
};

#endif /* ASTARGRIDGRAPHSOLVER_H_ */
