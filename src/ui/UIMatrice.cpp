#include "UIMatrice.hpp"


UIMatrice::UIMatrice() {
	(void) _state;
	_ui_matrice_color = {50, 50, 50, 255};
}

UIMatrice::~UIMatrice() {
	for (size_t i = 0; i < _v.size(); i++)
		delete _v[i];
}

int	UIMatrice::setValues(t_uiMatriceConfig& config) {
	_setConfig(config);
	setTheme(*_theme);
	if (config.isDev)
		setDevSize(_size.w, _size.h);
	else
		setWindowSize(_size.w, _size.h);
	_initTable();
	_setTableSize();
	if (config.isDev)
		_setTestWidgets();
	if (_setCells() == -1)
		return -1;  /* In order to put true when a cell is occupied for ex */
	return 0;
}

void	UIMatrice::_setConfig(t_uiMatriceConfig& config) {
	_renderer = config.renderer;
	_isVisible = config.isVisible;
	_theme = config.theme;
	_table_size = config.table_size;
	_size = config.size;
	_window_ratio_w = config.window_ratio_w;
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
		t_valueUIConf	conf;

		conf.renderer = _renderer;
		conf.text_engine = _text_engine;
		conf.font = _font;
		conf.theme = _theme;
		conf.min = 0;
		conf.max = 10;
		conf.value = 2;
		conf.value_type = INT_VALUE;
		t_pos	matrix_pos = {0, 0};
		t_size	matrix_size = {9, 1};

		slider1->initValues(&conf);
		slider1->setMatrixPos(matrix_pos, matrix_size, 'h', {static_cast<int>(_table[matrix_pos.y][matrix_pos.x]->rect->x), static_cast<int>(_table[matrix_pos.y][matrix_pos.x]->rect->y)}, {_cell_size, _cell_size});
		_v.push_back(slider1);
	}
	{
		Slider *slider2 = new Slider;
		t_valueUIConf	conf;

		conf.renderer = _renderer;
		conf.text_engine = _text_engine;
		conf.font = _font;
		conf.theme = _theme;
		conf.min = 0;
		conf.max = 2;
		conf.value = 1.5;
		conf.value_type = FLOAT_VALUE;
		t_pos	matrix_pos = {0, 2};
		t_size	matrix_size = {1, 5};

		slider2->initValues(&conf);
		slider2->setMatrixPos(matrix_pos, matrix_size, 'v', {static_cast<int>(_table[matrix_pos.y][matrix_pos.x]->rect->x), static_cast<int>(_table[matrix_pos.y][matrix_pos.x]->rect->y)}, {_cell_size, _cell_size});
		_v.push_back(slider2);
	}
	{
		Spinner *spinner1 = new Spinner;
		t_valueUIConf	conf;

		conf.renderer = _renderer;
		conf.text_engine = _text_engine;
		conf.font = _font;
		conf.theme = _theme;
		conf.min = 0;
		conf.max = 10;
		conf.value = 0;
		conf.value_type = INT_VALUE;
		conf.ratio = 1;
		t_pos	matrix_pos = {0, 1};
		t_size	matrix_size = {5, 1};
		t_pos pos = {static_cast<int>(_table[matrix_pos.y][matrix_pos.x]->rect->x), static_cast<int>(_table[matrix_pos.y][matrix_pos.x]->rect->y)};


		spinner1->initValues(&conf);
		spinner1->setMatrixPos(matrix_pos, matrix_size, 'h', pos, {_cell_size, _cell_size});
		_v.push_back(spinner1);
	}
	{
		Checkbox *checkbox1 = new Checkbox;
		t_valueUIConf	conf;

		conf.renderer = _renderer;
		conf.text_engine = _text_engine;
		conf.font = _font;
		conf.theme = _theme;
		conf.checked = false;
		conf.title = "Checkbox";
		t_pos	matrix_pos = {6, 6};
		t_pos	pos = {static_cast<int>(_table[matrix_pos.y][matrix_pos.x]->rect->x), static_cast<int>(_table[matrix_pos.y][matrix_pos.x]->rect->y)};

		//std::cout << pos.x << " ----- " << pos.y << '\n';
		checkbox1->initValues(&conf);
		checkbox1->setMatrixPos(matrix_pos, pos, {_cell_size, _cell_size});
		_v.push_back(checkbox1);
	}

		{
		Togglebox *toggle_box1 = new Togglebox;
		t_valueUIConf	conf;

		conf.renderer = _renderer;
		conf.text_engine = _text_engine;
		conf.font = _font;
		conf.theme = _theme;
		conf.checked = false;
		conf.title = "Togglebox";
		t_pos	matrix_pos = {6, 7};
		t_pos	pos = {static_cast<int>(_table[matrix_pos.y][matrix_pos.x]->rect->x), static_cast<int>(_table[matrix_pos.y][matrix_pos.x]->rect->y)};

		//std::cout << pos.x << " ----- " << pos.y << '\n';
		toggle_box1->initValues(&conf);
		toggle_box1->setMatrixPos(matrix_pos, pos, {_cell_size, _cell_size});
		_v.push_back(toggle_box1);
	}
}

