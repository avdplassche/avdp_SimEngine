#pragma once
#include "MenuButton.hpp"
#include "Menu.hpp"
#include "Div.hpp"

class MainScreen {

private:
	std::vector<MenuButton>		_menu_buttons;
	int							_nbButtons;
	float						_menu_size;
	t_size						_window_size;
	t_pos						_starting_pos;
	Div							_div;

	Menu						_menu_tree;

	t_color						_default_color;
	t_color						_hover_color;
	t_color						_inactive_color;

	std::vector<std::string>	_text_strings;


	void						_calculateStartingPos();
	MainScreen();


public:
	MainScreen(Menu& menu_tree, t_mainScreenConfig& config);


	void				draw();
	void				printInfo();

};
