#pragma once
#include "MenuButton.hpp"
#include "MenuTree.hpp"
#include "Theme.hpp"
#include "Div.hpp"

class MainScreen {

private:
	std::vector<MenuButton>		_menu_buttons;
	int							_nbButtons;
	float						_menu_height;
	t_size						_window_size;
	t_pos						_starting_pos;

	SDL_Renderer				*_renderer;
	Div							_div;

	MenuTree					_menu_tree;

	t_color						_default_color;
	t_color						_hover_color;
	t_color						_inactive_color;

	std::vector<std::string>	_text_strings;


public:
	MainScreen();
	~MainScreen();

	void						setValues(MenuTree& menu_tree, t_mainScreenConfig& config);
	void						setTheme(Theme &);
	void						draw();


	std::vector<MenuButton>&	getMenuButtons();


	void						printInfo();

};
