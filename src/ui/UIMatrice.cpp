#include "UIMatrice.hpp"


UIMatrice::UIMatrice() {

}

UIMatrice::~UIMatrice() {
	//std::cout << "delete\n";
	//std::cout << "size " << _table.size() << '\n';
	//if (!_table.empty())
	//{
	//	for (auto it = _table.begin(); it != _table.end(); it++)
	//	{
	//		std::cout << "deleted " << it->i << "\n";
	//		delete it->rect;
	//	}
	//}
	//std::cout << "size after" << _table.size() << '\n';
	//_table.clear();
	////_table.
	//std::cout << "size after after " << _table.size() << '\n';
}

void	UIMatrice::setValues(t_UIMatriceConfig& config) {
	_setConfig(config);
	setTheme(*_theme);
	setSize(_size.w, _size.h);
	_initTable();
	_setTableSize();
}

void	UIMatrice::_setConfig(t_UIMatriceConfig& config) {
	_renderer = config.renderer;
	_isVisible = config.isVisible;
	_theme = config.theme;
	_table_size = config.table_size;
	_size = config.size;
	_pos = config.pos;
	_orientation = config.orientation;
	_hoveredCell = {-1, -1};
}

void	UIMatrice::_initTable() {

	for (int i = 0; i < _table_size.h; i++)
	{
		std::vector<t_cell *>	table_i;
		for (int j = 0; j < _table_size.w; j++)
		{
			t_cell	*cell = new t_cell;
			SDL_Rect	*rect = new SDL_Rect;
			cell->rect = rect;
			table_i.push_back(cell);
		}
		_table.push_back(table_i);
	}
}

void	UIMatrice::_setTableSize() {
	if (_table.empty())
		return ;
	for (int i = 0; i < _table_size.h; i++)
	{
		for (int j = 0; j < _table_size.w; j++)
		{
			_table[i][j]->rect->w = _cell_size;;
			_table[i][j]->rect->h = _cell_size;
			_table[i][j]->rect->x = _pos.x + _cell_size * j;
			_table[i][j]->rect->y = _pos.y + _cell_size * i;
			_table[i][j]->c = _ui_border_color;
		}
	}
}



void	UIMatrice::draw() {

	for (int i = 0; i < _table_size.h; i++)
	{
		for (int j = 0; j < _table_size.w; j++)
		{
			SDL_FRect	frect;
			SDL_RectToFRect(_table[i][j]->rect, &frect);
			if (i == _hoveredCell.y && j == _hoveredCell.x)
			{
				SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
			}
			else
				SDL_SetRenderDrawColor(_renderer, _ui_border_color.r, _ui_border_color.g, _ui_border_color.b, 255);
			SDL_RenderRect(_renderer,  &frect);
		}
	}
}

void	UIMatrice::setSize(int w, int h) {
	_size = {w, h};
	if (_size.w > _size.h)
		_cell_size = (_size.h - _size.h / 20) / _table_size.h;
	else
		_cell_size = (_size.w - _size.w / 20) / _table_size.w;
	_pos.x = _size.w / 2 - (_cell_size * UI_MATRICE_W) / 2;
	_pos.y = _size.h / 2 - (_cell_size * UI_MATRICE_H) / 2;
	_setTableSize();
}

void	UIMatrice::setHovered(int i, int j) {
	_hoveredCell.x = j;
	_hoveredCell.y = i;
}

void	UIMatrice::setTheme(Theme &theme) {
	_ui_color = theme.getUIDefault();
	_ui_border_color = theme.getUIBorder();
}

void	UIMatrice::setCellColour(t_color c, int i, int j) {
	_table[i][j]->c = c;
}

t_size	UIMatrice::getSize() const {
	return _size;
}

t_pos	UIMatrice::getHovered() const {
	return _hoveredCell;
}

std::vector<std::vector<t_cell *>>	UIMatrice::getTable() const {
	return _table;
}


