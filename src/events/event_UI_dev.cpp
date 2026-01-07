#include "events.h"

void	handleUIDevEvents(SDL_Event *e, Application *app) {

	float					x, y = 0;
	SDL_MouseButtonFlags	flag = SDL_GetMouseState(&x, &y);;
	bool					mouseInMatrice = false;

	app->setMousePos(x, y);
	SDL_FPoint	point(app->getMousePos());

	if (e->type == SDL_EVENT_MOUSE_MOTION)
	{
		for (size_t i = 0; i < app->getUIDevMatrice().getTable().size(); i++)
		{
			for (size_t j = 0; j < app->getUIDevMatrice().getTable()[i].size(); j++)
			{
				SDL_FRect *r = app->getUIDevMatrice().getTable()[i][j]->rect;
				if (SDL_PointInRectFloat(&point, r))
				{
					app->getUIDevMatrice().setHovered(i, j);
					mouseInMatrice = true;
				}
			}
		}
		if (mouseInMatrice == false)
		{
			app->getUIDevMatrice().setHovered(-1, -1);
		}
	}
	AUIElement *widget = app->getUIDevMatrice().getHoveredElement();
	if (!widget)
		return ;

	if (flag == SDL_BUTTON_LEFT)
	{
		if (widget->getType() == SLIDER)
		{
			float	value = 0;
			float	val_diff = widget->getUiData().max - widget->getUiData().min;
			float	px_diff = 0;

			if (widget->getOrientation() == 'h')
			{
				px_diff = widget->getSize().w - SLIDER_PADDING * 2;
				value = (app->getMousePos().x - widget->getPos().x) * val_diff / px_diff;
			}
			else if (widget->getOrientation() == 'v')
			{
				px_diff = widget->getSize().h - SLIDER_PADDING * 2;
				value = (app->getMousePos().y - widget->getPos().y) * val_diff / px_diff;
			}
			else
				return;
			widget->setValue(value);
		}
	}
}

