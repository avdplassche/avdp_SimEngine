#ifndef UI_MATRICE_HPP
# define UI_MATRICE_HPP

#include "pch.h"
#include "AUIElement.hpp"
#include "Theme.hpp"
#include "Slider.hpp"

class UIMatrice {

private:

	std::vector<std::vector<t_uiCell *>>	_table;
	std::vector<AUIElement *>				_v;
	//std::vector<std::vector<bool>>		_room;


	SDL_Renderer							*_renderer;
	TTF_TextEngine							*_text_engine;
	TTF_Font								*_font;

	t_UIState								_state = UI_STATE_DEFAULT;


	t_size									_size;
	t_pos									_pos;
	t_size									_table_size; // i and j
	int										_cell_size;
	bool									_isVisible = true;
	char									_orientation;

	t_pos									_hoveredCell;
	AUIElement								*_hoveredElement = NULL;

	Theme									*_theme;
	t_color									_ui_color;
	t_color									_ui_border_color;
	t_color									_ui_matrice_color;


	void									_setConfig(t_uiMatriceConfig& config);
	void									_initTable();
	void									_setTableSize();
	void									_setTestWidgets();
	void									_setWidgetsSize();
	void									_setCells();


public:
	UIMatrice();
	~UIMatrice();

	void									setValues(t_uiMatriceConfig& config);

	void									setTheme(Theme &);
	void									setSize(int w, int h);
	void									setCellColour(t_color c, int i, int j);
	void									setHovered(int i, int j);
	void									setState(t_UIState& state);



	t_size									getSize() const;
	t_pos									getHovered() const;
	std::vector<std::vector<t_uiCell *>>	getTable() const;
	t_UIState								getState() const;

	AUIElement								*getHoveredElement();

	void									draw();

};

#endif