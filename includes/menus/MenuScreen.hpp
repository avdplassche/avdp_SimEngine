#pragma once
#include "MenuButton.hpp"
#include "MenuTree.hpp"
#include "Theme.hpp"
#include "Div.hpp"
#include "pch.h"

class MenuScreen {

private:
	SDL_Renderer				*_renderer;
	TTF_TextEngine				*_text_engine;
	TTF_Font					*_font;
	Theme						*_theme;
	t_color						*_background_color;

	t_menu						_current_menu;
	int							_nbButtons;


	float						_menu_height;
	t_pos						_starting_pos;

	std::vector<MenuButton>		_menu_buttons;
	t_size						_window_size;


	Div							_div;
	t_padding					_div_padding;


	std::vector<std::string>	_text_strings;

	void						_setConfig(t_MenuScreenConfig &conf);
	void						_setMenuTree(MenuTree& menu_tree);
	void						_setMenuData();
	void						_setDiv();
	void						_setButtons();

	void						_printChangeMenuInfo();
	void						_printButtonList();


public:
	MenuScreen();
	~MenuScreen();

	void						setValues(MenuTree& menu_tree, t_MenuScreenConfig& config);
	void						setTheme(Theme&);

	void						changeCurrentMenu(t_menu *current_menu);

	void						draw();

	void						setWindowSize(int w, int h);

	std::vector<MenuButton>&	getMenuButtons();
	t_menu&						getCurrentMenu();


	void						printInfo();

};
