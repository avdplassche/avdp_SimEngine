#pragma once
#include "pch.h"

class AUIElement {

protected:
	t_pos			_pos;
	t_size			_size;
	bool			_hasBorder;

public:

	virtual				~AUIElement() {};
	void				setPos(int x, int y);
	void				setSize(int width, int height);
	bool				hasBorder() const;

	virtual void		draw(SDL_Renderer *renderer) = 0;
};





//class UIDiv: public AUIElement {
//private:

//public:

//};

//class GameDiv {}; // ?

//class Widget: public AUIElement {

//};


