#pragma once
#include "MenuButton.hpp"
#include "Color.hpp"
#include "Div.hpp"

class MainScreen {

private:
	std::vector<MenuButton>		_menu_buttons;
	int							_nbButtons;
	float						_menu_size;
	t_size						_window_size;
	t_pos						_starting_pos;
	Div							_div;

	Color						_main_color;
	Color						_inactive_color;

	std::vector<std::string>	_text_strings;


	void						_calculateStartingPos();


public:
	MainScreen();
	MainScreen(int nbButtons, t_size window_size, Color main_colour, Color incative_colour);


	void				draw();
	void				printInfo();

};
