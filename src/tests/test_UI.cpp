#include "tests.h"
#include "uiSkeleton.hpp"
#include "MenuButton.hpp"

int	runShaderTests(Application &app) {


	glfwMakeContextCurrent(app.getWindow());
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glfwSetFramebufferSizeCallback(app.getWindow(), framebuffer_size_callback);

	std::cout << GREEN << "Window loop ready." << CRESET << std::endl;

	Container c;
	MenuButton button;

	//std::cout << "Size : " << app.getWindowSize().width << "x" << app.getWindowSize().height << std::endl;
	button.setValues(10, 10, 50, 50, app.getWindowSize());
	//button.printCoordinates();

	while (!glfwWindowShouldClose(app.getWindow()))
	{
		app.processInput();

		glClearColor(0.1f, 0.4f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		button.draw();
		c.draw();

		glfwSwapBuffers(app.getWindow());
		glfwPollEvents();
	}
	return 0;


}
