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
	bool				isEmpty = true;

	path << "themes/" << name << ".theme";

	std::ifstream is(path.str());

	if (!is.is_open())
		newLog("Unabled to load theme (filenor open) - " + name, WARNING_LOG);

	while (getline(is, buffer))
	{
		std::stringstream	ss(buffer);
		t_color				c;

		if (buffer.empty())
			continue ;
		isEmpty = false;
		ss >> key;
		if (key[0] == '#')
			continue ;
		ss >> val;
		if (!_checkValue(val))
			return newLog("Unable to load theme (value format error) - " + name, WARNING_LOG);
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
		else if (key == "ui_box_text")
			_ui_box_text_color = c;
		else if (key == "ui_plain_text")
			_ui_plain_text_color = c;
		else
			return newLog("Unable to load theme (key format error) - " + name, WARNING_LOG);
	}
	if (isEmpty)
		return newLog("Unable to load theme (empty file) - " + name, WARNING_LOG);
	_name = name;
	newLog((name + " theme loaded"), INFO_LOG);
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

t_color&	Theme::getUIBoxText() {
	return _ui_box_text_color;
}

t_color&	Theme::getUIPlainText() {
	return _ui_plain_text_color;
}

std::string	Theme::getName() const {
	return _name;
}

bool	Theme::_checkValue(std::string val) {
	std::string::iterator it = val.begin() + 1;

	while (it != val.end())
	{
		if (!isdigit(*it) && !('a' <= *it && *it <= 'f') && !('A' <= *it && *it <= 'F'))
			return 0;
		it++;
	}
	return 1;
}

bool	Theme::_checkFieldPresence() {

	std::stringstream	ss;
	bool				error = false;

	ss << "Unable to load theme " << _name << " - ";
	if (_background_color.r == -1 || _background_color.g == -1 || _background_color.b == -1)
	{
		ss << "background ";
		error = true;
	}
	else if (_menu_default_color.r == -1 || _menu_default_color.g == -1 || _menu_default_color.b == -1)
	{
		ss << "menu_default ";
		error = true;
	}
	else if (_menu_hover_color.r == -1 || _menu_hover_color.g == -1 || _menu_hover_color.b == -1)
	{
		ss << "menu_hover ";
		error = true;
	}
	else if (_menu_inactive_color.r == -1 || _menu_inactive_color.g == -1 || _menu_inactive_color.b == -1)
	{
		ss << "menu_inactive ";
		error = true;
	}
	else if (_menu_border_color.r == -1 || _menu_border_color.g == -1 || _menu_border_color.b == -1)
	{
		ss << "menu_border ";
		error = true;
	}
	else if (_menu_text_color.r == -1 || _menu_text_color.g == -1 || _menu_text_color.b == -1)
	{
		ss << "menu_text ";
		error = true;
	}
	else if (_ui_default_color.r == -1 || _ui_default_color.g == -1 || _ui_default_color.b == -1)
	{
		ss << "ui_color ";
		error = true;
	}
	else if (_ui_border_color.r == -1 || _ui_border_color.g == -1 || _ui_border_color.b == -1)
	{
		ss << "ui_border ";
		error = true;
	}
	if (error)
	{
		newLog(ss.str() + "field missing", WARNING_LOG);
		return false;
	}
	return true;
}

