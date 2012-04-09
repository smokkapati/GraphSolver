/*
 * GridFileReader.cpp
 *
 *  Created on: Apr 8, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#include "GridFileReader.h"
#include "GridGraph.h"


//This should parse a file and generate a maze.
//For now, just generate a simple maze for getting all the parts working
GridGraph GridFileReader::parseFile(std::string fname) {
	GridGraph graph(3,3);

	graph.addEdge(0,0, &graph(0,1));
	graph.addEdge(0,0, &graph(1,0));
	graph.addEdge(1,0, &graph(1,1));
	graph.addEdge(1,1, &graph(2,1));
	graph.addEdge(2,1, &graph(2,0));

	return graph;
}

