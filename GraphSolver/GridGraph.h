/*
 * GridGraph.h
 *
 *  Created on: Apr 8, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#ifndef GRIDGRAPH_H_
#define GRIDGRAPH_H_

#include "GridNode.h"

class GridGraph {
public:

	GridGraph(int numRows, int numCols);
	virtual void addEdge(int row, int col, int dir);

	virtual GridNode& getNode(int row, int col) const;
	virtual GridNode& getNode(int row, int col, int dir) const;
	virtual GridNode& operator()(int row, int col) const;
	virtual bool containsEdge(int row, int col, int dir) const;

	virtual int getNumRows() const { return m_numRows;}
	virtual int getNumCols() const { return m_numCols;}
	friend std::ostream& operator<<(std::ostream& os, const GridGraph& g);

	static void test();
	virtual ~GridGraph();

protected:
	GridNode *m_nodes; //array of nodes
	int m_numRows, m_numCols;
};

#endif /* GRIDGRAPH_H_ */
