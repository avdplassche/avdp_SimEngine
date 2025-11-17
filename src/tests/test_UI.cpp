#include "tests.h"
#include "uiSkeleton.hpp"
#include "MainScreen.hpp"
#include "Menu.hpp"

int	runShaderTests(Application &app) {

	glfwMakeContextCurrent(app.getWindow());
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glfwSetFramebufferSizeCallback(app.getWindow(), framebuffer_size_callback);

	std::cout << GREEN << "[INFO]	Window loop ready." << CRESET << std::endl;

	Container c;

	Color	color(1.0f, 1.0f, 1.0f, 1.0f);
	MainScreen	main_screen(5,app.getWindowSize(), color, color);
	Menu	menus;

	try {
		menus.loadMenus();
		menus.printMenu(menus.getMenu());
		while (!glfwWindowShouldClose(app.getWindow()))
		{
			app.processInput();

			glClearColor(0.1f, 0.4f, 0.7f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			main_screen.draw();
			//c.draw();

			glfwSwapBuffers(app.getWindow());
			glfwPollEvents();
		}
	}
	catch (std::exception &e) {
		std::cerr << e.what();
		return 1;
	}

	return 0;


}
