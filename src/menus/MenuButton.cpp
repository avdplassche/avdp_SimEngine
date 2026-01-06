#include "MenuButton.hpp"


MenuButton::MenuButton() {}

MenuButton::~MenuButton() {}

void	MenuButton::draw(SDL_Renderer *renderer) {

	if (_state == BUTTON_STATE_HOVER)
		_current_color = _hover_color;
	else if (_state == BUTTON_STATE_DEFAULT)
		_current_color = _default_color;
	if (MENU_HAS_SHADOW)
	{
		SDL_FRect shadow(_rect);
		shadow.x += MENU_SHADOW_X;
		shadow.y -= MENU_SHADOW_Y;
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderFillRect(renderer, &shadow);
	}
	SDL_SetRenderDrawColor(renderer, _current_color->r, _current_color->g,_current_color->b, 255);
	SDL_RenderFillRect(renderer, &_rect);
	if (_hasBorder)
	{
		SDL_SetRenderDrawColor(renderer, _border_color->r, _border_color->g,_border_color->b, 255);
		SDL_RenderRect(renderer, &_rect);
	}
	TTF_SetTextColor(_text, _text_color->r, _text_color->g,_text_color->b, 255);  // add theme color
	TTF_DrawRendererText(_text, _text_pos.x, _text_pos.y);
}


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

void		MenuButton::setState(t_buttonState state) {
	_state = state;
	switch (state)
	{
		case BUTTON_STATE_DEFAULT:
			_current_color = _default_color;
			break;
		case BUTTON_STATE_HOVER:
			_current_color = _hover_color;
			break;
		case BUTTON_STATE_INACTIVE:
			_current_color = _inactive_color;
			break;
		default:
			break;
	}
}

void	MenuButton::setData(t_pos pos, t_size size) {
	_size.w = size.w;
	_size.h = size.h;
	_rect.w = size.w;
	_rect.h = size.h;
	_pos.x = pos.x;
	_pos.y = pos.y;
	_rect.x = pos.x;
	_rect.y = pos.y;
	//_setData();
}

void	MenuButton::setSize(int width, int height) {
	_size.w = width;
	_size.h = height;
}

void		MenuButton::setMenu(t_menu *menu) {
	_menu = menu;
}

SDL_FRect	MenuButton::getRect() const {
	return _rect;
}

std::string	MenuButton::getString() const {
	return _string;
}

bool		MenuButton::getState() const {
	return	_state;
}

t_menu		*MenuButton::getMenu() {
	return _menu;
}



