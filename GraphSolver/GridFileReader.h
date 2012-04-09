/*
 * GridFileReader.h
 *
 *  Created on: Apr 8, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#ifndef GRIDFILEREADER_H_
#define GRIDFILEREADER_H_

#include <string>
#include "GridGraph.h"

class GridFileReader {
public:
	static GridGraph parseFile(std::string fname);
};

#endif /* GRIDFILEREADER_H_ */
