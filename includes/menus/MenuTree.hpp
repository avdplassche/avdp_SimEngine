#pragma once

#include "pch.h"

class MenuTree {

private:

	t_menu					_menu_tree;

	int						_getIndentationLevel(std::string& line) const;
	void					_fillNodes(std::ifstream& ifstream, t_menu* root);
	void					_finalizeTypes(t_menu *node, std::vector<std::string> *_theme_list);

public:
	MenuTree();
	~MenuTree();

	void					load(std::string menu_filename, std::vector<std::string> *_theme_list);
	void					printMenu(std::vector<t_menu *> menu, bool first);

	t_menu					getTree() const;

	void					printNode(t_menu& menu);
	//void					_deleteMenu(std::vector<t_menu *> menu);


};