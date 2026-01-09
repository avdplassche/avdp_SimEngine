#include "events.h"


void	handleEvents(SDL_Event *e, Application *app) {

	handleGeneralEvents(e, app);

	int state = app->getState();
	switch (state)
	{
		case APP_STATE_MAIN_MENU:
			handleMenuScreenEvents(e, app);
			break;
		case APP_STATE_UI_DEV:
			handleUIDevEvents(e, app);
			break;
	}
}


void	handleGeneralEvents(SDL_Event *e, Application *app) {
	if (e->type == SDL_EVENT_QUIT || e->key.scancode == SDL_SCANCODE_ESCAPE)
		return (app->quit());
	else if (e->type == SDL_EVENT_KEY_DOWN && e->key.scancode == SDL_SCANCODE_R)
		return (app->switchTheme());
	else if (e->type == SDL_EVENT_WINDOW_RESIZED)
	{
		int					w,h;
		std::stringstream	ss;

		SDL_GetWindowSize(app->getWindow(), &w, &h);
		if (w < 300 || h < 300)
			newLog("Window size may be too low", WARNING_LOG);
		ss << "Window size set to [" << std::to_string(w) << "," << std::to_string(h) << "]";
		newLog(ss.str(), DEBUG_LOG);
		if (app->getState() == APP_STATE_UI_DEV)
			app->getUIDevMatrice().setDevSize(w, h);
		else if (app->getState() == APP_STATE_MAIN_MENU)
			app->getMenuScreen().setWindowSize(w, h);
		else if (app->getState() == APP_STATE_SIMULATION_ONE)
			app->getSimulationOne().getUiMatrice().setWindowSize(w, h);
		return ;
	}
}
