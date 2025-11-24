#include "MainScreen.hpp"

MainScreen::MainScreen() {}

MainScreen::~MainScreen() {}

void	MainScreen::setValues(MenuTree& menu_tree, t_mainScreenConfig& config) {

	_renderer = config.renderer;
	_window_size = config.window_size;
	_nbButtons = menu_tree.getTree().size();
	_menu_height = _nbButtons * MENU_BUTTON_HEIGHT + ((_nbButtons - 2) * MENU_BUTTON_SPACING);
	assert(_menu_height < _window_size.height);

	_starting_pos.x = _window_size.width / 2 - MENU_BUTTON_WIDTH / 2;
	_starting_pos.y = _window_size.height / 2 - _menu_height / 2;

	setTheme(*config.theme);

	for (int i = 0; i < _nbButtons; i++) {
		MenuButton button;
		button.setSize(MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);
		button.setColor(_default_color);
		_menu_buttons.push_back(button);
	}
}

void	MainScreen::setTheme(Theme &t) {
	_default_color = t.getMenuDefault();
	_hover_color = t.getMenuHover();
	_inactive_color = t.getMenuInactive();
}

void	MainScreen::draw() {

	float	y = _starting_pos.y;

	for (int i = 0; i < _nbButtons; i++) {
		_menu_buttons[i].setValues(_starting_pos.x, y, MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT, _window_size);
		_menu_buttons[i].draw(_renderer);
		y += MENU_BUTTON_HEIGHT + MENU_BUTTON_SPACING;
	}
}


std::vector<MenuButton>&	MainScreen::getMenuButtons() {
	return _menu_buttons;
}


void	MainScreen::printInfo() {
	std::cout << "Nb buttons : " << _nbButtons << std::endl;
	std::cout << "Button size : " << MENU_BUTTON_WIDTH << "x" << MENU_BUTTON_HEIGHT << std::endl;
	std::cout << "Starting position : [" << _starting_pos.x << "," << _starting_pos.y << "]" << std::endl;
	std::cout << "Menu size : " << _menu_height << std::endl;
	std::cout << "Button spacing : " << MENU_BUTTON_SPACING << std::endl;
}





