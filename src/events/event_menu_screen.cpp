#include "events.h"


void	handleMenuScreenEvents(SDL_Event *e, Application *app) {
	if (e->type == SDL_EVENT_MOUSE_MOTION)
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
		SDL_Point point(app->getMousePos());
		for (auto it = app->getMenuScreen().getMenuButtons().begin(); it != app->getMenuScreen().getMenuButtons().end(); ++it)
		{
			SDL_Rect r = it->getRect();
			if (SDL_PointInRect(&point, &r))
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

