0.0.3 4/22/12
J Newth

Features:
Improved graphing and counting
Pushed code down in to GridGraphSolver
Added A* classes

TODO:
BFS Solver
BFS Stepping
A* Solver
A* Stepping
Maze generation

0.0.2 4/21/12

Features:
Stepping DFS solver working and animating.
Increased framerate, reorganized main.cpp::draw function to get the swap buffers right.
Lots of static variables in main.cpp, kind of a mess, but whatever.
Maze solve update rate is set in update cycle as # of frames.
DFS solver will correctly identify when it's solved a maze or found an unsolveable maze.

TODO:
BFS Solver
BFS Stepping
A* Solver
A* Stepping
Maze generation

Bugs:

0.0.1 4/18/12

Currently builds and solves a small maze.
This uses the DFSGraphSolver.
This solver can not step() through its solution, but it
can solve() it in a single step and this solution is correct.


4/18/12

Currently builds a small maze and has a partial solution.
SDL rendering is integrated.
DFSSolver doesnt really solve yet.


4/8/12

Currently constructs a grid of nodes with rows and columns. 
Has a text renderer (the graphs << operator)
No SDL based renderer
No solver

