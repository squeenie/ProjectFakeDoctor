#include "Application2D.h"

int main() {
	
	auto app = new Application2D();
	app->run("AIE", 900, 600, false);
	delete app;

	return 0;
}