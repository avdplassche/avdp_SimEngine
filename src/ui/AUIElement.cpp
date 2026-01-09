#include "AUIElement.hpp"


void		AUIElement::setPos(int x, int y) {
	_pos.x = x;
	_pos.y = y;
}

void		AUIElement::setSize(int width, int height) {
	_size.w = width;
	_size.h = height;
}

t_pos		AUIElement::getMatrixPos() const {
	return _matrix_position;
}

t_size		AUIElement::getMatrixSize() const {
	return _matrix_size;
}

t_UIType	AUIElement::getType() const {
	return _type;
}

t_pos		AUIElement::getPos() const {
	return _pos;
}

t_size		AUIElement::getSize() const {
	return _size;
}

char	AUIElement::getOrientation() const {
	return _orientation;
}

float	AUIElement::getVal() const {
	return _val;
}

float	AUIElement::getMax() const {
	return _max;
}

float	AUIElement::getMin() const {
	return _min;
}

//t_uiData	AUIElement::getUiData() const {
//	return _uiData;
//}

