#pragma once

#include "IUIElement.hpp"
#include "pch.h"

class MenuButton : public IUIElement {

private:

	std::string			_text;
	//int					_x;
	//int					_y;
	//int					_width;
	//int					_height;
	//float				_coordinates[8];


public:

	MenuButton();
	MenuButton(std::string text);
	~MenuButton();


	//void		setPos(int x, int y);
	//void		setSize(int width, int height);
	void		draw();
	//bool		hasBorder();

};

