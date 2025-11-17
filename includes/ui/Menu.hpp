#pragma once

#include "pch.h"

#define MENU_FILE "data/menu_data.txt"


typedef struct s_menu
{
	std::string				current;
	std::vector<s_menu>		sub;
	int						level;
}				t_menu;


class Menu {

private:

	std::vector<t_menu>		_menu;

	int						_getIndentationLevel(std::string line) const;
	void					_fillNodes(std::ifstream& ifstream, t_menu& current);

public:
	Menu();
	~Menu();

	void	loadMenus();
	void	printMenu(std::vector<t_menu> menu);

	std::vector<t_menu>		getMenu() const;




};