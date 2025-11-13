#include "pch.h"


static int	argumentError(const char *argv);


static int handleHelp() {

	std::cout << "-================-" << std::endl;
	std::cout << "|    --help      |" << std::endl;
	std::cout << "-================-\n" << std::endl;

	std::cout << "--info-monitor : show monitors available" << std::endl;
	return 0;
}


static int	printMonitorInfo() {

	int count;
	int xpos, ypos;

	GLFWmonitor** monitors = glfwGetMonitors(&count);

	std::cout << "-================-" << std::endl;
	std::cout << "| --info-monitor |" << std::endl;
	std::cout << "-================-\n" << std::endl;

	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << "Index	Name	Adress		Size		Pos\n" << std::endl;

	for (int i = 0; i < count; i ++)
	{
		const GLFWvidmode *mode = glfwGetVideoMode(monitors[i]);
		glfwGetMonitorPos(monitors[i], &xpos, &ypos);

		std::cout << i << "	";
		std::cout << glfwGetMonitorName(monitors[i]) << "	";
		std::cout << monitors[i] << "	";
		std::cout << mode->width << " - " << mode->height << "	";
		std::cout << xpos << " - " << ypos;
		std::cout << std::endl;
	}

	std::cout << "----------------------------------------------------------" << std::endl;
	std::cout << "\n\nCheckout GL doc for information about gamma ramp" << std::endl;

	return 0;
}

int	printWindowInfo(GLFWwindow* window) {
	std::cout << "-================-" << std::endl;
	std::cout << "| --info-window  |" << std::endl;
	std::cout << "-================-\n" << std::endl;

	(void) window;


	return 0;
}



static int	handleInfo(std::string arg, GLFWwindow* window) {

	if (arg == "monitor")
		return (printMonitorInfo());
	if (arg == "window")
		return (printWindowInfo(window));
	return argumentError(arg.c_str());
}


int	handleArgument(char* argv, GLFWwindow* window) {

	std::stringstream ss(argv);
	std::string field;
	int i = 0;
	std::string	first;
	std::string	second;

	if (argv[0] && argv[1] &&  argv[0] != '-' && argv[1] != '-')
		return argumentError(argv);
	while (getline(ss, field, '-'))
	{
		if (i == 2)
		{
			if (field.empty())
				return argumentError(argv);
			first = field;
		}
		if (i == 3)
		{
			if (field.empty())
				return argumentError(argv);
			second = field;
		}
		i++;
	}

	if (first == "info")
		return (handleInfo(second, window));
	if (first == "help")
		return (handleHelp());
	return 0;
}


static int	argumentError(const char* arg) {
	std::cerr << "Unknown option : " << arg << std::endl;
	std::cerr << "Use --help for more information" << std::endl;
	return 1;
}