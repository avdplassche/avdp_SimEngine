#pragma once

#include "AUIElement.hpp"
#include "pch.h"

class Div : public AUIElement {

private:


public:

	Div();
	Div(t_pos pos, t_size size, bool border);
	~Div();

	void				setPos(int x, int y);
	void				setSize(int width, int height);
	void				draw();
	bool				hasBorder() const;
};

