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
	virtual ~GridNode() { };
	virtual void addEdge(GridNode *node);
	virtual bool containsEdge(GridNode *node);
	static void test();

	friend std::ostream& operator<<(std::ostream& os, const GridNode& node);
protected:
	std::vector< GridNode* > m_edges;




};

#endif /* NODE_H_ */
