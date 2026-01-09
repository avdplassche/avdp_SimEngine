#ifndef SIMULATION_ONE_HPP
# define SIMULATION_ONE_HPP

#include "UIMatrice.hpp"
#include "pch.h"


class SimulationOne {

private:

	//SDL_Renderer			*_renderer;
	//TTF_TextEngine			*_text_engine;
	//TTF_Font				*_font;

	UIMatrice				_ui_matrice;

	//Theme					*_theme;



public:

	SimulationOne();
	~SimulationOne();

	void					setUiMatrice(t_uiMatriceConfig&);
	UIMatrice&				getUiMatrice();

	void					draw();

};


#endif