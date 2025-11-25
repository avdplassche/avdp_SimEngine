#pragma once

#include "AUIElement.hpp"
#include "Theme.hpp"
#include "pch.h"


class MenuButton : public AUIElement {

private:

	std::string				_text;
	t_color					*_default_color;
	t_color					*_inactive_color;
	t_color					*_hover_color;
	t_color					*_border_color;
	t_color					*_text_color;

	bool					_active;
	bool					_hasBorder;

	SDL_FRect				_rect;

	t_size					_window_size;


public:

	MenuButton();
	~MenuButton();


	void		setValues(int x, int y, int width, int height, t_size window_size);

	void		setText(std::string text);
	void		setTheme(Theme& theme);

	void		draw(SDL_Renderer *renderer);
	bool		isActive() const;


};

