#include "Spinner.hpp"

Spinner::Spinner() {
	_type = SPINNER;
}

Spinner::~Spinner() {}

void	Spinner::initValues(t_valueUIConf *conf) {
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

void	Spinner::draw(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, _ui_color->r, _ui_color->g,_ui_color->b, 255);
	SDL_RenderFillRect(renderer, &_rect);
	SDL_RenderFillRect(renderer, &_up_rect);
	SDL_RenderFillRect(renderer, &_down_rect);
	SDL_SetRenderDrawColor(renderer, 20, 20,20, 255);
	SDL_RenderRect(renderer, &_up_rect);
	SDL_RenderRect(renderer, &_down_rect);
	TTF_SetTextColor(_title.text, 0, 0, 0, 255);
	TTF_DrawRendererText(_title.text, _title.pos.x, _title.pos.y);
	TTF_SetTextColor(_plus_symbol.text, 0, 0, 0, 255);
	TTF_SetTextColor(_minus_symbol.text, 0, 0, 0, 255);
	TTF_DrawRendererText(_plus_symbol.text, _plus_symbol.pos.x, _plus_symbol.pos.y);
	TTF_DrawRendererText(_minus_symbol.text, _minus_symbol.pos.x, _minus_symbol.pos.y);
}

void	Spinner::setValue(SDL_FPoint mouse) {
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

void	Spinner::setMatrixPos(t_pos matrix_pos, t_size lenght, t_pos cell_origin, t_size cell_size) {
	_matrix_position = matrix_pos;
	_matrix_size.w = lenght.w;
	_matrix_size.h = lenght.h;
	_matrix_size.h > _matrix_size.w ? _orientation = 'v' : _orientation = 'h';
	//if (_matrix_size.h > _matrix_size.w)
	//	_orientation = 'v';

	_cell_origin = cell_origin;
	_cell_size = cell_size;
	_pos = cell_origin;
	_size.w = cell_size.w * lenght.w - SLIDER_PADDING * 2;
	_size.h = cell_size.h * lenght.h - SLIDER_PADDING * 2;
	_setData();
}

void	Spinner::_setData() {
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

void	Spinner::setPosSize(t_pos pos, t_size size) {
	_cell_origin = pos;
	_cell_size.h = size.h * _matrix_size.h;
	_cell_size.w = size.w * _matrix_size.w;
	_setData();
}

void	Spinner::setTheme(Theme& theme) {
	_ui_color = &theme.getUIDefault();
	_ui_border_color = &theme.getUIBorder();
}

void	Spinner::_setText() {
	std::stringstream	ss;
	ss << _val;
	_title.text = TTF_CreateText(_text_engine, _font, ss.str().c_str(), ss.str().size());
	TTF_GetTextSize(_title.text, &_title.size.w, &_title.size.h);
	_title.pos.x = _pos.x + SLIDER_PADDING + _rect.w / 2 - _title.size.w / 2;
	_title.pos.y = _pos.y + SLIDER_PADDING + _rect.h / 2 - _title.size.h / 2;
	_plus_symbol.text = TTF_CreateText(_text_engine, _font, "+", 1);
	_minus_symbol.text = TTF_CreateText(_text_engine, _font, "-", 1);
	TTF_GetTextSize(_plus_symbol.text, &_plus_symbol.size.w, &_plus_symbol.size.h);
	TTF_GetTextSize(_minus_symbol.text, &_minus_symbol.size.w, &_minus_symbol.size.h);
	_plus_symbol.pos.x = _up_rect.x + _up_rect.w / 2 - _plus_symbol.size.w / 2;
	_plus_symbol.pos.y = _up_rect.y + _up_rect.h / 2 - _plus_symbol.size.h / 2;
	_minus_symbol.pos.x = _down_rect.x + _down_rect.w / 2 - _minus_symbol.size.w / 2;
	_minus_symbol.pos.y = _down_rect.y + _down_rect.h / 2 - _minus_symbol.size.h / 2;
}

void	Spinner::increaseValue() {
	_val += _ratio;
}

void	Spinner::decreaseValue() {
	_val -= _ratio;
}

SDL_FRect&	Spinner::getUpRect() {
	return _up_rect;
}

SDL_FRect&	Spinner::getDownRect() {
	return _down_rect;
}

//t_pos	Spinner::getMatrixPos() const {
//	return _matrix_position;
//}


void	Spinner::printDatas() {

	std::cout << "\n===== Print Spinner Data =====\n\n";
	std::cout << "Max : " << _max << '\n';
	std::cout << "Min : " << _min << '\n';
	std::cout << "Val : " << _val << '\n';
	std::cout << "_pos : [" << _pos.x << "," << _pos.y << "]\n";
	std::cout << "_size : " << _size.w << "x" << _size.h << "\n";
	std::cout << "_matrix_position : [" << _matrix_position.x << "," << _matrix_position.y << "]\n";
	std::cout << "_matrix_size : " << _matrix_size.w << "x" << _matrix_size.h << "\n";
	std::cout << "\n\n=======================\n\n";
}



