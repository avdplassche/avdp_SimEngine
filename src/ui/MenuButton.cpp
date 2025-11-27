#include "MenuButton.hpp"


MenuButton::MenuButton() {}

MenuButton::~MenuButton() {}

void		MenuButton::setValues(int x, int y, int width, int height, t_size window_size) {
	_pos.x = x;
	_pos.y = y;
	_size.w = width;
	_size.h = height;
	_window_size = window_size;
}


void		MenuButton::setText(std::string string, TTF_TextEngine* engine, TTF_Font* font) {
	_string = string;
	_text = TTF_CreateText(engine, font, string.c_str(),  string.size());

}

void		MenuButton::setTheme(Theme& theme) {
	_default_color = &theme.getMenuDefault();
	_inactive_color = &theme.getMenuInactive();
	_hover_color = &theme.getMenuHover();
	_border_color = &theme.getMenuBorder();
	_text_color = &theme.getMenuText();
}


void	MenuButton::draw(SDL_Renderer *renderer) {
	_rect.w = _size.w;
	_rect.h = _size.h;
	_rect.x = _pos.x;
	_rect.y = _pos.y;
	SDL_SetRenderDrawColor(renderer, _default_color->r, _default_color->g,_default_color->b, 255);
	SDL_RenderFillRect(renderer, &_rect);
	if (_hasBorder)
	{
		SDL_SetRenderDrawColor(renderer, _border_color->r, _border_color->g,_border_color->b, 255);
		SDL_RenderRect(renderer, &_rect);
	}
	TTF_SetTextColor(_text, _text_color->r, _text_color->g,_text_color->b, 255);  // add theme color
	TTF_DrawRendererText(_text, _rect.x, _rect.y);
}

bool		MenuButton::isActive() const {
	return	_active;
}

