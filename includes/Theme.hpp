#pragma once

#include "pch.h"


class Theme {

private:
	std::string			_name;
	t_color				_background_color = {-1, -1, -1, 0};
	t_color				_menu_default_color = {-1, -1, -1, 0};
	t_color				_menu_hover_color = {-1, -1, -1, 0};
	t_color				_menu_inactive_color = {-1, -1, -1, 0};
	t_color				_menu_border_color = {-1, -1, -1, 0};
	t_color				_menu_text_color = {-1, -1, -1, 0};
	t_color				_ui_default_color = {-1, -1, -1, 0};
	t_color				_ui_border_color = {-1, -1, -1, 0};

	//t_color				_shadow_color;
	bool				_checkValue(std::string val);
	bool				_checkFieldPresence();

public:

	Theme();
	~Theme();
	Theme& operator=(const Theme&);

	void				setTheme(std::string name);


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
