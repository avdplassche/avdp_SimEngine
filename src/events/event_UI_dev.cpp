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

	if (e->type == SDL_EVENT_MOUSE_BUTTON_DOWN && flag == SDL_BUTTON_LEFT)
	{
		//while (flag == SDL_BUTTON_LEFT)
		//{
			if (widget->getType() == SLIDER)
			{
				float	value = 0;
				float	val_diff = 0;
				float	px_diff = 0;

				if (widget->getOrientation() == 'h')
				{
					val_diff = widget->getUiData().max - widget->getUiData().min;
					px_diff = widget->getSize().w - SLIDER_PADDING * 2;
					value = (app->getMousePos().x - widget->getPos().x) * val_diff / px_diff;
					//debugPrintInt("mouse", app->getMousePos().x);
					//debugPrintInt("val_diff", val_diff);
					//debugPrintInt("px_diff", px_diff);
					//debugPrintInt("value", value);
				}
				else
					return;
				widget->setValue(value);
			}
		//	flag = SDL_GetMouseState(&x, &y);;
		//}

	}



	//if (e->type == SDL_EVENT_MOUSE_MOTION && flag == SDL_BUTTON_LEFT)
	//{
	//	AUIElement *widget = app->getUIDevMatrice().getHoveredElement();

	//	if (!widget)
	//		return ;
	//	if (widget->getType() == SLIDER)
	//	{
	//		float value;

	//		if (widget->getOrientation() == 'h')
	//			value = widget->getPos().x ;
	//		else
	//			value = widget->getPos().y + 1;
	//		widget->setValue(value);
	//	}
	//}

}

