#pragma once

#include "pch.h"


class Theme {

private:
	t_color				_background_color;
	t_color				_menu_default_color;
	t_color				_menu_hover_color;
	t_color				_menu_inactive_color;


public:

	Theme();
	~Theme();
	Theme& operator=(const Theme&);
	//Theme(std::string file, std::string name);

	void				setTheme(std::string name);

	bool				checkValue(std::string val);

	//void				setBackgroundColor(t_color& c);
	//void				setMenuDefaultColor(t_color& c);
	//void				setMenuHoverColor(t_color& c);
	//void				setMenuInactiveColor(t_color& c);
	t_color&			getBackground();
	t_color&			getMenuDefault();
	t_color&			getMenuHover();
	t_color&			getMenuInactive();
};