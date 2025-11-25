#include "MenuTree.hpp"


MenuTree::MenuTree() {

}

MenuTree::~MenuTree() {

}



void	MenuTree::load(std::string menu_filename) {

	if (!_menu.empty())
		_menu.clear();

	std::ifstream	ifstream(menu_filename);

	if (!ifstream.is_open())
		throw (FileError(menu_filename));

	t_menu	root;

	root.level = -1;
	root.content = "ROOT";
	_fillNodes(ifstream, root);
	_finalizeTypes(root);
	_menu = std::move(root.sub);
	new_log("Menu loaded - " + menu_filename, GREEN_LOG);
}

void MenuTree::_fillNodes(std::ifstream& ifstream, t_menu& root) {

	std::vector<t_menu*> parent_stack;
	parent_stack.push_back(&root);

	char line_buffer[256];

	while (ifstream.getline(line_buffer, 256))
	{
		std::string sline(line_buffer);

		if (sline.find_first_not_of(" \t") == std::string::npos)
		{
			continue;
		}

		int new_level = _getIndentationLevel(sline);

		t_menu* current_parent = parent_stack.back();


		while (new_level <= current_parent->level && current_parent != &root) {
			parent_stack.pop_back();
			current_parent = parent_stack.back();
		}

		if (new_level <= root.level) {
			continue;
		}

		t_menu new_node;
		new_node.level = new_level;
		new_node.parent = current_parent;

		new_node.content = sline.substr(sline.find_first_not_of(" \t"));

		if (new_node.content.find("$cb") == 0)
		{
			new_node.type = CHECKBOX;
			new_node.content.erase(0, 3);
			new_node.content.erase(0, new_node.content.find_first_not_of(" \t"));
		}
		else {
			new_node.type = ROUTE;
		}

		current_parent->sub.push_back(new_node);

		if (new_level == current_parent->level + 1) {
			parent_stack.push_back(&current_parent->sub.back());
		}
		else if (new_level > current_parent->level + 1) {
		}
	}
}

void MenuTree::_finalizeTypes(t_menu& node) {
	if (!node.sub.empty()) {
		t_menu back_node;
		back_node.level = node.level + 1;
		back_node.parent = node.parent;
		if (node.level > -1)
		{
			back_node.content = "Back";
			back_node.type = BACK;
		}
		else
		{
			back_node.content = "Quit";
			back_node.type = QUIT;
		}
		node.sub.push_back(back_node);
		node.type = ROUTE;
		for (t_menu& child : node.sub) {
			_finalizeTypes(child);
		}
	}
	else if (node.type != CHECKBOX && node.type != QUIT && node.type != BACK) {
		node.type = ACTION;
	}
}

int	MenuTree::_getIndentationLevel(std::string line) const {

	int	i = 0;
	std::string::iterator it = line.begin();
	std::string::iterator ite = line.end();

	while (line[i] == '\t')
		i++;
	if (isspace(line[i]) && line[i] != '\t')
		throw MenuFileFormat(line);
	while (ite != it && isspace(*ite))
		line.erase(ite--);
	return i ;
}

std::vector<t_menu>	MenuTree::getTree() const {
	return _menu;
}

// Call it using printMenu(menu->getMenu())
void	MenuTree::printMenu(std::vector<t_menu> menu, bool first) {
	if (first)
		std::cout << "\n===== PRINT MENU TREE ====\n\n";
	for (size_t i = 0; i < menu.size(); i++)
	{
		for (int k = 0; k < menu[i].level; k++)
			std::cout << "	";
		std::cout << menu[i].level << " -> ";
		std::cout <<  menu[i].content;
		switch (menu[i].type)
		{
			case ROUTE:
				std::cout << " (ROUTE)\n";
				break;
			case CHECKBOX:
				std::cout << " (CHECKBOX)\n";
				break;
			case ACTION:
				std::cout << " (ACTION)\n";
				break;
			case QUIT:
				std::cout << " (QUIT)\n";
				break;
			case BACK:
				std::cout << " (BACK)\n";
				break;
			default:
				break;
		}
		if (!menu[i].sub.empty())
			printMenu(menu[i].sub, false);
	}
	if (first)
		std::cout << "\n===========================\n\n";
}


