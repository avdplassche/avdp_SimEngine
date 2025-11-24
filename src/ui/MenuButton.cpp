#include "MenuButton.hpp"

#define c _coordinates

MenuButton::MenuButton(): _text("") {}

MenuButton::~MenuButton() {}

void		MenuButton::setValues(int x, int y, int width, int height, t_size window_size) {
	_pos.x = x;
	_pos.y = y;
	_size.width = width;
	_size.height = height;
	_window_size = window_size;
}


void		MenuButton::setText(std::string text) {
	_text = text;
}

void		MenuButton::setColor(t_color& color) {
	_default_color.r = color.r;
	_default_color.g = color.g;
	_default_color.b = color.b;
}

void	MenuButton::draw(SDL_Renderer *renderer) {
	_rect.w = _size.width;
	_rect.h = _size.height;
	_rect.x = _pos.x;
	_rect.y = _pos.y;
	SDL_SetRenderDrawColor(renderer, _default_color.r, _default_color.g,_default_color.b, 100);
	SDL_RenderFillRect(renderer, &_rect);
	if (_hasBorder)
	{
		SDL_SetRenderDrawColor(renderer, _border_color.r, _border_color.g,_border_color.b, 100);
		SDL_RenderRect(renderer, &_rect);
	}
}


bool		MenuButton::isActive() const {
	return	_active;
}


void	MenuButton::printCoordinates() {
	std::cout << "Pos : [" << _pos.x << "," << _pos.y << "]" << std::endl;
	std::cout << "Size : " << _size.width << "x" << _size.height << std::endl;
	std::cout << "[" << c[TOP][LEFT].x << "," << c[TOP][LEFT].y << "] ";
	std::cout << "[" << c[TOP][RIGHT].x << "," << c[TOP][RIGHT].y << "] " << std::endl;
	std::cout << "[" << c[BOTTOM][LEFT].x << "," << c[BOTTOM][LEFT].y << "] ";
	std::cout << "[" << c[BOTTOM][RIGHT].x << "," << c[BOTTOM][RIGHT].y << "] " << std::endl;
}

