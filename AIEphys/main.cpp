#include "AIEphysApp.h"

int main() {
	
	auto app = new AIEphysApp();
	app->run("AIE", 1280, 720, false);
	delete app;

	return 0;
}