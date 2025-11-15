#pragma once
#include "MenuButton.hpp"
#include "Color.hpp"

class MainScreen {

private:
	std::vector<MenuButton>		_menu_buttons;
	//MenuButton			_menu_buttons[5];  // ask mydelf how could I do to go deeper (ex settings)
	int					_nbButtons;
	int					_buttonWidth;
	int					_buttonHeight;


public:
	MainScreen(int nbButtons, int buttonWidth, int buttonHeight);
	void				draw();


};
