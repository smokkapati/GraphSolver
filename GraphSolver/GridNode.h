/*
 * Node.h
 *
 *  Created on: Mar 19, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#ifndef GRIDNODE_H_
#define GRIDNODE_H_

#include <vector>
#include <ostream>

class GridNode {
public:
    
	static const int NORTH = 0;
	static const int EAST = 1;
	static const int SOUTH = 2;
	static const int WEST = 3;
	static const int NUM_DIRS = 4;
    
	GridNode();
	virtual ~GridNode() { };
	virtual void setIndex(int row, int col);
	virtual void addEdge(GridNode *node, int dir);
	virtual void removeEdge(int dir);
	virtual bool containsEdge(GridNode *node);
	virtual bool containsEdge(int dir);
	virtual int getRow() { return m_row; }
	virtual int getCol() { return m_col; }
	virtual GridNode* getNeighbor(int dir);
	int opposite(int dir);
	bool isVisited() { return m_isVisited;}
	void setVisited(bool isVisited) {m_isVisited = isVisited;}
    
	static void test();
    
	friend std::ostream& operator<<(std::ostream& os, const GridNode& node);
protected:
	GridNode* m_neighbor[4];
	int m_row, m_col;
	bool m_isVisited;
};

#endif /* NODE_H_ */
