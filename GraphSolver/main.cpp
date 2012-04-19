
#include <string.h>
#include <math.h>
#include <opengl.h>
#include <gl.h>
#include "SDL.h"
#include <iostream>

#include "GridGraph.h"
#include "GridFileReader.h"
#include "GridGraphRenderer.h"
#include "GridGraphSolver.h"
#include "DFSGridGraphSolver.h"

static SDL_Surface *gScreen;

using namespace std;

static GridGraph *gGraph;
static GridGraphRenderer *gRenderer;
static GridGraphSolver *gSolver;
static bool gDone;

static void tidyObjects() {
	if (gGraph) {
		delete gGraph;
	}
	if (gRenderer) {
		delete gRenderer;
	}
	if (gSolver) {
		delete gSolver;
	}
}

static void initAttributes ()
{
    // Setup attributes we want for the OpenGL context
    
    int value;
    
    // Don't set color bit sizes (SDL_GL_RED_SIZE, etc)
    //    Mac OS X will always use 8-8-8-8 ARGB for 32-bit screens and
    //    5-5-5 RGB for 16-bit screens
    
    // Request a 16-bit depth buffer (without this, there is no depth buffer)
    value = 16;
    SDL_GL_SetAttribute (SDL_GL_DEPTH_SIZE, value);
    
    
    // Request double-buffered OpenGL
    //     The fact that windows are double-buffered on Mac OS X has no effect
    //     on OpenGL double buffering.
    value = 1;
    SDL_GL_SetAttribute (SDL_GL_DOUBLEBUFFER, value);
}


static void createSurface (int fullscreen)
{
    Uint32 flags = 0;
    
    flags = SDL_OPENGL;
    if (fullscreen)
        flags |= SDL_FULLSCREEN;
    
    // Create window
    gScreen = SDL_SetVideoMode (640, 480, 0, flags);
    if (gScreen == NULL) {
        fprintf (stderr, "Couldn't set 640x480 OpenGL video mode: %s\n", SDL_GetError());
		SDL_Quit();
		exit(2);
	}
}

static void init(const char *fname)
{
	SDL_WM_SetCaption("GraphSolver", "GraphSolver");

	glClearColor(0, 0, 0, 0);
	glClearDepth(1.0f);

	glViewport(0, 0, 640, 480);

	glMatrixMode(GL_PROJECTION); //prevents Z from affecting anything.
	glLoadIdentity();

	glOrtho(0, 640, 480, 0, 1, -1); //set up 2D Perspective

	glMatrixMode(GL_MODELVIEW);

	glEnable(GL_TEXTURE_2D);
	glLoadIdentity();

	//create objects
	gGraph = GridFileReader::parseFile(fname);
	GridGraphSolverCInfoT solverInfo;
	solverInfo.graph = gGraph;
	solverInfo.from = &gGraph->getNode(0,0);
	solverInfo.to = &gGraph->getNode(2,2);
	solverInfo.width = 200; //tell renderer its working area
	solverInfo.height = 200;
	solverInfo.xOrigin = 10; //and tell it where it's upper left corner is
	solverInfo.yOrigin = 10;

	gSolver = new DFSGridGraphSolver(solverInfo);

	//debugging only
	gSolver->solve();

	GridGraphRenderer::GridGraphRendererCInfoT renderInfo;
	renderInfo.graph = gGraph;
	renderInfo.solver = gSolver;
	renderInfo.width = solverInfo.width; //tell renderer its working area
	renderInfo.height = solverInfo.height;
	renderInfo.xOrigin = solverInfo.xOrigin; //and tell it where it's upper left corner is
	renderInfo.yOrigin = solverInfo.yOrigin;
	gRenderer = new GridGraphRenderer(renderInfo);
}

static void drawGL ()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	gRenderer->render();
	gSolver->step();
	gSolver->render();
	SDL_GL_SwapBuffers();
}

static void handleKey(SDLKey key) {
	if (key == SDLK_ESCAPE) {
		gDone = true;
	}
}

static void mainLoop ()
{
	gDone = false;
    SDL_Event event;
    int fps = 24;
	int delay = 1000/fps;
    int thenTicks = -1;
    int nowTicks;
    
	//We need to write a real file parser to define graphs and then pass them in to our solver
	std::string fname = "null";


	std::cout << "Graph is:" << std::endl << *gGraph << std::endl;

    while ( !gDone ) {

		/* Check for events */
		while ( SDL_PollEvent (&event) ) {
			switch (event.type) {

				case SDL_MOUSEMOTION:
					break;
				case SDL_MOUSEBUTTONDOWN:
					break;
				case SDL_KEYDOWN:
					/* Any keypress quits the app... */
					handleKey(event.key.keysym.sym);
					break;
				case SDL_QUIT:
					gDone = true;
					break;
				default:
					break;
			}
		}
    
        // Draw at 24 hz
        //     This approach is not normally recommended - it is better to
        //     use time-based animation and run as fast as possible
        drawGL ();
        SDL_GL_SwapBuffers ();

        // Time how long each draw-swap-delay cycle takes
        // and adjust delay to get closer to target framerate
        if (thenTicks > 0) {
            nowTicks = SDL_GetTicks ();
            delay += (1000/fps - (nowTicks-thenTicks));
            thenTicks = nowTicks;
            if (delay < 0)
                delay = 1000/fps;
        }
        else {
            thenTicks = SDL_GetTicks ();
        }

        SDL_Delay (delay);
	}
}

int main(int argc, char *argv[])
{
	// Init SDL video subsystem
	if ( SDL_Init (SDL_INIT_VIDEO) < 0 ) {
		
        fprintf(stderr, "Couldn't initialize SDL: %s\n",
			SDL_GetError());
		exit(1);
	}

	//run some unit tests
	GridNode::test();
	GridGraph::test();

    // Set GL context attributes
    initAttributes();
    
    // Create GL context
    createSurface(0);
    
    // Get GL context attributes

    // Init GL state
    //could get a file name and pass in here

    init(NULL);
    
    // Draw, get events...
    mainLoop();
    
    // Cleanup
    tidyObjects();

	SDL_Quit();
	
    return 0;
}
