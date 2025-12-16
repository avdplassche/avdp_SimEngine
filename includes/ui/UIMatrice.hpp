#ifndef UI_MATRICE_HPP
# define UI_MATRICE_HPP

#include "pch.h"
#include "AUIElement.hpp"

class UIMatrice {

private:

	std::vector<t_cell>			_table;
	std::vector<AUIElement *>	_v;
	std::vector<bool>			_room;

	t_size						_size;
	t_pos						_pos;
	SDL_Renderer				*_renderer;
	t_size						_table_size; // i and j
	int							_cell_size;
	bool						_isVisible = true;
	char						_orientation;

	Theme						*_theme;

	void						_setConfig(t_UIMatriceConfig& config);
	void						_initTable();
	void						_setTableSize();

public:
	UIMatrice();
	~UIMatrice();

	void						setValues(t_UIMatriceConfig& config);

	void						setSize(int w, int h);

	void						draw();

};

#endif