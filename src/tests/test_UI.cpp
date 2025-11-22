#include "tests.h"
#include "uiSkeleton.hpp"
#include "MainScreen.hpp"
#include "Menu.hpp"

static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
	(void) window;
	std::cout << xpos << " - " << ypos << std::endl;
}


int	runUITests(Application &app) {

	glfwMakeContextCurrent(app.getWindow());
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glfwSetFramebufferSizeCallback(app.getWindow(), framebuffer_size_callback);

	info_log("TEST - Window loop ready", BLUE_LOG);

	Container c;
	Theme&		theme = app.getTheme();
	t_color		background = theme.getBackground();

	app.getAppMenus().printMenu(app.getAppMenus().getMenuTree());

	t_mainScreenConfig	main_screen_config;
	main_screen_config.default_color = theme.getMenuDefault();
	main_screen_config.hover_color = theme.getMenuHover();
	main_screen_config.inactive_color = theme.getMenuInactive();

	MainScreen	main_screen(app.getAppMenus(), main_screen_config);

	try {
		while (!glfwWindowShouldClose(app.getWindow()))
		{
			glfwSetCursorPosCallback(app.getWindow(), cursor_position_callback);
			app.processInput();

			glClearColor(background.r, background.g, background.b, background.a);
			glClear(GL_COLOR_BUFFER_BIT);

			main_screen.draw();
			c.draw();

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
