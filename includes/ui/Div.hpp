#pragma once

#include "AUIElement.hpp"
#include "pch.h"

class Div : public AUIElement {

private:

	SDL_FRect			_rect;
	std::string			_title_string;

	TTF_Text			*_title;
	t_size				_title_size;
	t_pos				_title_pos;

	bool				_isVisibleTitle = true;

public:

	Div();
	Div(t_pos pos, t_size size, bool border);
	~Div();

	void				setPos(int x, int y);
	void				setSize(int width, int height);
	void				setBorders(bool b);
	void				setFilled(bool b);
	void				setTitle(TTF_TextEngine *engine, TTF_Font *font, std::string text);
	void				setTitlePos(int x, int y);

	void				draw(SDL_Renderer *renderer);

	bool				hasBorder() const;
	bool				isFilled() const;

	bool				isVisibleTitle() const;

	t_size				getSize() const;
	t_pos				getPos() const;
	t_size				getTitleSize() const;
	t_pos				getTitlePos() const;


	void				printInfos() const;
};

