#include "events.h"

void	handleUIDevEvents(SDL_Event *e, Application *app, UIMatrice *uiMatrix) {

	float					x, y = 0;
	SDL_MouseButtonFlags	button_flag = SDL_GetMouseState(&x, &y);;
	bool					mouseInMatrice = false;

	app->setMousePos(x, y);
	SDL_FPoint	point(app->getMousePos());

	if (e->type == SDL_EVENT_MOUSE_MOTION)
	{
		for (size_t i = 0; i < uiMatrix->getTable().size(); i++)
		{
			for (size_t j = 0; j < uiMatrix->getTable()[i].size(); j++)
			{
				if (SDL_PointInRectFloat(&point, uiMatrix->getTable()[i][j]->rect))
				{
					uiMatrix->setHovered(i, j);
					mouseInMatrice = true;
					break ;
				}
			}
			if (mouseInMatrice)
				break ;
		}
		if (mouseInMatrice == false)
		{
			uiMatrix->setHovered(-1, -1);
            
		}
	}

    AUIElement *widget = nullptr;
    if (app->getState() == APP_STATE_SIMULATION_ONE) {
        widget = uiMatrix->getHoveredElement();
    }
    else {
        widget = app->getUIDevMatrice().getHoveredElement();
    }
	if (!widget)
		return ;

	if (button_flag == SDL_BUTTON_LEFT)
	{
		if (widget->getType() == SLIDER)
			widget->setValue(app->getMousePos());
		else if (widget->getType() == SPINNER)
			widget->setValue(app->getMousePos());
		else if (widget->getType() == CHECK_BOX)
			widget->setValue(app->getMousePos());
		else if (widget->getType() == TOGGLE_BOX)
			widget->setValue(app->getMousePos());
        app->getSimulationOne().updateWidgetValues();
	}
}