void	UIMatrice::newWidget(t_UIType type, t_pos matrix_pos, t_size matrix_size, float min, float max, float val) {
	t_valueUIConf	conf;

	conf.renderer = _renderer;
	conf.text_engine = _text_engine;
	conf.font = _font;
	conf.theme = _theme;
	conf.checked = false;
	conf.title = "Togglebox";


	//_v.push_back(element);
}


void	UIMatrice::_setWidgetsSize() {

	for (size_t i = 0; i < _v.size(); i++)
	{
		_v[i]->setPos(_pos.x + _cell_size * _v[i]->getMatrixPos().x, _pos.y + _cell_size * _v[i]->getMatrixPos().y);
		_v[i]->setSize(_cell_size * _v[i]->getMatrixSize().w, _cell_size * _v[i]->getMatrixSize().h);
		_v[i]->setPosSize({_pos.x + _cell_size * _v[i]->getMatrixPos().x, _pos.y + _cell_size * _v[i]->getMatrixPos().y},
							{_cell_size, _cell_size});
	}
}

int	UIMatrice::_setCells() {

	for (size_t i = 0; i < _v.size(); i++)
	{
		for (int x = 0; x < _v[i]->getMatrixSize().w; x++)
		{
			for (int y = 0; y < _v[i]->getMatrixSize().h; y++)
			{
				if (_table[_v[i]->getMatrixPos().y + y][_v[i]->getMatrixPos().x + x]->widget != nullptr)
					return -1;
				_table[_v[i]->getMatrixPos().y + y][_v[i]->getMatrixPos().x + x]->widget = _v[i];
			}
		}
	}
	return 0;
}


void	UIMatrice::draw() {


	////	Draw matrice (maybe it will become invisible in the future)
	for (int i = 0; i < _table_size.h; i++)
	{
		for (int j = 0; j < _table_size.w; j++)
		{
			if (i == _hoveredCell.y && j == _hoveredCell.x)
				SDL_SetRenderDrawColor(_renderer, 155, 155, 155, 155);
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

void	UIMatrice::setDevSize(int w, int h) {
	_size = {w, h};
	if (_size.w > _size.h)
		_cell_size = (_size.h - _size.h / UI_MATRICE_TEST_H) / _table_size.h;
	else
		_cell_size = (_size.w - _size.w / UI_MATRICE_TEST_W) / _table_size.w;
	_pos.x = _size.w / 2 - (_cell_size * UI_MATRICE_TEST_W) / 2;
	_pos.y = _size.h / 2 - (_cell_size * UI_MATRICE_TEST_H) / 2;
	_setTableSize();
	_setWidgetsSize();
}

void	UIMatrice::setWindowSize(int w, int h) {
	_size = {w, h};
	_pos.x = _size.w - _size.w * _window_ratio_w;
	_pos.y = 0;
	_cell_size = (_size.h - _size.h / _table_size.h) / _table_size.h;
	int ecart = (_size.w - _pos.x) / _cell_size;
	_pos.x = _size.w - ecart * _cell_size;
	_setTableSize();
	_setWidgetsSize();
	//printInfos();
}

void	UIMatrice::setHovered(int i, int j) {
	_hoveredCell.x = j;
	_hoveredCell.y = i;
	if (i >= 0 && j >= 0 && j < _table_size.w && i < _table_size.h)
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

void	UIMatrice::printInfos() {

	std::cout << "\n===== Print UI Matrice Infos =====\n\n";
	std::cout << "_pos : [" << _pos.x << "," << _pos.y << "]\n";
	std::cout << "_size : " << _size.w << "x" << _size.h << "\n";
	std::cout << "_cell_size : " << _cell_size << "\n";
	std::cout << "_table_size : " << _table_size.w << "x" << _table_size.h << "\n";
	std::cout << "\n=======================\n\n";
}

