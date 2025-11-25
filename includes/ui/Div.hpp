#pragma once

#include "AUIElement.hpp"
#include "pch.h"

class Div : public AUIElement {

private:

	SDL_FRect			_rect;

public:

	Div();
	Div(t_pos pos, t_size size, bool border);
	~Div();

	void				setPos(int x, int y);
	void				setSize(int width, int height);
	void				setBorders(bool b);
	void				setFilled(bool b);

	void				draw(SDL_Renderer *renderer);

	bool				hasBorder() const;
	bool				isFilled() const;
};

