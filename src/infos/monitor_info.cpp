#include "pch.h"
#include "argument_handler.h"


int	printMonitorInfo() {

	int count;
	int xpos, ypos;
	GLFWmonitor** monitors = glfwGetMonitors(&count);

	std::cout << "-================-" << std::endl;
	std::cout << "| --info-monitor |" << std::endl;
	std::cout << "-================-\n" << std::endl;

	std::cout << SEPARATOR << std::endl;
	std::cout << "Index	Name	Adress		Size		Pos		Refresh Rate\n" << std::endl;

	for (int i = 0; i < count; i ++)
	{
		const GLFWvidmode *mode = glfwGetVideoMode(monitors[i]);
		glfwGetMonitorPos(monitors[i], &xpos, &ypos);

		std::cout << i << "	";
		std::cout << glfwGetMonitorName(monitors[i]) << "	";
		std::cout << monitors[i] << "	";
		std::cout << mode->width << " - " << mode->height << "	";
		std::cout << xpos << " - " << ypos << "		";
		std::cout << mode->refreshRate;
		std::cout << std::endl;
	}

	std::cout << SEPARATOR << std::endl;
	std::cout << "\n\nCheckout GL doc for information about gamma ramp\n" << std::endl;

	return 0;
}

