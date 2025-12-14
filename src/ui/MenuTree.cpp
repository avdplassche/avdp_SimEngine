#include "MenuTree.hpp"


MenuTree::MenuTree() {
}

MenuTree::~MenuTree() {
}

void	MenuTree::load(std::string menu_filename) {

	std::ifstream	ifstream(menu_filename);

	if (!ifstream.is_open())
	{
		throw (FileError(menu_filename));
	}

	t_menu	*root = new t_menu;

	root->level = -1;
	root->content = "Root";
	root->parent = NULL;

	_fillNodes(ifstream, root);
	_finalizeTypes(root);
	_menu_tree = *root;
	printMenu(root->sub, true);
}

void MenuTree::_fillNodes(std::ifstream& ifstream, t_menu* root) {

	char	line_buffer[256];
	int		level = 0;

	while (ifstream.getline(line_buffer, 256))
	{
		std::string line(line_buffer);
		if (line.empty() || line[0] == '#')
			continue;
		level = _getIndentationLevel(line);

		t_menu	*new_node = new t_menu;

		new_node->level = level;
		new_node->content = line.substr(line.find_first_not_of("\t"));

		if (level > root->level)
		{
			new_node->parent = root;
			root->sub.push_back(new_node);
		}
		else if (level == root->level)
		{
			new_node->parent = root->parent;
			root->parent->sub.push_back(new_node);
		}
		else if (level < root->level)
		{
			t_menu	*parent = root->parent;

			while (level != parent->level)
				parent = parent->parent;
			new_node->parent = parent->parent;
			parent->parent->sub.push_back(new_node);
		}
		_fillNodes(ifstream, new_node);
	}
}

void MenuTree::_finalizeTypes(t_menu *node) {

	if (node->content.find("$cb") == 0)
	{
		node->content.erase(0, 4);
		node->type = CHECKBOX;
		return ;
	}
	if (node->sub.empty())
	{
		node->type = ACTION;
		return ;
	}
	node->type = ROUTE;
	for (size_t i = 0; i < node->sub.size(); i++)
	{
		_finalizeTypes(node->sub[i]);
		//printNode(*node->sub[i]);
	}
	t_menu	*exit_node = new t_menu;

	exit_node->level = node->level + 1;
	if (node->level >= 0)
	{
		exit_node->type = BACK;
		exit_node->content = "Back";
	}
	else if (node->level == -1)
	{
		exit_node->type = QUIT;
		exit_node->content = "Quit";
	}
	exit_node->parent = node;
	node->sub.push_back(exit_node);
}

int	MenuTree::_getIndentationLevel(std::string& line) const {

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

t_menu	MenuTree::getTree() const {
	return _menu_tree;
}

void	MenuTree::printNode(t_menu& menu)
{
	std::cout << "===== Print Node =====\n\n";
	std::cout << "Content : " << menu.content << "\n";
	std::cout << "Level : " << menu.level << "\n";
	if (menu.level >= 0)
		std::cout << "Parent : " << menu.parent->content << "\n";
	std::cout << "Type : " << menu.type << "\n";
	std::cout << "Sub : ";
	for (size_t i = 0; i < menu.sub.size(); i++)
		std::cout << menu.sub[i]->content << " ";
	std::cout << "\n\n=======================\n\n";
}


// Call it using printMenu(menu->getMenu())
void	MenuTree::printMenu(std::vector<t_menu *> menu, bool first) {
	if (first)
		std::cout << "\n===== PRINT MENU TREE ====\n\n";
	for (size_t i = 0; i < menu.size(); i++)
	{
		std::cout << menu[i]->parent->content << "		";
		for (int k = 0; k < menu[i]->level; k++)
			std::cout << "	";
		std::cout << menu[i]->level << " -> ";
		std::cout <<  menu[i]->content;
		switch (menu[i]->type)
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
		if (!menu[i]->sub.empty())
			printMenu(menu[i]->sub, false);
	}
	if (first)
		std::cout << "\n===========================\n\n";
}

