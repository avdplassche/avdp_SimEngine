#pragma once
#include "MenuButton.hpp"


class MainScreen {

private:
	MenuButton			_menu_buttons[5];  // ask mydelf how could I do to go deeper (ex settings)
	int					_nbButtons;

public:
	void				draw();


};
