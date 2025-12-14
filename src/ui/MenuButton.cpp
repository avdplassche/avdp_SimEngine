#include "MenuButton.hpp"


MenuButton::MenuButton() {}

MenuButton::~MenuButton() {}

void	MenuButton::draw(SDL_Renderer *renderer, t_color *color) {

	(void) color;
	SDL_FRect rendered_rec;
	SDL_RectToFRect(&_rect, &rendered_rec);
	if (MENU_HAS_SHADOW)
	{
		SDL_FRect shadow(rendered_rec);
		shadow.x += MENU_SHADOW_X;
		shadow.y -= MENU_SHADOW_Y;
		SDL_SetRenderDrawColor(renderer, 0, 0,0, 255);
		SDL_RenderFillRect(renderer, &shadow);
	}
	SDL_SetRenderDrawColor(renderer, _current_color->r, _current_color->g,_current_color->b, 255);
	SDL_RenderFillRect(renderer, &rendered_rec);
	if (_hasBorder)
	{
		SDL_SetRenderDrawColor(renderer, _border_color->r, _border_color->g,_border_color->b, 255);
		SDL_RenderRect(renderer, &rendered_rec);
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
		case DEFAULT_STATE:
			_current_color = _default_color;
			break;
		case HOVER:
			_current_color = _hover_color;
			break;
		case INACTIVE:
			_current_color = _inactive_color;
			break;
		default:
			break;
	}
}

void		MenuButton::setMenu(t_menu *menu) {
	_menu = menu;
}


SDL_Rect	MenuButton::getRect() const {
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



