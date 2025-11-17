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

	std::cout << GREEN << "[INFO]	";
	switch (DEBUG_MODE)
	{
		case 0:
			std::cout << "Dev";
			break;
		case 1:
			std::cout << "Info";
			break;
		case 2:
			std::cout << "Test";
			break;
		default:
			break;
	}
	std::cout << " mode started"  << std::endl;
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
	}

	if (DEBUG_MODE == TEST)
	{
		try {
			runShaderTests(app);
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
	if (argc == 2)
	{
		try {
			handleArgument(argv[1], app);
		}
		catch (std::exception &e) {
			std::cerr << e.what() << std::endl;
			return EXIT_FAILURE;
		}
	}
	try {
		app.run();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;;
}



