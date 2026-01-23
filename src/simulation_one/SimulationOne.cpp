#include "SimulationOne.hpp"


SimulationOne::SimulationOne() {}

SimulationOne::~SimulationOne() {}

void	SimulationOne::setValues(t_simOneConfig& conf) {
	_setConfig(conf);
	setTheme(*_theme);
	_setWidgets();
	printInfos();
}

void	SimulationOne::_setConfig(t_simOneConfig& conf) {
	_renderer = conf.renderer;
	_theme = conf.theme;
	setWindowSize(conf.window_size);
	_pos = {_window_size.w - SIM_ONE_PADDING - _size.w, SIM_ONE_PADDING / 2};
	_div.setBorders(conf.div_borders);
	_div.setFilled(conf.div_filled);
	_div.setSize(_window_size.w * 6 / 10, _window_size.w * 6 / 10);
	_div.setPos(_pos.x, _pos.y);
	_div.setState(APP_STATE_SIMULATION_ONE);
}

void	SimulationOne::setWindowSize(t_size size) {
	_window_size = {size.w * 66 / 100, size.h};
	if (_window_size.w > _window_size.h)
		_size = {_window_size.h - SIM_ONE_PADDING, _window_size.h - SIM_ONE_PADDING};
	else
		_size = {_window_size.w - SIM_ONE_PADDING, _window_size.w - SIM_ONE_PADDING};
	_ui_matrice.setWindowSize(size.w, size.h);
	_div.setSize(_size.w, _size.h);
}

void	SimulationOne::setTheme(Theme &theme) {
	_div_color = &theme.getMenuBorder();
}


void	SimulationOne::_setWidgets() {



}

void	SimulationOne::setUiMatrice(t_uiMatriceConfig& conf) {
	_ui_matrice.setValues(conf);
}

void	SimulationOne::draw() {
	_ui_matrice.draw();
	_div.draw(_renderer, _div_color);
}



UIMatrice&	SimulationOne::getUiMatrice() {
	return _ui_matrice;
}



void	SimulationOne::printInfos() {

	std::cout << "\n===== Simulation One Infos =====\n\n";
	std::cout << "_pos : [" << _pos.x << "," << _pos.y << "]\n";
	std::cout << "_size : " << _size.w << "x" << _size.h << "\n";
	std::cout << "\n=======================\n\n";
}


