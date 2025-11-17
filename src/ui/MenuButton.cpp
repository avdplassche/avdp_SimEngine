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
	_setCoordinates();
}


void		MenuButton::setText(std::string text) {
	_text = text;
}

void		MenuButton::setColor(Color& color) {
	_color.r = color.r;
	_color.g = color.g;
	_color.b = color.b;
}


void		MenuButton::_setCoordinates() {
	c[TOP][LEFT].x = normalizePosition(_pos.x, _window_size.width, 'x');
	c[TOP][LEFT].y = normalizePosition(_pos.y, _window_size.height, 'y');
	c[TOP][RIGHT].x = normalizePosition(_pos.x + _size.width, _window_size.width, 'x');
	c[TOP][RIGHT].y = normalizePosition(_pos.y, _window_size.height, 'y');
	c[BOTTOM][LEFT].x = normalizePosition(_pos.x, _window_size.width, 'x');
	c[BOTTOM][LEFT].y = normalizePosition(_pos.y + _size.height, _window_size.height, 'y');
	c[BOTTOM][RIGHT].x = normalizePosition(_pos.x + _size.width, _window_size.width, 'x');
	c[BOTTOM][RIGHT].y = normalizePosition(_pos.y + _size.height, _window_size.height, 'y');
}

void	MenuButton::draw() {

	glBegin(GL_QUADS);
	glColor3f(_color.r, _color.g, _color.b);
	glVertex2f(c[TOP][LEFT].x, c[TOP][LEFT].y); // Top-left vertex
	glVertex2f(c[TOP][RIGHT].x, c[TOP][RIGHT].y); // Top-right vertex
	glVertex2f(c[BOTTOM][RIGHT].x, c[BOTTOM][RIGHT].y); // Bottom-left vertex
	glVertex2f(c[BOTTOM][LEFT].x, c[BOTTOM][LEFT].y); // Bottom-right vertex
	glEnd();
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

