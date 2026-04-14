#include "Slider.hpp"

Slider::Slider() {
	_type = SLIDER;
}

Slider::~Slider() {}

void	Slider::initValues(t_valueUIConf *conf) {
	_text_engine = conf->text_engine;
	_font = conf->font;
	setTheme(*conf->theme);
	_min = conf->min;
	_max = conf->max;
	_val = conf->value;
	_value_type = conf->value_type;
	_setText();
	//_setData();
}

void	Slider::draw(SDL_Renderer *renderer) {
	SDL_SetRenderDrawColor(renderer, _ui_color->r, _ui_color->g,_ui_color->b, 255);
	SDL_RenderFillRect(renderer, &_rect);
	SDL_RenderFillRect(renderer, &_bar);
	SDL_SetRenderDrawColor(renderer, 20, 20,20, 255);
	SDL_RenderRect(renderer, &_bar);
	TTF_SetTextColor(_title, 0, 0, 0, 255);
	TTF_DrawRendererText(_title, _title_pos.x, _title_pos.y);
}

void	Slider::setValue(SDL_FPoint mouse) {
	float	value = 0;
	float	val_diff = _max - _min;
	float	px_diff = 0;
    
	if (_orientation == 'h')
	{
		px_diff = _size.w - SLIDER_PADDING * 2;
		value = (mouse.x - _pos.x) * val_diff / px_diff;
	}
	else if (_orientation == 'v')
	{
		px_diff = _size.h - SLIDER_PADDING * 2;
		value = _max - (mouse.y - _pos.y) * val_diff / px_diff;
	}
	else
    {
        return;
    }
	if (_value_type == INT_VALUE)
	{
		int a = static_cast<int>(value);
		if (value - a >= 0.5)
			a++;
		_val = a;
	}
	else
		_val = value;
	_moveBar();
	_setText();
}

void	Slider::setMatrixPos(t_pos matrix_pos, t_size lenght, t_pos cell_origin, t_size cell_size) {
	_matrix_position = matrix_pos;
	_matrix_size.w = lenght.w;
	_matrix_size.h = lenght.h;
	_matrix_size.h > _matrix_size.w ? _orientation = 'v' : _orientation = 'h';
	_cell_origin = cell_origin;
	_cell_size = cell_size;
	_pos = cell_origin;
	_size.w = cell_size.w * lenght.w - SLIDER_PADDING * 2;
	_size.h = cell_size.h * lenght.h - SLIDER_PADDING * 2;
	_setData();
	//printDatas();
}

void	Slider::_setData() {
	_rect.w = _size.w - SLIDER_PADDING * 2;
	_rect.h = _size.h - SLIDER_PADDING * 2;
	_rect.x = _cell_origin.x + SLIDER_PADDING;
	_rect.y = _cell_origin.y + SLIDER_PADDING;
	if (_orientation == 'h')
	{
		_bar.h = _cell_size.h;
		_bar.w = _cell_size.w / SLIDER_BAR_RATIO;
		_bar.y = _cell_origin.y;
		_moveBar();
	}
	else if (_orientation == 'v')
	{
		_bar.h = _cell_size.h / SLIDER_BAR_RATIO;
		_bar.w = _cell_size.w;
		_bar.x = _cell_origin.x;
		_moveBar();
	}
	_setText();
}

void	Slider::setPosSize(t_pos pos, t_size size) {
	_cell_origin = pos;
	_cell_size.h = size.h * _matrix_size.h;
	_cell_size.w = size.w * _matrix_size.w;
	_setData();
}

void	Slider::setTheme(Theme& theme) {
	_ui_color = &theme.getUIDefault();
	_ui_border_color = &theme.getUIBorder();
}

void	Slider::_setText() {
	std::stringstream	ss;
	if (_value_type == FLOAT_VALUE)
		ss << std::setprecision(2) << _val;
	else
		ss << _val;
	//TTF_SetFontSize(_font, FONT_SIZE - 6);
	_title = TTF_CreateText(_text_engine, _font, ss.str().c_str(), ss.str().size());
	TTF_GetTextSize(_title, &_title_size.w, &_title_size.h);
	_title_pos.x = _pos.x + SLIDER_PADDING + _rect.w / 2 - _title_size.w / 2;
	_title_pos.y = _pos.y + SLIDER_PADDING + _rect.h / 2 - _title_size.h / 2;
}

void	Slider::_moveBar() {
	if (_orientation == 'h')
		_bar.x = _cell_origin.x + _val * _rect.w / _max - _bar.w / 2;
	else if (_orientation == 'v')
		_bar.y = _cell_origin.y + _rect.h - _val * _rect.h / _max - _bar.h / 2;
}


//t_pos	Slider::getMatrixPos() const {
//	return _matrix_position;
//}


void	Slider::printDatas() {

	std::cout << "\n===== Print Slider Data =====\n\n";
	std::cout << "Max : " << _max << '\n';
	std::cout << "Min : " << _min << '\n';
	std::cout << "Val : " << _val << '\n';
	std::cout << "_pos : [" << _pos.x << "," << _pos.y << "]\n";
	std::cout << "_size : " << _size.w << "x" << _size.h << "\n";
	std::cout << "_matrix_position : [" << _matrix_position.x << "," << _matrix_position.y << "]\n";
	std::cout << "_matrix_size : " << _matrix_size.w << "x" << _matrix_size.h << "\n";
	std::cout << "\n\n=======================\n\n";
}



