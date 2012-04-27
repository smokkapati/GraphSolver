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
	typedef enum {SIMPLE, MAZE10, SNIGDHA10, ASTARTEST};
	static GridGraph* parseFile(const char *fname);
	static GridGraph* getMaze(int maze);
    
private:
	static GridGraph* snigdha10();
	static GridGraph* simple4();
	static GridGraph* testAStar();
    static GridGraph* maze10();
    static GridGraph* maze2_10();
    static GridGraph* maze3_10();
    static GridGraph* maze4_10();
};

#endif /* GRIDFILEREADER_H_ */
