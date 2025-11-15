#include "tests.h"
#include "uiSkeleton.hpp"

int	runShaderTests(Application &app) {


	glfwMakeContextCurrent(app.getWindow());
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glfwSetFramebufferSizeCallback(app.getWindow(), framebuffer_size_callback);

	std::cout << GREEN << "Window loop ready." << CRESET << std::endl;

	Container c;

	std::cout << "normalize : " << normalize(500, 2000) << std::endl;
	std::cout << "normalize : " << normalize(1500, 2000) << std::endl;



	while (!glfwWindowShouldClose(app.getWindow()))
	{
		app.processInput();

		glClearColor(0.1f, 0.4f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//glBegin(GL_LINE_LOOP);
		//glColor3f(.0f, 1.0f, 1.0f); // White color
		//glVertex2f(-0.5555555f,  -0.5f); // Top-left vertex
		//glVertex2f( 0.5f,  0.5f); // Top-right vertex
		//glVertex2f( 0.5f, -0.5f); // Bottom-right vertex
		//glVertex2f(-0.5f, -0.5f); // Bottom-left vertex
		//glEnd();

		c.draw();

		glfwSwapBuffers(app.getWindow());
		glfwPollEvents();
	}
	return 0;


}
