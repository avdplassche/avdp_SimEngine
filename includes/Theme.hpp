#pragma once

#include "pch.h"


class Theme {

private:
	std::string			_name;
	t_color				_background_color;
	t_color				_menu_default_color;
	t_color				_menu_hover_color;
	t_color				_menu_inactive_color;
	t_color				_menu_border_color;
	t_color				_menu_text_color;
	t_color				_ui_default_color;
	t_color				_ui_border_color;

public:

	Theme();
	~Theme();
	Theme& operator=(const Theme&);

	void				setTheme(std::string name);

	bool				checkValue(std::string val);

	t_color&			getBackground();
	t_color&			getMenuDefault();
	t_color&			getMenuHover();
	t_color&			getMenuInactive();
	t_color&			getMenuBorder();
	t_color&			getMenuText();
	t_color&			getUIDefault();
	t_color&			getUIBorder();

	std::string			getName() const;
};
