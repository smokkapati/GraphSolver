/*
 * GridFileReader.cpp
 *
 *  Created on: Apr 8, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#include "GridFileReader.h"
#include "GridGraph.h"
#include "GridNode.h"

//This should parse a file and generate a maze.
//For now, just generate a simple maze for getting all the parts working
GridGraph* GridFileReader::parseFile(const char *fname) {
    
    //	return simple4();
    //	return snigdha10();
    //	return testAStar();
    return maze10();
}

GridGraph* GridFileReader::simple4() {
	GridGraph *graph = new GridGraph(3, 3);
    
	graph->addEdge(0, 0, GridNode::EAST);
	graph->addEdge(0, 1, GridNode::SOUTH);
	graph->addEdge(1, 1, GridNode::WEST);
	graph->addEdge(1, 0, GridNode::SOUTH);
	graph->addEdge(2, 0, GridNode::EAST);
	graph->addEdge(2, 1, GridNode::EAST);
	return graph;
}

GridGraph* GridFileReader::snigdha10() {
    
	GridGraph *graph = new GridGraph(10, 10);
    
	graph->addEdge(0, 0, GridNode::SOUTH);
	graph->addEdge(1, 0, GridNode::SOUTH);
	graph->addEdge(2, 0, GridNode::SOUTH);
	graph->addEdge(3, 0, GridNode::SOUTH);
	graph->addEdge(0, 4, GridNode::SOUTH);
	graph->addEdge(0, 4, GridNode::EAST);
	graph->addEdge(0, 6, GridNode::EAST);
	graph->addEdge(0, 7, GridNode::EAST);
	graph->addEdge(0, 8, GridNode::EAST);
	graph->addEdge(1, 0, GridNode::EAST);
	graph->addEdge(1, 1, GridNode::EAST);
	graph->addEdge(1, 2, GridNode::SOUTH);
	graph->addEdge(2, 2, GridNode::SOUTH);
	graph->addEdge(3, 2, GridNode::SOUTH);
	graph->addEdge(3, 2, GridNode::EAST);
	graph->addEdge(4, 2, GridNode::EAST);
	graph->addEdge(4, 3, GridNode::SOUTH);
	graph->addEdge(5, 3, GridNode::SOUTH);
	graph->addEdge(6, 3, GridNode::EAST);
	graph->addEdge(6, 4, GridNode::EAST);
	graph->addEdge(6, 5, GridNode::NORTH);
	graph->addEdge(5, 5, GridNode::NORTH);
	graph->addEdge(4, 5, GridNode::NORTH);
	graph->addEdge(3, 5, GridNode::NORTH);
	graph->addEdge(2, 5, GridNode::EAST);
	graph->addEdge(2, 6, GridNode::NORTH);
	graph->addEdge(1, 6, GridNode::NORTH);
	graph->addEdge(0, 8, GridNode::SOUTH);
	graph->addEdge(1, 8, GridNode::SOUTH);
	graph->addEdge(2, 8, GridNode::SOUTH);
	graph->addEdge(3, 8, GridNode::SOUTH);
	graph->addEdge(4, 8, GridNode::SOUTH);
	graph->addEdge(5, 8, GridNode::WEST);
	graph->addEdge(5, 7, GridNode::SOUTH);
	graph->addEdge(6, 7, GridNode::SOUTH);
	graph->addEdge(7, 7, GridNode::SOUTH);
	graph->addEdge(8, 7, GridNode::EAST);
	graph->addEdge(8, 8, GridNode::EAST);
	graph->addEdge(8, 9, GridNode::SOUTH);
	graph->addEdge(6, 0, GridNode::SOUTH);
	graph->addEdge(7, 0, GridNode::SOUTH);
	graph->addEdge(8, 0, GridNode::SOUTH);
	graph->addEdge(6, 0, GridNode::EAST);
	graph->addEdge(9, 0, GridNode::EAST);
	graph->addEdge(9, 1, GridNode::EAST);
	graph->addEdge(9, 2, GridNode::EAST);
	graph->addEdge(9, 3, GridNode::NORTH);
	graph->addEdge(8, 3, GridNode::NORTH);
	graph->addEdge(7, 3, GridNode::NORTH);
	graph->addEdge(6, 5, GridNode::SOUTH);
	graph->addEdge(7, 5, GridNode::SOUTH);
	graph->addEdge(3, 3, GridNode::EAST);
	graph->addEdge(4, 5, GridNode::EAST);
	return graph;
}


GridGraph* GridFileReader::testAStar() {
	GridGraph *graph = new GridGraph(6,8);
	for (int row = 0; row < graph->getNumRows(); row++) {
		for (int col =0; col < graph->getNumCols(); col++) {
			for (int dir=0; dir <GridNode::NUM_DIRS; dir++) {
				graph->addEdge(row,col,dir);
			}
		}
	}
    
	for (int row = 1; row <= 3; row++) {
		int col = 3;
		for (int dir = 0; dir < GridNode::NUM_DIRS; dir++) {
			graph->removeEdge(row, col, dir);
		}
	}
	return graph;
}

GridGraph* GridFileReader::maze10() {
    
	GridGraph *graph = new GridGraph(10,10);
    
	graph->addEdge(0,0, GridNode::EAST);
	graph->addEdge(0,1, GridNode::EAST);
	graph->addEdge(0,2, GridNode::EAST);
	graph->addEdge(0,3, GridNode::EAST);
	graph->addEdge(0,4, GridNode::EAST);
	graph->addEdge(0,5, GridNode::EAST);
	graph->addEdge(0,6, GridNode::EAST);
	graph->addEdge(0,7, GridNode::EAST);
	graph->addEdge(0,0, GridNode::SOUTH);
	graph->addEdge(1,0, GridNode::EAST);
	graph->addEdge(1,1, GridNode::EAST);
	graph->addEdge(1,2, GridNode::SOUTH);
	graph->addEdge(2,2, GridNode::WEST);
	graph->addEdge(2,1, GridNode::SOUTH);
	graph->addEdge(3,1, GridNode::WEST);
	graph->addEdge(3,0, GridNode::NORTH);
	graph->addEdge(0,3, GridNode::SOUTH);
	graph->addEdge(1,3, GridNode::SOUTH);
	graph->addEdge(0,4, GridNode::SOUTH);
	graph->addEdge(0,8, GridNode::SOUTH);
	graph->addEdge(0,9, GridNode::SOUTH);
	graph->addEdge(1,8, GridNode::EAST);
	graph->addEdge(1,4, GridNode::EAST);
	graph->addEdge(1,5, GridNode::SOUTH);
	graph->addEdge(2,5, GridNode::SOUTH);
	graph->addEdge(2,5, GridNode::WEST);
	graph->addEdge(2,4, GridNode::SOUTH);
	graph->addEdge(3,4, GridNode::WEST);
	graph->addEdge(3,3, GridNode::WEST);
	graph->addEdge(3,5, GridNode::EAST);
	graph->addEdge(3,7, GridNode::EAST);
	graph->addEdge(3,9, GridNode::NORTH);
	graph->addEdge(2,9, GridNode::WEST);
	graph->addEdge(2,8, GridNode::WEST);
	graph->addEdge(2,7, GridNode::NORTH);
	graph->addEdge(1,7, GridNode::WEST);
	graph->addEdge(1,6, GridNode::SOUTH);
	graph->addEdge(3,2, GridNode::SOUTH);
	graph->addEdge(3,6, GridNode::SOUTH);
	graph->addEdge(3,7, GridNode::SOUTH);
	graph->addEdge(3,8, GridNode::SOUTH);
	graph->addEdge(3,9, GridNode::SOUTH);
	graph->addEdge(4,0, GridNode::EAST);
	graph->addEdge(4,1, GridNode::EAST);
	graph->addEdge(4,2, GridNode::EAST);
	graph->addEdge(4,3, GridNode::EAST);
	graph->addEdge(4,4, GridNode::EAST);
	graph->addEdge(4,6, GridNode::EAST);
	graph->addEdge(4,8, GridNode::EAST);
	graph->addEdge(4,0, GridNode::SOUTH);
	graph->addEdge(4,2, GridNode::SOUTH);
	graph->addEdge(5,2, GridNode::SOUTH);
	graph->addEdge(4,4, GridNode::SOUTH);
	graph->addEdge(4,5, GridNode::SOUTH);
	graph->addEdge(4,7, GridNode::SOUTH);
	graph->addEdge(5,0, GridNode::EAST);
	graph->addEdge(5,4, GridNode::WEST);
	graph->addEdge(5,5, GridNode::SOUTH);
	graph->addEdge(5,6, GridNode::EAST);
	graph->addEdge(5,7, GridNode::EAST);
	graph->addEdge(5,8, GridNode::EAST);
	graph->addEdge(5,1, GridNode::SOUTH);
	graph->addEdge(6,1, GridNode::WEST);
	graph->addEdge(5,3, GridNode::SOUTH);
	graph->addEdge(5,9, GridNode::SOUTH);
	graph->addEdge(6,0, GridNode::SOUTH);
	graph->addEdge(7,0, GridNode::SOUTH);
	graph->addEdge(8,0, GridNode::SOUTH);
	graph->addEdge(6,3, GridNode::SOUTH);
	graph->addEdge(7,3, GridNode::SOUTH);
	graph->addEdge(8,3, GridNode::WEST);
	graph->addEdge(8,2, GridNode::NORTH);
	graph->addEdge(7,2, GridNode::WEST);
	graph->addEdge(7,1, GridNode::SOUTH);
	graph->addEdge(8,1, GridNode::SOUTH);
	graph->addEdge(9,1, GridNode::EAST);
	graph->addEdge(9,2, GridNode::EAST);
	graph->addEdge(9,3, GridNode::EAST);
	graph->addEdge(9,4, GridNode::NORTH);
	graph->addEdge(8,4, GridNode::EAST);
	graph->addEdge(8,5, GridNode::EAST);
	graph->addEdge(8,6, GridNode::EAST);
	graph->addEdge(6,5, GridNode::WEST);
	graph->addEdge(6,4, GridNode::SOUTH);
	graph->addEdge(7,4, GridNode::EAST);
	graph->addEdge(6,9, GridNode::WEST);
	graph->addEdge(6,8, GridNode::SOUTH);
	graph->addEdge(7,8, GridNode::EAST);
	graph->addEdge(7,9, GridNode::SOUTH);
	graph->addEdge(8,9, GridNode::SOUTH);
	graph->addEdge(9,9, GridNode::WEST);
	graph->addEdge(9,8, GridNode::WEST);
	graph->addEdge(9,7, GridNode::WEST);
	graph->addEdge(9,6, GridNode::WEST);
	graph->addEdge(9,8, GridNode::NORTH);
	graph->addEdge(8,7, GridNode::NORTH);
	graph->addEdge(7,7, GridNode::WEST);
	graph->addEdge(7,6, GridNode::NORTH);
	graph->addEdge(6,6, GridNode::EAST);
    
	return graph;
}


