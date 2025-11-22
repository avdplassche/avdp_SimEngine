#include "pch.h"
#include "argument_handler.h"
#include "Application.hpp"

void	testArgs(char* argv) {
	if (argv[0] && argv[1] &&  argv[0] != '-' && argv[1] != '-')
		throw ArgumentError (argv);
}

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
		printWindowInfo(app.getWindow());
		return 0;
	}
	throw ArgumentError(arg);
}

int	handleInfos(char* argv, Application& app) {

	std::stringstream ss(argv);
	std::string field;
	int i = 0;
	std::string	first;
	std::string	second;

	try {
		testArgs(argv);
		while (getline(ss, field, '-'))
		{
			if (i == 2)
			{
				if (field.empty())
					throw ArgumentError(argv);
				first = field;
			}
			if (i == 3)
			{
				if (field.empty())
					throw ArgumentError(argv);
				second = field;
			}
			i++;
		}
		if (first == "info")
			return (handleInfo(second, app));
		if (first == "help")
			return (handleHelp());
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
	return EXIT_SUCCESS;
}

