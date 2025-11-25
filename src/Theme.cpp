#include "Theme.hpp"


Theme::Theme() {
	_background_color = newColor(0, 0, 0, 100);
	_menu_default_color = newColor(255, 255, 255, 100);
	_menu_hover_color = newColor (180, 180, 180, 100);
	_menu_inactive_color = newColor (100, 100, 100, 100);;
	_menu_border_color = newColor (100, 100, 100, 255);
	_menu_text_color = newColor (0, 0, 0, 255);
	_ui_default_color = newColor (0, 0, 0, 255);
	_ui_border_color = newColor (255, 255, 255, 255);
}

Theme::~Theme() {}

Theme& Theme::operator=(const Theme& source) {
	if (this == &source)
		return *this;
	_background_color = source._background_color;
	_menu_default_color = source._menu_default_color;
	_menu_hover_color = source._menu_hover_color;
	_menu_inactive_color = source._menu_inactive_color;
	return *this;
}

void	Theme::setTheme(std::string name) {
	std::stringstream	path;
	std::stringstream	ss;
	std::string			buffer;
	std::string			key;
	std::string			val;
	//Theme				theme;


	path << "themes/" << name << ".conf";

	std::ifstream is(path.str());

	if (!is.is_open())
		new_log("Unabled to load theme " + name, RED_LOG);

	while (getline(is, buffer))
	{
		std::stringstream	ss(buffer);
		t_color				c;

		if (buffer.empty())
			continue ;
		ss >> key;
		if (key[0] == '#')
			continue ;
		ss >> val;
		if (!checkValue(val))
			return new_log("Unabled to load theme (value format error) " + name, RED_LOG);
		c = colorHexToInt(val);
		if (key == "background")
			_background_color = c;
		else if (key == "menu_default")
			_menu_default_color = c;
		else if (key == "menu_hover")
			_menu_hover_color = c;
		else if (key == "menu_inactive")
			_menu_inactive_color = c;
		else if (key == "menu_border")
			_menu_border_color = c;
		else if (key == "menu_text")
			_menu_text_color = c;
		else if (key == "ui_color")
			_ui_default_color = c;
		else if (key == "ui_border")
			_ui_border_color = c;
		else
			return new_log("Unabled to load theme (key format error) " + name, RED_LOG);
	}
	//*this = theme;
	new_log(("Theme loaded - " + name), GREEN_LOG);
}

bool	Theme::checkValue(std::string val) {
	std::string::iterator it = val.begin() + 1;

	while (it != val.end())
	{
		if (!isdigit(*it) && !('a' <= *it && *it <= 'f') && !('A' <= *it && *it <= 'F'))
		{
			std::cout << "HERE " << val << '\n';
			return 0;
		}
		it++;
	}
	return 1;
}


t_color&	Theme::getBackground() {
	return _background_color;
}

t_color&	Theme::getMenuDefault() {
	return _menu_default_color;
}

t_color&	Theme::getMenuHover() {
	return _menu_hover_color;
}

t_color&	Theme::getMenuInactive() {
	return _menu_inactive_color;
}

t_color&	Theme::getMenuBorder() {
	return _menu_border_color;
}

t_color&	Theme::getMenuText() {
	return _menu_text_color;
}

t_color&	Theme::getUIDefault() {
	return _ui_default_color;
}

t_color&	Theme::getUIBorder() {
	return _ui_border_color;
}
