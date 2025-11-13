#include "pch.h"
#include "argument_handler.h"
#include "Application.hpp"


int exitProgramm(const char *error_message, int return_value) {
	glfwTerminate();
	std::cerr << error_message << std::endl;
	return return_value;
}


//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	(void)window;
//	glViewport(0, 0, width, height);
//}



int main(int argc, char** argv)
{

	if (!glfwInit())
		return (exitProgramm("Failed to initialize GLFW", EXIT_FAILURE));

	Application	app;
	if (app.init())
		return (exitProgramm("Failed to create GLFW window", EXIT_FAILURE));

	if (argc == 2)
	{
		if (handleArgument(argv[1], app.getWindow()))
			return 1;
	}


	app.run();
	//glfwWindowHint(GLFW_MAXIMIZED, GLFW_FALSE);

	// this will go on a class


	//glfwMakeContextCurrent(app.getWindow());

	//glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);

	//glfwSetFramebufferSizeCallback(app.getWindow(), framebuffer_size_callback);




	return 0;
}



