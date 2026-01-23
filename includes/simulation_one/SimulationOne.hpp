#ifndef SIMULATION_ONE_HPP
# define SIMULATION_ONE_HPP

#include "UIMatrice.hpp"
#include "pch.h"

#include "Div.hpp"
#include "Theme.hpp"


class SimulationOne {

private:

	SDL_Renderer			*_renderer;
	//TTF_TextEngine		*_text_engine;
	//TTF_Font				*_font;

	UIMatrice				_ui_matrice;
	Div						_div;

	t_size					_window_size;
	t_size					_size;
	t_pos					_pos;
	t_color					*_div_color;

	Theme					*_theme;

	void					_setConfig(t_simOneConfig& );
	void					_setWidgets();

public:

	SimulationOne();
	~SimulationOne();


	void					setValues(t_simOneConfig& );
	void					setWindowSize(t_size);
	void					setUiMatrice(t_uiMatriceConfig&);
	void					setTheme(Theme &);

	UIMatrice&				getUiMatrice();

	void					draw();
	void					printInfos();
};


#endif