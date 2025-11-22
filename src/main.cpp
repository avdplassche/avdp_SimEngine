#include "pch.h"
#include "argument_handler.h"
#include "Application.hpp"
#include "tests.h"


int exitProgramm(const char *error_message, int return_value) {
	glfwTerminate();
	std::cerr << error_message << std::endl;
	return return_value;
}

void	print_mode() {
	switch (DEBUG_MODE)
	{
		case 0:
			info_log("Dev mode started", GREEN_LOG);
			break;
		case 1:
			info_log("Info mode started", GREEN_LOG);
			break;
		case 2:
			info_log("Test mode started", GREEN_LOG);
			break;
		default:
			break;
	}
}

int main(int argc, char** argv)
{
	if (!glfwInit())
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return EXIT_FAILURE;
	}

	print_mode();

	Application	app;

	try {
		app.init();
	}
	catch (std::exception &e){
		glfwTerminate();
		std::cout << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	if (DEBUG_MODE == TEST_MODE)
		return runTests(app);
	if (argc == 2)
		return handleInfos(argv[1], app);

	try {
		app.run();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;;
}



