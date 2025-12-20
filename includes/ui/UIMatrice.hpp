#ifndef UI_MATRICE_HPP
# define UI_MATRICE_HPP

#include "pch.h"
#include "AUIElement.hpp"
#include "Theme.hpp"

class UIMatrice {

private:

	std::vector<std::vector<t_cell *>>	_table;
	std::vector<AUIElement *>			_v;
	std::vector<bool>					_room;



	t_size								_size;
	t_pos								_pos;
	SDL_Renderer						*_renderer;
	t_size								_table_size; // i and j
	int									_cell_size;
	bool								_isVisible = true;
	char								_orientation;
	t_pos								_hoveredCell;

	Theme								*_theme;
	t_color								_ui_color;
	t_color								_ui_border_color;


	void								_setConfig(t_UIMatriceConfig& config);
	void								_initTable();
	void								_setTableSize();



public:
	UIMatrice();
	~UIMatrice();

	void								setValues(t_UIMatriceConfig& config);

	void								setTheme(Theme &);
	void								setSize(int w, int h);
	void								setCellColour(t_color c, int i, int j);
	void								setHovered(int i, int j);

	t_size								getSize() const;
	t_pos								getHovered() const;
	std::vector<std::vector<t_cell *>>	getTable() const;


	void								draw();

};

#endif