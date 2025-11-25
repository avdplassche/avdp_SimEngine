#include "pch.h"
#include "argument_handler.h"
#include "Application.hpp"

void	testArgs(char* argv) {
	if (argv[0] && argv[1] &&  argv[0] != '-' && argv[1] != '-')
		throw ArgumentError (argv);
}

static int handleHelp() {

	std::cout << "-================-" << '\n';
	std::cout << "|    --help      |" << '\n';
	std::cout << "-================-\n" << '\n';

	std::cout << "--info-monitor : show available monitors" << '\n';
	std::cout << "--info-window : show windows info" << '\n';
	return 0;
}

static int	handleInfo(std::string arg, Application& app) {
	(void) app;
	if (arg == "window")
	{
		//printMonitorInfo();
		runWindowInfoMode(app);
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
		std::cerr << e.what() << '\n';
	}
	return EXIT_SUCCESS;
}

