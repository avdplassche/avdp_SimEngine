#ifndef CHECKBOX_HPP
# define CHECKBOX_HPP


#include "pch.h"
#include "AUIElement.hpp"

class Checkbox : public AUIElement {

private:

	SDL_Renderer		*_renderer;
	TTF_TextEngine		*_text_engine;
	TTF_Font			*_font;
	t_text				_title;


	t_color				*_ui_color;
	t_color				*_ui_border_color;
	t_color				*_ui_text_color;
	t_color				*_ui_check_color;

	//SDL_FRect			_rect;
	SDL_FRect			_box_rect;
	SDL_FRect			_rect_checked_true;

	bool				_checked;

	t_pos				_cell_origin;
	t_size				_cell_size;

	void				_setText(std::string text);
	void				_setData();


public:
	Checkbox();
	~Checkbox();

	void				draw();
	void				initValues(t_valueUIConf *conf);

	void				setValue(SDL_FPoint mouse);
	void				setMatrixPos(t_pos matrix_pos, t_pos cell_origin, t_size cell_size);
	void				setPosSize(t_pos pos, t_size size);
	void				setTheme(Theme&);

	void				printInfos();

};


#endif

