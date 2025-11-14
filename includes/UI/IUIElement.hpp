#pragma once

class IUIElement {

private:
	int			pos[2];
	int			size[2];

public:

	virtual void		setPos(int x, int y) = 0;
	virtual void		setSize(int width, int height) = 0;
	virtual void		draw() = 0;
};

