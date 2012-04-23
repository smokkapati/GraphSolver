/*
 * AStarGridGraphSolver.cpp
 *
 *  Created on: Apr 22, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#include "AStarGridGraphSolver.h"

AStarGridGraphSolver::AStarGridGraphSolver(const GridGraphSolverCInfoT& info) {
	init(info);
	PathNodeT p(NULL, m_start);
	m_openList.push(p);
	incrementStepCount();
}

AStarGridGraphSolver::~AStarGridGraphSolver() {
	// TODO Auto-generated destructor stub
}

GridGraphSolver::SolveStateT AStarGridGraphSolver::step() {
	if (m_state == STEPPING) {






	}
	return m_state;
}

GridGraphSolver::SolveStateT AStarGridGraphSolver::solve() {
	return UNSOLVED;
}

void AStarGridGraphSolver::render() {
	//draw open list as gray circle-with-tale
	//draw path as
}
