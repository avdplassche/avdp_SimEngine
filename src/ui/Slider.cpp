#include "Slider.hpp"

Slider::Slider() {}

Slider::~Slider() {}

void	Slider::initValues(float min, float max, float value, t_valueType value_type) {
	_min = min;
	_max = max;
	_value = value;
	_value_type = value_type;
	_setData();
}

void	Slider::draw(SDL_Renderer *renderer, t_color *color) {
	SDL_SetRenderDrawColor(renderer, color->r, color->g,color->b, 255);
	SDL_RenderFillRect(renderer, &_rect);
}


void	Slider::setValue(float value) {
	_value = value;
}

void	Slider::setMatrixPos(int i, int j, int lenght, char orient) {
	_matrix_position.x = j;
	_matrix_position.y = i;
	_lenght = lenght;
	_orientation = orient;
	_setData();
}

void	Slider::_setData() {

}





