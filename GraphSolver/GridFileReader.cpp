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

	return simple4();
//	return snigdha10();
}


GridGraph* GridFileReader::simple4() {
	GridGraph *graph = new GridGraph(3,3);

	graph->addEdge(0,0, GridNode::EAST);
	graph->addEdge(0,1, GridNode::SOUTH);
	graph->addEdge(1,1, GridNode::WEST);
	graph->addEdge(1,0, GridNode::SOUTH);
	graph->addEdge(2,0, GridNode::EAST);
	graph->addEdge(2,1, GridNode::EAST);
	return graph;
}

GridGraph* GridFileReader::snigdha10() {

GridGraph *graph = new GridGraph(10,10);

//	graph->addEdge(0,0, &graph(1,0));
//	graph.addEdge(1,0, &graph(2,0));
//	graph.addEdge(2,0, &graph(3,0));
//	graph.addEdge(3,0, &graph(4,0));
//	graph.addEdge(0,4, &graph(1,4));
//	graph.addEdge(0,4, &graph(0,5));
//	graph.addEdge(0,6, &graph(0,7));
//	graph.addEdge(0,7, &graph(0,8));
//	graph.addEdge(0,8, &graph(0,9));
//	graph.addEdge(1,0, &graph(1,1));
//	graph.addEdge(1,1, &graph(1,2));
//	graph.addEdge(1,2, &graph(2,2));
//	graph.addEdge(2,2, &graph(3,2));
//	graph.addEdge(3,2, &graph(4,2));
//	graph.addEdge(3,2, &graph(3,3));
//	graph.addEdge(4,2, &graph(4,3));
//	graph.addEdge(4,3, &graph(5,3));
//	graph.addEdge(5,3, &graph(6,3));
//	graph.addEdge(6,3, &graph(6,4));
//	graph.addEdge(6,4, &graph(6,5));
//	graph.addEdge(6,5, &graph(5,5));
//	graph.addEdge(5,5, &graph(4,5));
//	graph.addEdge(4,5, &graph(3,5));
//	graph.addEdge(3,5, &graph(2,5));
//	graph.addEdge(2,5, &graph(2,6));
//	graph.addEdge(2,6, &graph(1,6));
//	graph.addEdge(1,6, &graph(0,6));
//	graph.addEdge(0,8, &graph(1,8));
//	graph.addEdge(1,8, &graph(2,8));
//	graph.addEdge(2,8, &graph(3,8));
//	graph.addEdge(3,8, &graph(4,8));
//	graph.addEdge(4,8, &graph(5,8));
//	graph.addEdge(5,8, &graph(5,7));
//	graph.addEdge(5,7, &graph(6,7));
//	graph.addEdge(6,7, &graph(7,7));
//	graph.addEdge(7,7, &graph(8,7));
//	graph.addEdge(8,7, &graph(8,8));
//	graph.addEdge(8,8, &graph(8,9));
//	graph.addEdge(8,9, &graph(9,9));
//	graph.addEdge(6,0, &graph(7,0));
//	graph.addEdge(7,0, &graph(8,0));
//	graph.addEdge(8,0, &graph(9,0));
//	graph.addEdge(6,0, &graph(6,1));
//	graph.addEdge(9,0, &graph(9,1));
//	graph.addEdge(9,1, &graph(9,2));
//	graph.addEdge(9,2, &graph(9,3));
//	graph.addEdge(9,3, &graph(8,3));
//	graph.addEdge(8,3, &graph(7,3));
//	graph.addEdge(7,3, &graph(6,3));
//	graph.addEdge(6,5, &graph(7,5));
//	graph.addEdge(7,5, &graph(8,5));
//	graph.addEdge(3,3, &graph(3,4));
//	graph.addEdge(4,5, &graph(4,6));
	return graph;
}

