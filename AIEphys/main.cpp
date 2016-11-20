#include "AIEphysApp.h"

int main() {
	
	AIEphysApp *app = new AIEphysApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}