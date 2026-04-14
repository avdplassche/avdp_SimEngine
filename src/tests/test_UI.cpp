#include "tests.h"
#include "uiSkeleton.hpp"
#include "MenuScreen.hpp"
#include "MenuTree.hpp"
#include "events.h"


int	runUITests(Application &app) {

	Theme&		theme = app.getTheme();
	SDL_Event	e;

	newLog("TEST - Window loop ready", INFO_LOG);
	app.setState(STARTING_STATE);
    //newLog("TEST - Starting state : " + STARTING_STATE, INFO_LOG);

	try {

		while (app.isRuning())
		{
			while (SDL_PollEvent(&e))
				handleEvents(&e, &app);

			SDL_SetRenderDrawColor(app.getRenderer(), theme.getBackground().r , theme.getBackground().g, theme.getBackground().b, SDL_ALPHA_OPAQUE);
			SDL_RenderClear(app.getRenderer());

			if (app.getState() == APP_STATE_MAIN_MENU)
				app.getMenuScreen().draw(app.getRenderer());
			else if (app.getState() == APP_STATE_UI_DEV)
				app.getUIDevMatrice().draw(app.getRenderer());
			else if (app.getState() == APP_STATE_SIMULATION_ONE)
				app.getSimulationOne().draw(app.getRenderer());
			SDL_RenderPresent(app.getRenderer());

            // std::cout << "State : " << app.getState() << '\n';
		}
		newLog("Ending Game Loop", INFO_LOG);
	}
	catch (std::exception &e) {
		std::cerr << e.what();
		return 1;
	}
	return 0;
}
