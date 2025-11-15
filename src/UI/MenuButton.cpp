#include "MenuButton.hpp"

#define c _coordinates

MenuButton::MenuButton():_text(""), _pos({0, 0}), _size({0,0}){}

MenuButton::~MenuButton() {}

void		MenuButton::setValues(int x, int y, int width, int height) {
	_pos.x = x;
	_pos.y = y;
	_size.width = width;
	_size.height = height;
	_setCoordinates();
}

void		MenuButton::setPos(int x, int y) {
	_pos.x = x;
	_pos.y = y;
}

void		MenuButton::setSize(int width, int height) {
	_size.width = width;
	_size.height = height;
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
	c[TOP][LEFT].x = normalizePosition(_pos.x, WINDOW_WIDTH);
	c[TOP][LEFT].y = normalizePosition(_pos.y, WINDOW_HEIGHT);
	c[TOP][RIGHT].x = normalizePosition(_pos.x + _size.width, WINDOW_HEIGHT);
	c[TOP][RIGHT].y = normalizePosition(_pos.y, WINDOW_HEIGHT);
	c[BOTTOM][LEFT].x = normalizePosition(_pos.x, WINDOW_WIDTH);
	c[BOTTOM][LEFT].y = normalizePosition(_pos.y + _size.height, WINDOW_HEIGHT);
	c[BOTTOM][RIGHT].x = normalizePosition(_pos.x + _size.width, WINDOW_HEIGHT);
	c[BOTTOM][RIGHT].y = normalizePosition(_pos.y + _size.height, WINDOW_HEIGHT);
}

void	MenuButton::draw() {

	glBegin(GL_QUADS);
	glColor3f(_color.r, _color.g, _color.b);
	glVertex2f(c[TOP][LEFT].x, c[TOP][LEFT].y); // Top-left vertex
	glVertex2f(c[TOP][RIGHT].x, c[TOP][RIGHT].y); // Top-right vertex
	glVertex2f(c[BOTTOM][LEFT].x, c[BOTTOM][LEFT].y); // Bottom-right vertex
	glVertex2f(c[BOTTOM][RIGHT].x, c[BOTTOM][RIGHT].y); // Bottom-left vertex
	glEnd();
}


bool		MenuButton::hasBorder() const {
	return	_hasBorder;
}

bool		MenuButton::isActive() const {
	return	_active;
}


