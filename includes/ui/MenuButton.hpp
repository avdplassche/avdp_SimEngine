#pragma once

#include "AUIElement.hpp"
#include "pch.h"


class MenuButton : public AUIElement {

private:

	std::string				_text;
	t_pos					_coordinates[2][2];
	t_color					_default_color;
	t_color					_border_color;
	//t_color					_hover_color;

	bool					_active;
	bool					_hasBorder;

	SDL_FRect				_rect;

	t_size					_window_size;

	//void					_setCoordinates();

public:

	MenuButton();
	~MenuButton();


	void		setValues(int x, int y, int width, int height, t_size window_size);

	void		setText(std::string text);
	void		setColor(t_color& color);


	void		draw(SDL_Renderer *renderer);
	bool		isActive() const;

	void		printCoordinates();

};

