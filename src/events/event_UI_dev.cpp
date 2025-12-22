#include "events.h"

void	handleUIDevEvents(SDL_Event *e, Application *app) {

	if (e->type == SDL_EVENT_MOUSE_MOTION)
	{
		app->setMousePos(e->motion.x, e->motion.y);
		SDL_FPoint point(app->getMousePos());
		for (size_t i = 0; i < app->getUIDevMatrice().getTable().size(); i++)
		{
			for (size_t j = 0; j < app->getUIDevMatrice().getTable()[i].size(); j++)
			{
				SDL_FRect *r = app->getUIDevMatrice().getTable()[i][j]->rect;
				if (SDL_PointInRectFloat(&point, r))
					app->getUIDevMatrice().setHovered(i, j);
			}
		}
	}
}