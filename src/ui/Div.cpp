#include "Div.hpp"


Div::Div() {}

Div::Div(t_pos pos, t_size size, bool border) {
	_pos = pos;
	_size = size;
	_hasBorder = border;
}

Div::~Div() {}


void	Div::draw(SDL_Renderer *render) {
	(void) render;
}
