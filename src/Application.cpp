#include "Application.hpp"
#include "argument_handler.h"
#include "Menu.hpp"


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

void	Application::init() {
	try {
		_initMonitor();
		_initWindow();
		_initCursor();
		_app_menu.load(APP_MENU_FILE);
		_theme.setTheme(THEME);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
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
		throw GlWindow();
	glfwGetWindowSize(_window, &width, &height);
	_window_resolution.width = width;
	_window_resolution.height = height;
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

	info_log("Window loop ready.", GREEN_LOG);


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
	if (DEBUG_MODE == WINDOW_INFO_MODE)
		setWindowHintEvent(_window);
	if(glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(_window, true);
}


GLFWwindow*		Application::getWindow() const {
	return (_window);
}

GLFWmonitor*	Application::getMonitor() const {
	return (_monitor);
}

t_size			Application::getWindowSize() const {
	return (_window_resolution);
}

t_size			Application::getMonitorResolution() const {
	return (_monitor_resolution);
}

Menu&			Application::getAppMenus(){
	return (_app_menu);
}

Theme&			Application::getTheme() {
	return (_theme);
}

