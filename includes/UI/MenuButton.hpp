#pragma once

#include "IUIElement.hpp"
#include "pch.h"
#include "Color.hpp"

class MenuButton : public IUIElement {

private:

	std::string				_text;
	t_pos					_pos;
	t_size					_size;
	t_pos					_coordinates[2][2];
	Color					_color;
	bool					_hasBorder;
	bool					_active;

	void					_setCoordinates();

public:

	MenuButton();
	~MenuButton();


	void		setValues(int x, int y, int width, int height);

	void		setPos(int x, int y);
	void		setSize(int width, int height);
	void		setText(std::string text);
	void		setColor(Color& color);


	void		draw();
	bool		hasBorder() const;
	bool		isActive() const;


};

