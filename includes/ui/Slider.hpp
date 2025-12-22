#ifndef SLIDER_HPP
# define SLIDER_HPP

#include "pch.h"
#include "AUIElement.hpp"

class Slider : public AUIElement {

private:

	SDL_FRect			_rect;
	//SDL_FRect			_bar;

	float				_min;
	float				_max;
	float				_value;
	t_valueType			_value_type;

	char				_orientation;
	int					_lenght;

	t_pos				_matrix_position;

	void				_setData();



public:
	Slider();
	~Slider();

	void				draw(SDL_Renderer *renderer, t_color *color);

	void				initValues(float min, float max, float value, t_valueType value_type);
void					setValue(float value);
	void				setMatrixPos(int i, int j, int lenght, char orient);

	//int					getIntValue() const;
	//float				getFloatValue() const;
	//t_pos				getMatrixPos() const;


};




#endif
