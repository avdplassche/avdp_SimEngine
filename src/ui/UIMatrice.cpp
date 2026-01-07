#include "UIMatrice.hpp"


UIMatrice::UIMatrice() {
	(void) _state;
	_ui_matrice_color = {100, 100, 100, 255};
}

UIMatrice::~UIMatrice() {
}

void	UIMatrice::setValues(t_uiMatriceConfig& config) {
	_setConfig(config);
	setTheme(*_theme);
	setSize(_size.w, _size.h);
	_initTable();
	_setTableSize();
	_setTestWidgets();
	_setCells();  /* In order to put true when a cell is occupied for ex */
	// throw UIMatriceSpaceError if problem
}

void	UIMatrice::_setConfig(t_uiMatriceConfig& config) {
	_renderer = config.renderer;
	_isVisible = config.isVisible;
	_theme = config.theme;
	_table_size = config.table_size;
	_size = config.size;
	_pos = config.pos;
	_orientation = config.orientation;
	_hoveredCell = {-1, -1};
	_text_engine = config.text_engine;
	_font = config.font;
}

void	UIMatrice::_initTable() {

	for (int i = 0; i < _table_size.h; i++)
	{
		std::vector<t_uiCell *>	table_i;
		for (int j = 0; j < _table_size.w; j++)
		{
			t_uiCell	*cell = new t_uiCell;
			SDL_FRect	*rect = new SDL_FRect;
			cell->rect = rect;
			cell->widget = nullptr;
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

void	UIMatrice::_setTestWidgets() {

	{
		Slider *slider1 = new Slider;
		t_sliderConf	conf;

		conf.renderer = _renderer;
		conf.text_engine = _text_engine;
		conf.font = _font;
		conf.theme = _theme;
		conf.min = 0;
		conf.max = 10;
		conf.value = 2;
		conf.value_type = INT_VALUE;
		t_pos	matrix_pos = {0, 0};
		t_size	lenght = {9, 1};

		slider1->initValues(&conf);
		slider1->setMatrixPos(matrix_pos, lenght, 'h', {static_cast<int>(_table[matrix_pos.y][matrix_pos.x]->rect->x), static_cast<int>(_table[matrix_pos.y][matrix_pos.x]->rect->y)}, {_cell_size, _cell_size});
		_v.push_back(slider1);
	}
	{
		Slider *slider2 = new Slider;
		t_sliderConf	conf;

		conf.renderer = _renderer;
		conf.text_engine = _text_engine;
		conf.font = _font;
		conf.theme = _theme;
		conf.min = 0;
		conf.max = 20;
		conf.value = 10;
		conf.value_type = INT_VALUE;
		t_pos	matrix_pos = {7, 2};
		t_size	lenght = {1, 5};

		slider2->initValues(&conf);
		slider2->setMatrixPos(matrix_pos, lenght, 'v', {static_cast<int>(_table[matrix_pos.y][matrix_pos.x]->rect->x), static_cast<int>(_table[matrix_pos.y][matrix_pos.x]->rect->y)}, {_cell_size, _cell_size});
		_v.push_back(slider2);
	}
}

//void	UIMatrice::addWidget(AUIElement *element) {
//	_v.push_back(element);
//}


void	UIMatrice::_setWidgetsSize() {

	for (size_t i = 0; i < _v.size(); i++)
	{
		_v[i]->setPos(_pos.x + _cell_size * _v[i]->getMatrixPos().x, _pos.y + _cell_size * _v[i]->getMatrixPos().y);
		_v[i]->setSize(_cell_size * _v[i]->getMatrixSize().w, _cell_size * _v[i]->getMatrixSize().h);
		_v[i]->setPosSize({_pos.x + _cell_size * _v[i]->getMatrixPos().x, _pos.y + _cell_size * _v[i]->getMatrixPos().y},
							{_cell_size, _cell_size});
	}
}

void	UIMatrice::_setCells() {
	for (size_t i = 0; i < _v.size(); i++)
	{
		for (int y = 0; y < _v[i]->getMatrixSize().h; y++)
			_table[_v[i]->getMatrixPos().y + y][_v[i]->getMatrixPos().x]->widget = _v[i];
		for (int x = 0; x < _v[i]->getMatrixSize().w; x++)
			_table[_v[i]->getMatrixPos().y][_v[i]->getMatrixPos().x + x]->widget = _v[i];
	}
}


void	UIMatrice::draw() {


	////	Draw matrice (maybe it will become invisible in the future)

	for (int i = 0; i < _table_size.h; i++)
	{
		for (int j = 0; j < _table_size.w; j++)
		{
			if (i == _hoveredCell.y && j == _hoveredCell.x)
				SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
			else
				SDL_SetRenderDrawColor(_renderer, _ui_matrice_color.r, _ui_matrice_color.g, _ui_matrice_color.b, 255);
			SDL_RenderRect(_renderer,  _table[i][j]->rect);
		}
	}

	////	Draw widgets

	for (size_t i = 0; i < _v.size(); i++)
	{
		_v.at(i)->draw();
	}

}

void	UIMatrice::setSize(int w, int h) {
	_size = {w, h};
	if (_size.w > _size.h)
		_cell_size = (_size.h - _size.h / UI_MATRICE_H) / _table_size.h;
	else
		_cell_size = (_size.w - _size.w / UI_MATRICE_W) / _table_size.w;
	_pos.x = _size.w / 2 - (_cell_size * UI_MATRICE_W) / 2;
	_pos.y = _size.h / 2 - (_cell_size * UI_MATRICE_H) / 2;
	_setTableSize();
	_setWidgetsSize();
}

void	UIMatrice::setHovered(int i, int j) {
	_hoveredCell.x = j;
	_hoveredCell.y = i;
	if (i >= 0 && j >= 0 && j < UI_MATRICE_W && i < UI_MATRICE_H)
		_hoveredElement = _table[i][j]->widget;
	else
		_hoveredElement = nullptr;
}

void	UIMatrice::setTheme(Theme &theme) {
	for (size_t i = 0; i < _v.size(); i++)
	{
		_v.at(i)->setTheme(theme);
	}
	_ui_color = theme.getUIDefault();
	_ui_border_color = theme.getUIBorder();
}

void	UIMatrice::setCellColour(t_color c, int i, int j) {
	_table[i][j]->c = c;
}

void	UIMatrice::setState(t_UIState& state) {
	_state = state;
}

t_size	UIMatrice::getSize() const {
	return _size;
}

t_pos	UIMatrice::getHovered() const {
	return _hoveredCell;
}

std::vector<std::vector<t_uiCell *>>	UIMatrice::getTable() const {
	return _table;
}

t_UIState	UIMatrice::getState() const {
	return _state;
}

AUIElement	*UIMatrice::getHoveredElement() {
	return _hoveredElement;
}

//t_pos	getCellPos(int i, int j) {

//}

//t_size	getCellSize(int i, int j) {

//}

