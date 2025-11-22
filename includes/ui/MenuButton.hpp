#pragma once

#include "AUIElement.hpp"
#include "pch.h"


class MenuButton : public AUIElement {

private:

	std::string				_text;
	t_pos					_coordinates[2][2];
	t_color					_color;
	t_color					_hoverColor;
	bool					_active;

	t_size					_window_size;

	void					_setCoordinates();

public:

	MenuButton();
	~MenuButton();


	void		setValues(int x, int y, int width, int height, t_size window_size);

	void		setText(std::string text);
	void		setColor(t_color& color);


	void		draw();
	bool		isActive() const;

	void		printCoordinates();

};

