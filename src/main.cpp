#include "pch.h"
#include "argument_handler.h"
#include "Application.hpp"
#include "tests.h"


int exitProgramm(const char *error_message, int return_value) {
	std::cerr << error_message << '\n';
	SDL_Quit();
	return return_value;
}

void	print_mode() {
	switch (DEBUG_MODE)
	{
		case 0:
			new_log("Dev mode started", GREEN_LOG);
			break;
		case 1:
			new_log("Info mode started", GREEN_LOG);
			break;
		case 2:
			new_log("Test mode started", GREEN_LOG);
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

	if (DEBUG_MODE == TEST_MODE)
		return runTests(app);
	if (argc == 2)
		return handleInfos(argv[1], app);

	try {
		app.run();
	}
	catch (std::exception &e) {
		return exitProgramm(e.what(), EXIT_FAILURE);
	}

	return EXIT_SUCCESS;;
}



