/*
 * main.cpp
 *
 *  Created on: Mar 18, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#include <iostream>
using namespace std;

int main(int argc, char **argv) {

	if (argc < 2) {
		cout << "Usage: GraphSolver [fname] [solver]" << endl;
		cout << "[fname] = A file representing a graph to be solved" << endl;
		cout << "[solver] = One of \"DFS\", \"BFS\", or \"A\"" << endl;
	}

//	FileReader reader(argv[0]);
//	Graph g;
//	reader.populate(g); //will fill g with the appropriate graph representation
	//Renderer context;
	//Solver solver(g);

	//while (true) {
		//process inputs
		//g.render(context);
		//solver.render(context);
		//solver.step();
	//}


	return 0;
}



