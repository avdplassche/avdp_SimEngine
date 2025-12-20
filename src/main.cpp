#include "pch.h"
#include "argument_handler.h"
#include "Application.hpp"
#include "tests.h"



void handle_sigint(int sig) {
	(void)sig;
	std::cout << "\nReceived SIGINT. Stopping the programm..." << std::endl;
}

int exitProgramm(const char *error_message, int return_value) {
	std::cerr << error_message << '\n';
	SDL_Quit();
	return return_value;
}



void	print_mode() {
	switch (DEBUG_MODE)
	{
		case 0:
			newLog("Dev mode started", INFO_LOG);
			break;
		case 1:
			newLog("Info mode started", INFO_LOG);
			break;
		case 2:
			newLog("Test mode started", INFO_LOG);
			break;
		default:
			break;
	}
}

int main(int argc, char** argv)
{

	print_mode();
	Application	app;


	try {
		app.init();
	}
	catch (std::exception &e){
		return exitProgramm(e.what(), EXIT_FAILURE);
	}
	signal(SIGINT, handle_sigint);
	if (DEBUG_MODE == TEST_MODE)
		return runTests(app);
	else if (argc == 2)
		return handleInfos(argv[1], app);
	try {
		app.run();
	}
	catch (std::exception &e) {
		return exitProgramm(e.what(), EXIT_FAILURE);
	}

	return EXIT_SUCCESS;;
}



