#include "AIEphysApp.h"

AIEphysApp *app;

int main() {
	
	app = new AIEphysApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}