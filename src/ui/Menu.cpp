#include "Menu.hpp"


Menu::Menu() {

}

Menu::~Menu() {

}



void	Menu::loadMenus() {

	std::ifstream	ifstream(MENU_FILE);

	//char			*line;
	//int				old_inde = 0;
	//int				new_inde = 0;

	if (!ifstream.is_open())
		throw (FileError(MENU_FILE));

	t_menu	base;

	base.level = 0;
	base.current = "";
	_menu.push_back(base);

	_fillNodes(ifstream, _menu[0]);

	//while (ifstream.getline(line, 256))
	//{
	//	std::string sline(line);

	//	new_inde = _getIndentationLevel(sline);
	//	if (new_inde == old_inde)
	//	{
	//		t_menu	sub;

	//		sub.current = sline;
	//	}
	//	else if (new_inde > old_inde)
	//	{


	//	}


	//}

}

void	Menu::_fillNodes(std::ifstream& ifstream, t_menu& current) {

	char			line[256];
	int				new_level;

	if (ifstream.getline(line, 256).eof())
		return ;
	std::string sline(line);
	PRINT_DEBUG("line = " << sline);
	new_level = _getIndentationLevel(sline);
	PRINT_DEBUG("Indentation = " << new_level);


	if (new_level == current.level)
	{
		t_menu	sub;

		sub.current = sline;
		sub.level = new_level;
		current.sub.push_back(sub);
		_fillNodes(ifstream, current);
		return;
	}
	else if (new_level > current.level)
	{
		t_menu	sub;

		sub.current = sline;
		sub.level = new_level;
		current.sub.push_back(sub);
		_fillNodes(ifstream, current);
	}
	//else
	//{


	//}

}

int	Menu::_getIndentationLevel(std::string line) const {

	int	i = 0;
	std::string::iterator it = line.begin();
	std::string::iterator ite = line.end();

	while (line[i] == '\t')
		i++;
	if (isspace(line[i]) && line[i] != '\t')
		throw FileFormat(line);
	while (ite != it && isspace(*ite))
		line.erase(ite--);
	return i;
}


std::vector<t_menu>	Menu::getMenu() const {
	return _menu;
}

// Call it using printMenu(menu->getMenu())
void	Menu::printMenu(std::vector<t_menu> menu) {

	for (size_t i = 0; i < menu.size(); i++)
	{
		std::cout << menu[i].current;
		if (!menu[i].sub.empty())
		{
			std::cout << " -> ";
			printMenu(menu[i].sub);
		}
		std::cout << std::endl;
	}
}


