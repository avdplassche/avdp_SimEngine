#include "MenuScreen.hpp"

MenuScreen::MenuScreen() {}

MenuScreen::~MenuScreen() {}

void	MenuScreen::setValues(MenuTree& menu_tree, t_MenuScreenConfig& config) {
	_setConfig(config);
	_setMenuTree(menu_tree);
	_setMenuData();
	setTheme();
	_setDiv();
	_setButtons();
}

void	MenuScreen::_setConfig(t_MenuScreenConfig &config) {
	_renderer = config.renderer;
	_text_engine = config.text_engine;
	_font = config.font;
	_window_size = config.window_size;
	_theme = config.theme;
}

void	MenuScreen::_setMenuTree(MenuTree& menu_tree) {
	_menu_tree = &menu_tree;
	_current_menu = _menu_tree->getTree().at(0);
	std::cout << _current_menu.content << '\n';
	_nbButtons = _current_menu.sub.size();
	//_nbButtons = _menu_tree->getTree().size();
}

void	MenuScreen::_setMenuData() {

	_menu_height = _nbButtons * MENU_BUTTON_HEIGHT + ((_nbButtons - 1) * MENU_BUTTON_SPACING);
	assert(_menu_height < _window_size.h);
	_starting_pos.x = _window_size.w / 2 - MENU_BUTTON_WIDTH / 2;
	_starting_pos.y = _window_size.h / 2 - _menu_height / 2;
}

void	MenuScreen::setTheme() {
	_background_color = &_theme->getBackground();
}

void	MenuScreen::_setDiv() {

	_div_padding = {MENU_PADDING_L, MENU_PADDING_R, MENU_PADDING_T, MENU_PADDING_B};
	_div.setPos(_starting_pos.x - _div_padding.l, _starting_pos.y - _div_padding.t);
	_div.setSize(MENU_BUTTON_WIDTH + MENU_PADDING_L + MENU_PADDING_R,
				_menu_height + MENU_PADDING_T + MENU_PADDING_B);
	_div.setFilled(true);
	_div_title = TTF_CreateText(_text_engine, _font, _div_title_string.c_str(),  _div_title_string.size());
	TTF_GetTextSize(_div_title, &_div_title_size.w, &_div_title_size.h);
	std::cout << "Title size " << _div_title_size.w << "x" << _div_title_size.h << '\n';

}

void	MenuScreen::_setButtons() {
	_nbButtons = _current_menu.sub.size();
	for (int i = 0; i < _nbButtons; i++) {
		MenuButton button;
		button.setSize(MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);
		button.setTheme(*_theme);
		_menu_buttons.push_back(button);
	}
}

void	MenuScreen::draw() {

	float	y = _starting_pos.y;

	SDL_SetRenderDrawColor(_renderer, _background_color->r + 20 , _background_color->g + 20, _background_color->b + 20, SDL_ALPHA_OPAQUE);
	_div.draw(_renderer);
	SDL_SetRenderDrawColor(_renderer, _background_color->r , _background_color->g, _background_color->b, SDL_ALPHA_OPAQUE);
	for (int i = 0; i < _nbButtons; i++) {
		_menu_buttons[i].setValues(_starting_pos.x, y, MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT, _window_size);
		_menu_buttons[i].draw(_renderer);
		y += MENU_BUTTON_HEIGHT + MENU_BUTTON_SPACING;
	}
	TTF_SetTextColor(_div_title, 55, 55, 55, 255);  // add theme color
	TTF_DrawRendererText(_div_title, _starting_pos.x, _starting_pos.y);
}


std::vector<MenuButton>&	MenuScreen::getMenuButtons() {
	return _menu_buttons;
}

void	MenuScreen::_setDivTitle() {
	//TTF_CreateText()

}

void	MenuScreen::printInfo() {
	std::cout << "Nb buttons : " << _nbButtons << '\n';
	std::cout << "Button size : " << MENU_BUTTON_WIDTH << "x" << MENU_BUTTON_HEIGHT << '\n';
	std::cout << "Starting position : [" << _starting_pos.x << "," << _starting_pos.y << "]" << '\n';
	std::cout << "Menu size : " << MENU_BUTTON_WIDTH << "x" <<  _menu_height << '\n';
	std::cout << "Button spacing : " << MENU_BUTTON_SPACING << '\n';
}





