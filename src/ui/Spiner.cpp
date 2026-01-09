#include "Spiner.hpp"

Spiner::Spiner() {
	_type = SPINER;
}

Spiner::~Spiner() {}

//void	Spiner::initValues(SDL_Renderer *renderer, Theme *theme, float min, float max, float value, t_valueType value_type) {
void	Spiner::initValues(t_valueUIConf *conf) {
	_renderer = conf->renderer;
	_text_engine = conf->text_engine;
	_font = conf->font;
	setTheme(*conf->theme);
	_min = conf->min;
	_max = conf->max;
	_val = conf->value;
	_value_type = conf->value_type;
	_ratio = conf->ratio;
	_setText();
	//_setData();
}

void	Spiner::draw() {
	SDL_SetRenderDrawColor(_renderer, _ui_color->r, _ui_color->g,_ui_color->b, 255);
	SDL_RenderFillRect(_renderer, &_rect);
	SDL_RenderFillRect(_renderer, &_up_rect);
	SDL_RenderFillRect(_renderer, &_down_rect);
	SDL_SetRenderDrawColor(_renderer, 20, 20,20, 255);
	SDL_RenderRect(_renderer, &_up_rect);
	SDL_RenderRect(_renderer, &_down_rect);
	TTF_SetTextColor(_title, 0, 0, 0, 255);
	TTF_DrawRendererText(_title, _title_pos.x, _title_pos.y);
}

void	Spiner::setValue(SDL_FPoint mouse) {
	SDL_FPoint	point(mouse);

	SDL_FRect	*r = &_up_rect;
	if (SDL_PointInRectFloat(&point, r))
	{
		if (_val <= _max - _ratio)
		{
			increaseValue();
			_setText();
			return ;
		}
	}
	r = &_down_rect;
	if (SDL_PointInRectFloat(&point, r))
	{
		if (_val - _ratio >= _min)
		{
			decreaseValue();
		}
	}
	_setText();
}

void	Spiner::setMatrixPos(t_pos matrix_pos, t_size lenght, char orient, t_pos cell_origin, t_size cell_size) {
	_matrix_position = matrix_pos;
	_matrix_size.w = lenght.w;
	_matrix_size.h = lenght.h;
	_orientation = orient;
	_cell_origin = cell_origin;
	_cell_size = cell_size;
	_pos = cell_origin;
	_size.w = cell_size.w * lenght.w - SLIDER_PADDING * 2;
	_size.h = cell_size.h * lenght.h - SLIDER_PADDING * 2;
	_setData();
	//printDatas();
}

void	Spiner::_setData() {
	_rect.w = _size.w - SLIDER_PADDING * 2;
	_rect.h = _size.h - SLIDER_PADDING * 2;
	_rect.x = _cell_origin.x + SLIDER_PADDING;
	_rect.y = _cell_origin.y + SLIDER_PADDING;
	_up_rect.h = _rect.h / 2;
	_up_rect.w = _up_rect.h * 2;
	_up_rect.y = _rect.y;
	_up_rect.x = _rect.x + _rect.w - _up_rect.w;
	_down_rect.h = _rect.h / 2;
	_down_rect.w = _down_rect.h * 2;
	_down_rect.y = _rect.y + _down_rect.h;
	_down_rect.x = _rect.x + _rect.w - _down_rect.w;
	_setText();
}

void	Spiner::setPosSize(t_pos pos, t_size size) {
	_cell_origin = pos;
	_cell_size.h = size.h * _matrix_size.h;
	_cell_size.w = size.w * _matrix_size.w;
	_setData();
}

void	Spiner::setTheme(Theme& theme) {
	_ui_color = &theme.getUIDefault();
	_ui_border_color = &theme.getUIBorder();
}

void	Spiner::_setText() {
	std::stringstream	ss;
	ss << _val;
	_title = TTF_CreateText(_text_engine, _font, ss.str().c_str(), ss.str().size());
	TTF_GetTextSize(_title, &_title_size.w, &_title_size.h);
	_title_pos.x = _pos.x + SLIDER_PADDING + _rect.w / 2 - _title_size.w / 2;
	_title_pos.y = _pos.y + SLIDER_PADDING + _rect.h / 2 - _title_size.h / 2;
}

void	Spiner::increaseValue() {
	_val += _ratio;
}

void	Spiner::decreaseValue() {
	_val -= _ratio;
}

SDL_FRect&	Spiner::getUpRect() {
	return _up_rect;
}

SDL_FRect&	Spiner::getDownRect() {
	return _down_rect;
}

//t_pos	Spiner::getMatrixPos() const {
//	return _matrix_position;
//}


void	Spiner::printDatas() {

	std::cout << "\n===== Print Spiner Data =====\n\n";
	std::cout << "Max : " << _max << '\n';
	std::cout << "Min : " << _min << '\n';
	std::cout << "Val : " << _val << '\n';
	std::cout << "_pos : [" << _pos.x << "," << _pos.y << "]\n";
	std::cout << "_size : " << _size.w << "x" << _size.h << "\n";
	std::cout << "_matrix_position : [" << _matrix_position.x << "," << _matrix_position.y << "]\n";
	std::cout << "_matrix_size : " << _matrix_size.w << "x" << _matrix_size.h << "\n";
	std::cout << "\n\n=======================\n\n";
}



