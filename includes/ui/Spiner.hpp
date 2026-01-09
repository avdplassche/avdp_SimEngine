#ifndef SPINER_HPP
# define SPINER_HPP

#include "pch.h"
#include "AUIElement.hpp"
#include "Theme.hpp"

class Spiner : public AUIElement {

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
	SDL_FRect			_up_rect;
	SDL_FRect			_down_rect;

	t_valueType			_value_type;


	float				_ratio = 1;

	t_pos				_cell_origin;
	t_size				_cell_size;
	//t_size				_lenght;

	void				_setData();
	void				_setText();

public:

	Spiner();
	~Spiner();

	void				draw();

	void				initValues(t_valueUIConf *conf);
	void				setValue(SDL_FPoint mouse);
	void				increaseValue();
	void				decreaseValue();

	void				setMatrixPos(t_pos pos, t_size lenght, char orient, t_pos cell_origin, t_size cell_size);
	void				setPosSize(t_pos pos, t_size size);
	void				setTheme(Theme&);
	void				printDatas();

	SDL_FRect&			getUpRect();
	SDL_FRect&			getDownRect();

};


#endif