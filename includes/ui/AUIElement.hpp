#pragma once
#include "pch.h"
#include "Theme.hpp"


/**
 * - t_pos		_pos;
 * - t_size		_size;
 * - t_pos		_matrix_position;
 * - t_size		_matrix_size
 * - t_UIType	_type;
 * - char		_orientation;
 * - float		_val;
 * - float		_min;
 * - float		_max;
 *
 *
 * - setPos(x, y);
 * - setSize(w, h);
 *
 * - draw = 0;
 */
class AUIElement {

protected:
	t_pos					_pos = {0, 0};
	t_size					_size = {1, 1};
	t_pos					_matrix_position;
	t_size					_matrix_size;
	t_UIType				_type;
	char 					_orientation;

	float					_val = 0;
	float					_max = 0;
	float					_min = 0;



public:

	virtual					~AUIElement() {};
	void					setPos(int x, int y);
	void					setSize(int width, int height);
	virtual void			setPosSize(t_pos pos, t_size size) = 0;

	virtual void			initValues(t_valueUIConf *conf) = 0;
	virtual void			setMatrixPos(t_pos matrix_pos, t_size lenght, t_pos cell_origin, t_size cell_size) = 0;


	virtual void			setValue(SDL_FPoint mouse) = 0;
	virtual void			setTheme(Theme&) = 0;
	//virtual void			setValue(int) = 0;
	//virtual void			setValue(std::string) = 0;


	t_pos					getMatrixPos() const;
	t_size					getMatrixSize() const;
	t_pos					getPos() const;
	t_size					getSize() const;
	t_UIType				getType() const;
	char					getOrientation() const;

	float					getVal() const;
	float					getMax() const;
	float					getMin() const;


	virtual void			draw(SDL_Renderer *renderer) = 0;
};





//class UIDiv: public AUIElement {
//private:

//public:

//};

//class GameDiv {}; // ?

//class Widget: public AUIElement {

//};


