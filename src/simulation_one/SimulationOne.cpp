#include "SimulationOne.hpp"
#include "data_structures.h"
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_stdinc.h>


SimulationOne::SimulationOne() {}

SimulationOne::~SimulationOne() {}

void	SimulationOne::setValues(t_simOneConfig& conf) {
	_setConfig(conf);
	setTheme(*_theme);
	_setWidgets();
    updateWidgetValues();
	printInfos();
}

void	SimulationOne::_setConfig(t_simOneConfig& conf) {
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
	_ui_matrice.newWidget(SLIDER, {0, 0}, {6, 1}, "Slider", {0, 100, 50, FLOAT_VALUE});
	_ui_matrice.newWidget(SLIDER, {0, 1}, {6, 1}, "Slider", {0, 255, (float)_rectColor.r, INT_VALUE});
	_ui_matrice.newWidget(SLIDER, {0, 2}, {6, 1}, "Slider", {0, 255, (float)_rectColor.g, INT_VALUE});
	_ui_matrice.newWidget(SLIDER, {0, 3}, {6, 1}, "Slider", {0, 255, (float)_rectColor.b, INT_VALUE});

}

void	SimulationOne::setUiMatrice(t_uiMatriceConfig& conf) {
	_ui_matrice.setValues(conf);
}

void	SimulationOne::draw(SDL_Renderer *renderer) {
	_ui_matrice.draw(renderer);
	_div.draw(renderer, _div_color);
    SDL_SetRenderDrawColor(renderer, _rectColor.r, _rectColor.g, _rectColor.b, _rectColor.a);
    SDL_RenderFillRect(renderer, &_rect);
}


void    SimulationOne::updateWidgetValues() {
    _rect.h = _ui_matrice.getElements()[0]->getVal() * 5;
    _rect.w = _ui_matrice.getElements()[0]->getVal() * 5;
    _rect.x = _div.getPos().x + (float)_div.getSize().w / 2 - _rect.w / 2;
    _rect.y = _div.getPos().y + (float)_div.getSize().h / 2 - _rect.h / 2;
    _rectColor.r = _ui_matrice.getElements()[1]->getVal();
    _rectColor.g = _ui_matrice.getElements()[2]->getVal();
    _rectColor.b = _ui_matrice.getElements()[3]->getVal();
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


