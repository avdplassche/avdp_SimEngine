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


void	Div::draw(SDL_Renderer *renderer, t_color *color) {
	if (MENU_HAS_SHADOW)
	{
		SDL_SetRenderDrawColor(renderer, 0 , 0, 0, SDL_ALPHA_OPAQUE);
		SDL_RenderFillRect(renderer, &_shadow);
	}
	SDL_SetRenderDrawColor(renderer, color->r + 20 , color->g + 20, color->b + 20, SDL_ALPHA_OPAQUE);
	if (_isFilled)
		SDL_RenderFillRect(renderer, &_rect);
	else if (_hasBorder)
		SDL_RenderRect(renderer, &_rect);
	if (_isVisibleTitle)
	{
		TTF_SetTextColor(_title, 180, 180, 180, 255);
		TTF_DrawRendererText(_title, _title_pos.x, _title_pos.y);
	}
}

void	Div::setPos(int x, int y) {
	_pos.x = x;
	_pos.y = y;
	_rect.x = x;
	_rect.y = y;
	_shadow.x = x + MENU_SHADOW_X;
	_shadow.y = y - MENU_SHADOW_X;
}

void	Div::setSize(int w, int h) {
	_size.w = w;
	_size.h = h;
	_rect.w = w;
	_rect.h = h;
	_shadow.w = w;
	_shadow.h = h;
}


void	Div::setTitle(TTF_TextEngine *engine, TTF_Font *font, std::string text) {
	_title_string = text;
	_title = TTF_CreateText(engine, font, text.c_str(), text.size());
	TTF_GetTextSize(_title, &_title_size.w, &_title_size.h);
}

void	Div::setTitlePos(int x, int y) {
	_title_pos.x = x;
	_title_pos.y = y;
}

void	Div::setBorders(bool b) {
	_hasBorder = b;
}

void	Div::setFilled(bool b) {
	_isFilled = b;
}

bool	Div::hasBorder() const {
	return _isFilled;
}

bool	Div::isFilled() const {
	return _isFilled;
}

bool	Div::isVisibleTitle() const {
	return _isVisibleTitle;
}

t_size	Div::getSize() const {
	return _size;
}

t_pos	Div::getPos() const {
	return _pos;
}

t_size	Div::getTitleSize() const {
	return _title_size;
}

t_pos	Div::getTitlePos() const {
	return _title_pos;
}

SDL_FRect	Div::getRect() const {
	return _rect;
}

void	Div::printInfos() const {
	std::cout << "\n===== PRINT DIV INFO ====\n\n";

	std::cout << "Position : [" << _pos.x << "," << _pos.y << "]" << '\n';
	std::cout << "Size : " << _size.w << "x" << _size.h << '\n';
	std::cout << "Border : " << std::boolalpha << _hasBorder << '\n';
	std::cout << "Filled : " << std::boolalpha << _isFilled << '\n';

	std::cout << "\n===========================\n\n";
}

