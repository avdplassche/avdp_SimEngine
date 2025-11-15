//#pragma once
//#include "pch.h"

class IUIElement {

protected:
	int			_pos[2];
	int			_size[2];
	bool		_border;
	//

public:
	virtual				~IUIElement() {};
	virtual void		setPos(int x, int y) = 0;
	virtual void		setSize(int width, int height) = 0;
	virtual void		draw() = 0;
	virtual bool		hasBorder() = 0;
};





//class UIDiv: public IUIElement {
//private:

//public:

//};

//class GameDiv {}; // ?

//class Widget: public IUIElement {

//};


