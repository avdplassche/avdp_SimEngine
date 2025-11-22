#pragma once

#include "pch.h"

//#define MENU_FILE "../../data/menu_dat1a.txt"



typedef struct s_menu
{
	std::string				content;
	std::vector<s_menu>		sub;
	s_menu					*parent;
	int						level;
	t_menuType				type;
}				t_menu;


class Menu {

private:

	std::vector<t_menu>		_menu;

	int						_getIndentationLevel(std::string line) const;
	void					_fillNodes(std::ifstream& ifstream, t_menu& root);
	void					_finalizeTypes(t_menu& node);

public:
	Menu();
	~Menu();

	void	load(std::string menu_filename);
	void	printMenu(std::vector<t_menu> menu);

	std::vector<t_menu>		getMenuTree() const;




};