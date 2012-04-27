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
    
	virtual ~BFSGridGraphSolver();
    
protected:
	typedef enum {LIST_A, LIST_B};
	int currentList;
	void drawPathSegment(GridNode *from, GridNode *to);
    
	typedef struct PathNodeT {
        PathNodeT *m_parent;
        GridNode *m_node;
        PathNodeT(PathNodeT *parent, GridNode *n) : m_parent(parent), m_node(n) {}
	} PathNodeT;
    
	virtual void computePath(PathNodeT* end);
	void renderOpenAndClosedLists();
	void drawListNode(PathNodeT *p);
	void drawListNodeTail(PathNodeT *p);
    
	std::vector<PathNodeT *> m_path;
	std::list<PathNodeT *> m_open_list;
	std::list<PathNodeT *> m_closed_list;
};



#endif /* BFSGRIDGRAPHSOLVER_H_ */
