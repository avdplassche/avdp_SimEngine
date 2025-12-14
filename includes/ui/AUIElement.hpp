#pragma once
#include "pch.h"

class AUIElement {

protected:
	t_pos			_pos = {0, 0};
	t_size			_size;
	bool			_hasBorder;
	bool			_isFilled;

public:

	virtual				~AUIElement() {};
	void				setPos(int x, int y);
	void				setSize(int width, int height);


	bool				hasBorder() const;
	bool				isFilled() const;

	virtual void		draw(SDL_Renderer *renderer, t_color *color) = 0;
};





//class UIDiv: public AUIElement {
//private:

//public:

//};

//class GameDiv {}; // ?

//class Widget: public AUIElement {

//};


