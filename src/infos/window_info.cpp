#include "pch.h"
#include "argument_handler.h"


void	key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	(void) mods;
	(void) scancode;
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS)
	{
		printMonitorInfo();
		printWindowInfo(window);
	}
}

void	setWindowHintEvent(GLFWwindow *window) {
	glfwSetKeyCallback(window, key_callback);
}


void	printWindowInfo(GLFWwindow* window) {

	int		width;
	int		height;

	std::cout << "-================-" << std::endl;
	std::cout << "| --info-window  |" << std::endl;
	std::cout << "-================-\n" << std::endl;

	std::cout << "	HINTS\n" << std::endl;
	std::cout << "0 GLFW_RESIZABLE		" << std::boolalpha << (bool)glfwGetWindowAttrib(window, GLFW_RESIZABLE) << std::endl;
	std::cout << "1 GLFW_VISIBLE			" << std::boolalpha << (bool)glfwGetWindowAttrib(window, GLFW_VISIBLE) << std::endl;
	std::cout << "2 GLFW_DECORATED		"  << std::boolalpha << (bool)glfwGetWindowAttrib(window, GLFW_DECORATED)  << std::endl;
	std::cout << "3 GLFW_FOCUSED			" << std::boolalpha << (bool)glfwGetWindowAttrib(window, GLFW_FOCUSED) << std::endl;
	std::cout << "4 GLFW_AUTO_ICONIFY		" << std::boolalpha << (bool)glfwGetWindowAttrib(window, GLFW_AUTO_ICONIFY) << std::endl;
	std::cout << "5 GLFW_FLOATING			" << std::boolalpha << (bool)glfwGetWindowAttrib(window, GLFW_FLOATING)  << std::endl;
	std::cout << "6 GLFW_MAXIMIZED		" << std::boolalpha << (bool)glfwGetWindowAttrib(window, GLFW_MAXIMIZED)  << std::endl;
	std::cout << "7 GLFW_CENTER_CURSOR		" << std::boolalpha << (bool)glfwGetWindowAttrib(window, GLFW_CENTER_CURSOR)  << std::endl;
	std::cout << "8 GLFW_TRANSPARENT_FRAMEBUFFER	" << std::boolalpha << (bool)glfwGetWindowAttrib(window, GLFW_SCALE_FRAMEBUFFER)  << std::endl;
	std::cout << "9 GLFW_FOCUS_ON_SHOW		" << std::boolalpha << (bool)glfwGetWindowAttrib(window, GLFW_FOCUS_ON_SHOW)  << std::endl;
	std::cout << "10 GLFW_SCALE_TO_MONITOR	" << std::boolalpha << (bool)glfwGetWindowAttrib(window, GLFW_SCALE_TO_MONITOR)  << std::endl;
	std::cout << std::endl;
	std::cout << SEPARATOR << std::endl;
	std::cout << std::endl;
	glfwGetWindowSize(window, &width, &height);
	std::cout << "Window Size : 	" << width << " x " << height << std::endl;

	std::cout << std::endl;
	std::cout << std::endl;

}
