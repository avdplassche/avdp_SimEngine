#include "AUIElement.hpp"


void		AUIElement::setPos(int x, int y) {
	_pos.x = x;
	_pos.y = y;
}

void		AUIElement::setSize(int width, int height) {
	_size.w = width;
	_size.h = height;
}

bool		AUIElement::hasBorder() const {
	return	_hasBorder;
}

