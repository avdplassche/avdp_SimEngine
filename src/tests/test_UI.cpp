#include "tests.h"
#include "uiSkeleton.hpp"
#include "MainScreen.hpp"
#include "MenuTree.hpp"

int	runUITests(Application &app) {

	new_log("TEST - Window loop ready", BLUE_LOG);

	//Container c;
	Theme&		theme = app.getTheme();
	bool		close_window = false;
	SDL_Event	e;
	t_color		&background = theme.getBackground();

	app.getAppMenus().printMenu(app.getAppMenus().getTree());

	try {

		while (!close_window)
		{
			while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EVENT_QUIT) {
				close_window = true;
            	}
   		 	}

			SDL_SetRenderDrawColor(app.getRenderer(), background.r , background.g, background.b, SDL_ALPHA_OPAQUE);
			SDL_RenderClear(app.getRenderer());

        // *You would draw your game elements here*
			app.getMainScreen().draw();

			SDL_RenderPresent(app.getRenderer());
			//app.processInput();


			//c.draw();

		}
	}
	catch (std::exception &e) {
		std::cerr << e.what();
		return 1;
	}

	return 0;


}
