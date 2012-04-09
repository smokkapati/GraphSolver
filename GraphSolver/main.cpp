/*
 * main.cpp
 *
 *  Created on: Mar 18, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#include <iostream>
#include "GridGraph.h"
#include "GridNode.h"
#include "GridFileReader.h"

using namespace std;



int main(int argc, char **argv) {

	//run some unit tests
	GridNode::test();
	GridGraph::test();

	//We probably need to write a real file parser to define graphs and then pass them in to our solver
	std::string fname = "null";
	GridGraph graph = GridFileReader::parseFile(fname);

	std::cout << "Graph is:" << std::endl << graph << std::endl;

	//graphics biz


	return 0;
}



