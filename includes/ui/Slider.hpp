#ifndef SLIDER_HPP
# define SLIDER_HPP

#include "pch.h"
#include "AUIElement.hpp"
#include "Theme.hpp"

class Slider : public AUIElement {

private:

	SDL_Renderer		*_renderer;
	TTF_TextEngine		*_text_engine;
	TTF_Font			*_font;
	TTF_Text			*_title;
	t_size				_title_size;
	t_pos				_title_pos;

	t_color				*_ui_color;
	t_color				*_ui_border_color;

	SDL_FRect			_rect;
	SDL_FRect			_bar;

	t_valueType			_value_type;

	//t_pos				_matrix_position;
	t_pos				_cell_origin;
	t_size				_cell_size;
	t_size				_lenght;

	void				_setData();
	void				_setText();
	void				_moveBar();


public:
	Slider();
	~Slider();

	void				draw();

	//void				initValues(SDL_Renderer *_renderer, Theme *theme, float min, float max, float value, t_valueType value_type);
	void				initValues(t_sliderConf *conf);
	void				setValue(float value);
	void				setMatrixPos(t_pos pos, t_size lenght, char orient, t_pos cell_origin, t_size cell_size);
	void				setPosSize(t_pos pos, t_size size);
	void				setTheme(Theme&);

	//int				getIntValue() const;
	//float				getFloatValue() const;
	//t_pos				getMatrixPos() const;

	void				printDatas();
};




#endif
