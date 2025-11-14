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
	std::cout << " Mode\n"  << std::endl;
}

int main(int argc, char** argv)
{
	if (!glfwInit())
		return (exitProgramm("Failed to initialize GLFW", EXIT_FAILURE));

	print_mode();

	Application	app;
	if (app.init())
		return (exitProgramm("Failed to create GLFW window", EXIT_FAILURE));

	if (DEBUG_MODE == TEST)
		return runShaderTests(app);
	if (argc == 2 && handleArgument(argv[1], app))
		return 1;


	app.run();

	return 0;
}



