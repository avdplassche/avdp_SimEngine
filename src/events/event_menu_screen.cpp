#include "events.h"


void	handleMenuScreenEvents(SDL_Event *e, Application *app) {
	if (e->type == SDL_EVENT_MOUSE_MOTION)
	{
		app->setMousePos(e->motion.x, e->motion.y);
		SDL_FPoint point(app->getMousePos());
		for (auto it = app->getMenuScreen().getMenuButtons().begin(); it != app->getMenuScreen().getMenuButtons().end(); ++it) {
			SDL_FRect r = it->getRect();
			if (SDL_PointInRectFloat(&point, &r))
			{
				if (it->getState() == BUTTON_STATE_DEFAULT)
					it->setState(BUTTON_STATE_HOVER);
				else if (it->getState() == BUTTON_STATE_HOVER)
					return ;
				return ;
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
		SDL_FPoint point(app->getMousePos());
		for (auto it = app->getMenuScreen().getMenuButtons().begin(); it != app->getMenuScreen().getMenuButtons().end(); ++it)
		{
			SDL_FRect r = it->getRect();
			if (SDL_PointInRectFloat(&point, &r))
			{
				if (it->getState() == BUTTON_STATE_HOVER)
				{
					switch (it->getMenu()->type)
					{
					case MENU_ROUTE:
						app->getMenuScreen().changeCurrentMenu(it->getMenu());
						return ;
					case MENU_BACK:
						app->getMenuScreen().changeCurrentMenu(it->getMenu()->parent->parent);
						return ;
					case MENU_THEME:
						app->setTheme(it->getMenu()->content);
						return ;
					case MENU_ACTION:
						if (it->getMenu()->content == "UI Matrice")
						{
							app->setState(APP_STATE_UI_DEV);
							newLog("TEST - Entered UI Dev State", INFO_LOG);
						}
                        else if (it->getMenu()->content == "Simulation 01")
                        {
                            int					w,h;
                            std::stringstream	ss;
		                    SDL_GetWindowSize(app->getWindow(), &w, &h);
                            app->getSimulationOne().setWindowSize({w, h});
                            app->getSimulationOne().updateWidgetValues();
                            app->setState(APP_STATE_SIMULATION_ONE);
                            newLog("TEST - Entered Sim one", INFO_LOG);
                        }
						return ;
					case MENU_QUIT:
						app->quit();
						return ;
					default:
						break;
					}
				}
			}
		}
	}
}

