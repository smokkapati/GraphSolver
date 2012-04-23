/*
 * GridFileReader.h
 *
 *  Created on: Apr 8, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#ifndef GRIDFILEREADER_H_
#define GRIDFILEREADER_H_

#include "GridGraph.h"

class GridFileReader {
public:
	static GridGraph* parseFile(const char *fname);
private:
	static GridGraph* snigdha10();
	static GridGraph* simple4();
	static GridGraph* testAStar();

};

#endif /* GRIDFILEREADER_H_ */
