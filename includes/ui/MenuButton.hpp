#pragma once

#include "AUIElement.hpp"
#include "pch.h"
#include "Color.hpp"

class MenuButton : public AUIElement {

private:

	std::string				_text;
	t_pos					_coordinates[2][2];
	Color					_color;
	Color					_inactiveColor;
	bool					_active;

	t_size					_window_size;

	void					_setCoordinates();

public:

	MenuButton();
	~MenuButton();


	void		setValues(int x, int y, int width, int height, t_size window_size);

	void		setText(std::string text);
	void		setColor(Color& color);


	void		draw();
	bool		isActive() const;

	void		printCoordinates();

};

