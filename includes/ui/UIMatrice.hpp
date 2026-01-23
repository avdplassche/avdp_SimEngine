#ifndef UI_MATRICE_TEST_HPP
# define UI_MATRICE_TEST_HPP

#include "pch.h"
#include "AUIElement.hpp"
#include "Theme.hpp"
#include "Slider.hpp"
#include "Spinner.hpp"
#include "Checkbox.hpp"
#include "Togglebox.hpp"

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
	float									_window_ratio_w;
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
	int										_setCells();


public:
	UIMatrice();
	~UIMatrice();

	int										setValues(t_uiMatriceConfig& config);

	void									setTheme(Theme &);
	void									setDevSize(int w, int h);
	void									setWindowSize(int w, int h);
	void									setCellColour(t_color c, int i, int j);
	void									setHovered(int i, int j);
	void									setState(t_UIState& state);

	void									newWidget(t_UIType, t_pos, t_size, float min, float max, float val);

	t_size									getSize() const;
	t_pos									getHovered() const;
	std::vector<std::vector<t_uiCell *>>	getTable() const;
	t_UIState								getState() const;

	AUIElement								*getHoveredElement();

	void									draw();

	void									printInfos();
};

#endif