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
}

void	UIMatrice::_initTable() {
	for (int i = 0; i < _table_size.h; i++)
	{
		for (int j = 0; j < _table_size.w; j++)
		{
			t_cell	cell;
			SDL_FRect	*rect = new SDL_FRect;
			cell.i = i;
			cell.j = j;
			cell.rect = rect;
			_table.push_back(cell);
		}
	}
}

void	UIMatrice::_setTableSize() {
	if (_table.empty())
		return ;
	for (int i = 0; i < _table_size.h; i++)
	{
		for (int j = 0; j < _table_size.w; j++)
		{
			_table.at(i * 10 + j).rect->w = _cell_size;
			_table.at(i * 10 + j).rect->h = _cell_size;
			_table.at(i * 10 + j).rect->x = _pos.x + _cell_size * j;
			_table.at(i * 10 + j).rect->y = _pos.y + _cell_size * i;
		}
	}
}



void	UIMatrice::draw() {

	for (size_t i = 0; i < _table.size(); i++)
	{
		SDL_SetRenderDrawColor(_renderer, 100, 100, 100, 255);
		SDL_RenderRect(_renderer, _table[i].rect);
	}
}

void	UIMatrice::setSize(int w, int h) {
	_size = {w, h};
	if (_size.w > _size.h)
		_cell_size = (_size.h - _size.h / 10) / _table_size.h;
	else
		_cell_size = (_size.w - _size.w / 10) / _table_size.w;
	_pos.x = _size.w / 2 - (_cell_size * UI_MATRICE_W) / 2;
	_pos.y = _size.h / 2 - (_cell_size * UI_MATRICE_H) / 2;
	_setTableSize();
}
