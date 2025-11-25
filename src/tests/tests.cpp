#include "tests.h"

int	runTests(Application &app) {

	try {
		runUITests(app);
		return 0;
	}
	catch (std::exception &e) {
		//glfwTerminate();
		std::cerr << "Exception catched" << '\n';
		std::cerr << e.what() << '\n';
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;

}