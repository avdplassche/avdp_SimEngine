#include "tests.h"

int	runTests(Application &app) {

	try {
		runUITests(app);
		return 0;
	}
	catch (std::exception &e) {
		glfwTerminate();
		std::cerr << "Exception catched" << std::endl;
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;

}