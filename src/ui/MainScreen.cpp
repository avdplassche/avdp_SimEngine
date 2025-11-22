#include "MainScreen.hpp"

MainScreen::MainScreen() {}

MainScreen::MainScreen(Menu& menu_tree, t_mainScreenConfig& config):
					_nbButtons(config.nbButtons),
					_window_size(config.window_size),
					_menu_tree(menu_tree),
					_default_color(config.default_color),
					_hover_color(config.hover_color),
					_inactive_color(config.inactive_color)
{

	(void)_hover_color;
	(void)_inactive_color;
	_menu_size = _nbButtons * MENU_BUTTON_HEIGHT + ((_nbButtons - 2) * MENU_BUTTON_SPACING);
	assert(_menu_size < _window_size.height);

	for (int i = 0; i < _nbButtons; i++) {

		MenuButton button;
		button.setSize(MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);
		button.setColor(_default_color);
		_menu_buttons.push_back(button);
	}
	_calculateStartingPos();
}

void	MainScreen::_calculateStartingPos() {
	_starting_pos.x = _window_size.width / 2 - MENU_BUTTON_WIDTH / 2;
	_starting_pos.y = _window_size.height / 2 - _menu_size / 2;
}


void	MainScreen::draw() {

	float	y = _starting_pos.y;

	for (int i = 0; i < _nbButtons; i++) {
		_menu_buttons[i].setValues(_starting_pos.x, y, MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT, _window_size);
		_menu_buttons[i].draw();
		y += MENU_BUTTON_HEIGHT + MENU_BUTTON_SPACING;
	}
}

void	MainScreen::printInfo() {
	std::cout << "Nb buttons : " << _nbButtons << std::endl;
	std::cout << "Button size : " << MENU_BUTTON_WIDTH << "x" << MENU_BUTTON_HEIGHT << std::endl;
	std::cout << "Starting position : [" << _starting_pos.x << "," << _starting_pos.y << "]" << std::endl;
	std::cout << "Menu size : " << _menu_size << std::endl;
	std::cout << "Button spacing : " << MENU_BUTTON_SPACING << std::endl;

}

