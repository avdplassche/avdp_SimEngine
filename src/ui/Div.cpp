#include "Div.hpp"


Div::Div(){
	_pos = {0, 0};
	_size = {10, 10};
	setPos(0, 0);
	setSize(0, 0);
}

Div::Div(t_pos pos, t_size size, bool border) {
	_pos = pos;
	_size = size;
	_hasBorder = border;
}

Div::~Div() {}


void	Div::draw(SDL_Renderer *renderer) {
	if (_isFilled)
		SDL_RenderFillRect(renderer, &_rect);
	else if (_hasBorder)
		SDL_RenderRect(renderer, &_rect);
}

void	Div::setPos(int x, int y) {
	_pos.x = x;
	_pos.y = y;
	_rect.x = x;
	_rect.y = y;
}

void	Div::setSize(int w, int h) {
	_size.w = w;
	_size.h = h;
	_rect.w = w;
	_rect.h = h;
}

void	Div::setBorders(bool b) {
	_hasBorder = b;
}

void	Div::setFilled(bool b) {
	_isFilled = b;
}

bool	Div::isFilled() const {
	return _isFilled;
}

bool	Div::hasBorder() const {
	return _isFilled;
}
