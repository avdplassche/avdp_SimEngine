#include "Application.hpp"
#include <cstring>
#include "argument_handler.h"


Application::Application() {}

Application::Application (const Application& source) {
	*this = source;
}

Application& Application::operator=(const Application& source) {
	if (this != &source)
	{
		this->_monitor = source._monitor;
		this->_window = source._window;
	}
	return *this;
}

Application::~Application() {
	glfwDestroyWindow(_window);
	glfwTerminate();
}

int	Application::init() {
	_initMonitor();
	if (_initWindow())
		return 1;
	_initCursor();
	return 0;
}

int	Application::_initMonitor() {
	_monitor_list = glfwGetMonitors(&_nbMonitors);
	_monitor = glfwGetPrimaryMonitor();
	_mode = glfwGetVideoMode(_monitor);
	if (_nbMonitors > 1)
	glfwSetWindowMonitor(_window, _monitor_list[1],0, 0, _mode->width, _mode->height, _mode->refreshRate);
	return 0;
}

int	Application::_initWindow() {

	int	width, height;

	_window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pure OpenGL via GLFW", NULL, NULL);
	if (_window == NULL)
	return 1;
	glfwGetWindowSize(_window, &width, &height);
	_window_size.width = width;
	_window_size.height = height;
	return 0;
}

int	Application::_initCursor() {
	unsigned char pixels[4 * 4 * 4];
	GLFWimage image;

	memset(pixels, 0xff, sizeof(pixels));
	image.width = 4;
	image.height = 4;
	image.pixels = pixels;
	GLFWcursor* cursor = glfwCreateCursor(&image, 0, 0);
	glfwSetCursor(_window, cursor);
	return 0;
}




int	Application::run() {

	glfwMakeContextCurrent(_window);
	glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
	glfwSetFramebufferSizeCallback(_window, framebuffer_size_callback);

	std::cout << GREEN << "Window loop ready." << CRESET << std::endl;


	while (!glfwWindowShouldClose(_window))
	{
		processInput();

		glClearColor(0.1f, 0.4f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// [...]

		glfwSwapBuffers(_window);
		glfwPollEvents();
	}
	return 0;
}




void Application::processInput()
{
	if (DEBUG_MODE == WINDOW)
		setWindowHintEvent(_window);
	if(glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(_window, true);
}





GLFWwindow			*Application::getWindow() const {
	return (_window);
}

GLFWmonitor			*Application::getMonitor() const {
	return (_monitor);
}

t_size Application::getWindowSize() const {
	return (_window_size);
}

int Application::getWindowHeight() const {
	return (_window_height);
}

int Application::getMonitorWidth() const {
	return (_monitor_width);
}

int Application::getMonitorHeight() const {
	return (_monitor_height);
}

