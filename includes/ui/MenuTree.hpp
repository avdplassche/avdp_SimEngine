#pragma once

#include "pch.h"

class MenuTree {

private:

	std::vector<t_menu>		_menu;

	int						_getIndentationLevel(std::string line) const;
	void					_fillNodes(std::ifstream& ifstream, t_menu& root);
	void					_finalizeTypes(t_menu& node);

public:
	MenuTree();
	~MenuTree();

	void					load(std::string menu_filename);
	void					printMenu(std::vector<t_menu> menu, bool first);

	std::vector<t_menu>		getTree() const;




};