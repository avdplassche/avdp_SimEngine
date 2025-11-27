#include "tests.h"
#include "uiSkeleton.hpp"
#include "MenuScreen.hpp"
#include "MenuTree.hpp"

int	runUITests(Application &app) {

	new_log("TEST - Window loop ready", BLUE_LOG);

	Theme&		theme = app.getTheme();
	bool		close_window = false;
	SDL_Event	e;


	//app.getAppMenus().printMenu(app.getAppMenus().getTree(), true);

	try {

		while (!close_window)
		{
			while (SDL_PollEvent(&e)) {
				if (e.type == SDL_EVENT_QUIT)
					close_window = true;
				if (e.type == SDL_EVENT_KEY_DOWN)
				{
					//if (SDLK_A && !app.getAppMenus().getTree().empty())
					//	std::cout << "Number A"<< "\n";
					std::cout  << e.key.scancode <<" scancode pressed\n";
					std::cout  << e.key.key <<" keycode pressed\n";
					size_t code = e.key.key - 48;
					std::cout  << "code " << code << "\nsize " << app.getMenuScreen().getCurrentMenu().size()<< "\n";
					//if (code < app.getMenuScreen().getCurrentMenu().size())
					//{
					//	app.getMenuScreen().changeCurrentMenu(app.getMenuScreen().getCurrentMenu()[code].sub);
					//}
					//if (e.key.key == SDLK_R)
					//	app.getMenuScreen().changeCurrentMenu(app.getMenuScreen().getCurrentMenu()[code].sub);

				}
				if (e.type == SDL_EVENT_KEY_DOWN && (e.key.scancode == 21 || (e.key.scancode >= 30 && e.key.scancode <= 39)))
				{
					size_t code = e.key.scancode;
					//std::cout << "Size " << app.getAppMenus().getTree().size() << '\n';
					//std::cout << "number " << code - 29;
					if (code == 21)
						app.setTheme("Burgundy");
					//	app.getMenuScreen().changeCurrentMenu(app.getAppMenus().getTree()[0].sub);
					//else if (app.getAppMenus().getTree().size() > (code - 29))
					//{
					//	app.getMenuScreen().changeCurrentMenu(app.getAppMenus().getTree()[code - 30].sub);
					//}
				}
		 	}

			SDL_SetRenderDrawColor(app.getRenderer(), theme.getBackground().r , theme.getBackground().g, theme.getBackground().b, SDL_ALPHA_OPAQUE);
			SDL_RenderClear(app.getRenderer());

		// *You would draw your game elements here*
			app.getMenuScreen().draw();

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
