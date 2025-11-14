#include "pch.h"
#include "argument_handler.h"
#include "Application.hpp"

static int	argumentError(const char *argv);


static int handleHelp() {

	std::cout << "-================-" << std::endl;
	std::cout << "|    --help      |" << std::endl;
	std::cout << "-================-\n" << std::endl;

	std::cout << "--info-monitor : show available monitors" << std::endl;
	std::cout << "--info-window : show windows info" << std::endl;
	return 0;
}

static int	handleInfo(std::string arg, Application& app) {

	if (arg == "window")
	{
		printMonitorInfo();
		return (printWindowInfo(app.getWindow()));
	}
	return argumentError(arg.c_str());
}

int	handleArgument(char* argv, Application& app) {

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
		return (handleInfo(second, app));
	if (first == "help")
		return (handleHelp());
	return 0;
}


static int	argumentError(const char* arg) {
	std::cerr << "Unknown option : " << arg << std::endl;
	std::cerr << "Use --help for more information" << std::endl;
	return 1;
}