#include "MenuButton.hpp"


MenuButton::MenuButton() {}

MenuButton::~MenuButton() {}

void		MenuButton::setValues(int x, int y, int width, int height, t_size window_size) {
	_window_size = window_size;
	_rect.w = width;
	_rect.h = height;
	_rect.x = x;
	_rect.y = y;
	TTF_GetTextSize(_text, &_text_size.w, &_text_size.h);
	_text_pos.x = x + width / 2 - _text_size.w / 2;
	_text_pos.y = y + height / 2 - _text_size.h / 2;
}


void		MenuButton::setText(std::string string, TTF_TextEngine* engine, TTF_Font* font) {
	_string = string;
	_text = TTF_CreateText(engine, font, string.c_str(), string.size());

}

void		MenuButton::setTheme(Theme& theme) {
	_default_color = &theme.getMenuDefault();
	_inactive_color = &theme.getMenuInactive();
	_hover_color = &theme.getMenuHover();
	_border_color = &theme.getMenuBorder();
	_text_color = &theme.getMenuText();
}



void	MenuButton::draw(SDL_Renderer *renderer) {

	SDL_FRect rendered_rec;
	SDL_RectToFRect(&_rect, &rendered_rec);


	SDL_SetRenderDrawColor(renderer, _default_color->r, _default_color->g,_default_color->b, 255);
	SDL_RenderFillRect(renderer, &rendered_rec);
	if (_hasBorder)
	{
		SDL_SetRenderDrawColor(renderer, _border_color->r, _border_color->g,_border_color->b, 255);
		SDL_RenderRect(renderer, &rendered_rec);
	}
	TTF_SetTextColor(_text, _text_color->r, _text_color->g,_text_color->b, 255);  // add theme color
	TTF_DrawRendererText(_text, _text_pos.x, _text_pos.y);
}

SDL_Rect	MenuButton::getRect() const {
	return _rect;
}

std::string	MenuButton::getString() const {
	return _string;
}


bool		MenuButton::isActive() const {
	return	_active;
}



