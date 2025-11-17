#include "MainScreen.hpp"
#include "UIElementFactory.hpp"

MainScreen::MainScreen() {}

MainScreen::MainScreen(int nbButtons, t_size window_size, Color main_color, Color incative_color):
					_nbButtons(nbButtons),
					_window_size(window_size),
					_main_color(main_color),
					_inactive_color(incative_color)
{
	_menu_size = _nbButtons * MENU_BUTTON_HEIGHT + ((_nbButtons - 2) * MENU_BUTTON_SPACING);
	assert(_menu_size < _window_size.height);

	for (int i = 0; i < _nbButtons; i++) {

		MenuButton button;
		button.setSize(MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);
		button.setColor(_main_color);
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

