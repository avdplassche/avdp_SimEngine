#pragma once

#include "AUIElement.hpp"
#include "Theme.hpp"
#include "pch.h"


class MenuButton : public AUIElement {

private:

	std::string				_string;
	TTF_Text				*_text = NULL;
	t_color					*_default_color;
	t_color					*_inactive_color;
	t_color					*_hover_color;
	t_color					*_border_color;
	t_color					*_text_color;

	t_color					*_current_color;

	t_buttonState			_state;
	bool					_hasBorder;

	SDL_FRect				_rect;

	t_size					_window_size;
	t_pos					_text_pos;
	t_size					_text_size;

	t_menu					*_menu = NULL;

public:

	MenuButton();
	~MenuButton();


	void			setValues(int x, int y, int width, int height, t_size window_size);

	void			setText(std::string text, TTF_TextEngine* engine, TTF_Font* font);
	void			setTheme(Theme& theme);
	void			setState(t_buttonState);
	void			setMenu(t_menu *menu);


	std::string		getString() const;
	SDL_FRect		getRect() const;
	t_menu			*getMenu();
	//bool			isHover() const;

	void			draw(SDL_Renderer *renderer, t_color *color);
	bool			getState() const;


};

