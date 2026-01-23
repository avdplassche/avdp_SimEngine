#include "Togglebox.hpp"

Togglebox::Togglebox() {
	_type = TOGGLE_BOX;
}

Togglebox::~Togglebox() {}

void	Togglebox::initValues(t_valueUIConf *conf) {

	_renderer = conf->renderer;
	_text_engine = conf->text_engine;
	_font = conf->font;
	_checked = conf->checked;
	setTheme(*conf->theme);
	//_setData();
	_setText(conf->title);
}

void	Togglebox::setTheme(Theme& theme) {
	_ui_color = &theme.getUIDefault();
	_ui_border_color = &theme.getUIBorder();
	_ui_text_color = &theme.getUIPlainText();
	_ui_check_color = &theme.getUIBoxText();
}

void	Togglebox::_setData() {
	int n = 1;

	_box_rect.h = _size.h - SLIDER_PADDING * 2;
	_box_rect.w = _box_rect.h;
	_box_rect.x = _cell_origin.x + SLIDER_PADDING;
	_box_rect.y = _cell_origin.y + SLIDER_PADDING;
	_rect_checked_true.h = _box_rect.h - SLIDER_PADDING * 2;
	_rect_checked_true.w = _rect_checked_true.h;
	_rect_checked_true.x = _box_rect.x + SLIDER_PADDING;
	_rect_checked_true.y = _box_rect.y + SLIDER_PADDING;
	_size.w = _box_rect.w + _title.size.w;
	while (_size.w < n * _cell_size.w)
		n++;
	_matrix_size.w = n;
	_matrix_size.h = 1;
	TTF_SetFontSize(_font, _cell_size.h / 2);
	TTF_GetTextSize(_title.text, &_title.size.w, &_title.size.h);
	_title.pos.x = _box_rect.w + _pos.x + SLIDER_PADDING * 2;
	_title.pos.y = _pos.y + _cell_size.h / 2 - _title.size.h / 2;
}

void	Togglebox::_setText(std::string title) {
	_title.text = TTF_CreateText(_text_engine, _font, title.c_str(), title.size());
	TTF_GetTextSize(_title.text, &_title.size.w, &_title.size.h);
}

void	Togglebox::setMatrixPos(t_pos matrix_pos, t_pos cell_origin, t_size cell_size) {

	_matrix_position = matrix_pos;
	_cell_origin = cell_origin;
	_cell_size = cell_size;
	_pos = cell_origin;
	_size.h = cell_size.h - SLIDER_PADDING * 2;
	_setData();
	printInfos();
}


void	Togglebox::setPosSize(t_pos pos, t_size size) {
	_cell_origin = pos;
	_cell_size.h = size.h * _matrix_size.h;
	_cell_size.w = size.w * _matrix_size.w;
	_setData();
}

void	Togglebox::setValue(SDL_FPoint mouse) {
	SDL_FPoint	point(mouse);

	SDL_FRect	*r = &_box_rect;
	if (SDL_PointInRectFloat(&point, r))
	{
		_action();
		std::cout << "Toggle Button Pressed!\n";
	}
}

void	Togglebox::setAction(void (*action)(void)) {
	_action = action;
}




void	Togglebox::draw() {
	SDL_SetRenderDrawColor(_renderer, _ui_color->r, _ui_color->g,_ui_color->b, 255);
	SDL_RenderFillRect(_renderer, &_box_rect);
	TTF_SetTextColor(_title.text, _ui_text_color->r, _ui_text_color->g, _ui_text_color->b, 255);
	TTF_DrawRendererText(_title.text, _title.pos.x, _title.pos.y);
	if (_checked)
	{
		SDL_SetRenderDrawColor(_renderer, _ui_check_color->r, _ui_check_color->g,_ui_check_color->b, 255);
		SDL_RenderFillRect(_renderer, &_rect_checked_true);
	}
}

void	Togglebox::printInfos() {
	std::cout << "\n===== Print Togglebox Data =====\n\n";
	std::cout << "_pos : [" << _pos.x << "," << _pos.y << "]\n";
	std::cout << "_size : " << _size.w << "x" << _size.h << "\n";
	std::cout << "_matrix_position : [" << _matrix_position.x << "," << _matrix_position.y << "]\n";
	std::cout << "_matrix_size : " << _matrix_size.w << "x" << _matrix_size.h << "\n";
	std::cout << "_box_rect pos : [" << _box_rect.x << "," << _box_rect.y << "]\n";
	std::cout << "_box_rect size : " << _box_rect.w << "x" << _box_rect.h << '\n';
	std::cout << "_title pos : [" << _title.pos.x << "," << _title.pos.y << "]\n";
	std::cout << "font size : " << TTF_GetFontSize(_font) << '\n';
	std::cout << "\n=======================\n\n";
}

