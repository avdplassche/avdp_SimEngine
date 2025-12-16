#include "tests.h"
#include "uiSkeleton.hpp"
#include "MenuScreen.hpp"
#include "MenuTree.hpp"

extern volatile sig_atomic_t g_run;

int	handleEvents(SDL_Event *e, Application *app) {

	if (e->type == SDL_EVENT_KEY_DOWN)
	{
		//if (SDLK_A && !app.getAppMenus().getTree().empty())
		//	std::cout << "Number A"<< "\n";
		//std::cout  << e->key.scancode <<" scancode pressed\n";
		//std::cout  << e->key.key <<" keycode pressed\n";
		//size_t code = e->key.key - 48;
		//std::cout  << "code " << code << "\nsize " << app.getMenuScreen().getCurrentMenu().sub.size()<< "\n";
	}
	if (e->type == SDL_EVENT_KEY_DOWN && (e->key.scancode == 21 || (e->key.scancode >= 30 && e->key.scancode <= 39)))
	{
		size_t code = e->key.scancode;
		if (code == 21)
			app->switchTheme();
	}
	else if (e->type == SDL_EVENT_WINDOW_RESIZED)
	{
		int					w,h;
		std::stringstream	ss;

		SDL_GetWindowSize(app->getWindow(), &w, &h);
		if (w < 300 || h < 300)
			newLog("Window size may be too low", WARNING_LOG);
		ss << "Size set to [" << std::to_string(w) << "," << std::to_string(h) << "]";
		newLog(ss.str(), DEBUG_LOG);
		if (app->getState() == APP_STATE_UI_DEV)
			app->getUIDevMatrice().setSize(w, h);
		else if (app->getState() == APP_STATE_MAIN_MENU)
			app->getMenuScreen().setWindowSize(w, h);
	}
	else if (e->type == SDL_EVENT_MOUSE_MOTION)
	{
		app->setMousePos(e->motion.x, e->motion.y);
		SDL_Point point(app->getMousePos());
		for (auto it = app->getMenuScreen().getMenuButtons().begin(); it != app->getMenuScreen().getMenuButtons().end(); ++it) {
			SDL_Rect r = it->getRect();
			if (SDL_PointInRect(&point, &r))
			{
				if (it->getState() == BUTTON_STATE_DEFAULT)
					it->setState(BUTTON_STATE_HOVER);
				else if (it->getState() == BUTTON_STATE_HOVER)
					return 0;
				return 0;
			}
			else
			{
				if (it->getState() == BUTTON_STATE_HOVER)
					it->setState(BUTTON_STATE_DEFAULT);
			}
		}
	}
	else if (e->type == SDL_EVENT_MOUSE_BUTTON_UP)
	{
		SDL_Point point(app->getMousePos());
		for (auto it = app->getMenuScreen().getMenuButtons().begin(); it != app->getMenuScreen().getMenuButtons().end(); ++it) {
			SDL_Rect r = it->getRect();
			if (SDL_PointInRect(&point, &r))
			{
				if (it->getState() == BUTTON_STATE_HOVER)
				{
					switch (it->getMenu()->type)
					{
					case MENU_ROUTE:
						app->getMenuScreen().changeCurrentMenu(it->getMenu());
						return 0;
					case MENU_BACK:
						app->getMenuScreen().changeCurrentMenu(it->getMenu()->parent->parent);
						return 0;
					case MENU_THEME:
						app->setTheme(it->getMenu()->content);
						return 0;
					case MENU_ACTION:
						if (it->getMenu()->content == "UI Matrice")
						{
							app->setState(APP_STATE_UI_DEV);
							newLog("TEST - Entered UI Dev State", INFO_LOG);
						}
						return 0;
					case MENU_QUIT:
						return 1;
					default:
						break;
					}
				}
			}
		}
	}

	return 0;
}


int	runUITests(Application &app) {

	Theme&		theme = app.getTheme();
	bool		close_window = false;
	SDL_Event	e;

	newLog("TEST - Window loop ready", INFO_LOG);
	newLog("TEST - Entered Main Screen State", INFO_LOG);
	app.setState(APP_STATE_UI_DEV);

	//app.getAppMenus().printMenu(app.getAppMenus().getTree(), true);

	try {

		while (!close_window && g_run)
		{
			while (SDL_PollEvent(&e)) {
				if (e.type == SDL_EVENT_QUIT || handleEvents(&e, &app))
					close_window = true;
		 	}

			SDL_SetRenderDrawColor(app.getRenderer(), theme.getBackground().r , theme.getBackground().g, theme.getBackground().b, SDL_ALPHA_OPAQUE);
			SDL_RenderClear(app.getRenderer());

		// *You would draw your game elements here*
			if (app.getState() == APP_STATE_MAIN_MENU)
				app.getMenuScreen().draw();
			else if (app.getState() == APP_STATE_UI_DEV)
				app.getUIDevMatrice().draw();

			SDL_RenderPresent(app.getRenderer());
			//app.processInput();


			//c.draw();

		}
		newLog("Ending Game Loop", INFO_LOG);
	}
	catch (std::exception &e) {
		std::cerr << e.what();
		return 1;
	}
	return 0;
}
