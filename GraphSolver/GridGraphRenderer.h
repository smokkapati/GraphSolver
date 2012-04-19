/*
 * GridGraphRenderer.h
 *
 *  Created on: Apr 13, 2012
 *      Author: Joshua Newth (mrfurious@gmail.com)
 */

#ifndef GRIDGRAPHRENDERER_H_
#define GRIDGRAPHRENDERER_H_

//forward declaration
class GridGraph;
class GridGraphSolver;


class GridGraphRenderer {
public:
	typedef struct GridGraphRendererCInfoT {
		GridGraph* graph;
		GridGraphSolver* solver;
		int width, height, xOrigin, yOrigin;
	} GridGraphCInfoT;

	GridGraphRenderer(const GridGraphRendererCInfoT& info);
	virtual void render();
	virtual ~GridGraphRenderer();
protected:
	void drawCell(int row, int col);

	GridGraph *m_graph;
	GridGraphSolver *m_solver;
	int m_width, m_height, m_x, m_y;
	int m_cellWidth, m_cellHeight, m_widthOffset, m_heightOffset;
};

#endif /* GRIDGRAPHRENDERER_H_ */
