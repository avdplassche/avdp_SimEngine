#include "MenuScreen.hpp"

MenuScreen::MenuScreen() {}

MenuScreen::~MenuScreen() {}


void	MenuScreen::setValues(MenuTree& menu_tree, t_MenuScreenConfig& config) {
	_setConfig(config);
	newLog("Menu Screen : Conf loaded", DEBUG_LOG);
	_setMenuTree(menu_tree);
	newLog("Menu Screen : Menu tree loaded", DEBUG_LOG);
	_setMenuData();
	newLog("Menu Screen : Menu Data loaded", DEBUG_LOG);
	setTheme();
	newLog("Menu Screen : Theme loaded", DEBUG_LOG);
	_setDiv();
	newLog("Menu Screen : Div loaded", DEBUG_LOG);
	_setButtons();
	newLog("Menu Screen : Buttons loaded", DEBUG_LOG);
}

void	MenuScreen::changeCurrentMenu(t_menu current_menu)
{
	_current_menu = current_menu;
	_nbButtons = _current_menu.sub.size();
	_setMenuData();
	_setDiv();
	_setButtons();
	_printChangeMenuInfo();
}

void	MenuScreen::_setConfig(t_MenuScreenConfig &config) {
	_renderer = config.renderer;
	_text_engine = config.text_engine;
	_font = config.font;
	_window_size = config.window_size;
	_theme = config.theme;
}

void	MenuScreen::_setMenuTree(MenuTree& menu_tree) {
	_current_menu = menu_tree.getTree();
	_nbButtons = _current_menu.sub.size();
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

	std::string title;

	if (_current_menu.content == "Root")
		title = "Menu";
	else
		title = _current_menu.content;
	_div_padding = {MENU_PADDING_L, MENU_PADDING_R, MENU_PADDING_T, MENU_PADDING_B};
	_div.setPos(_starting_pos.x - _div_padding.l, _starting_pos.y - _div_padding.t);
	_div.setSize(MENU_BUTTON_WIDTH + MENU_PADDING_L + MENU_PADDING_R,
		_menu_height + MENU_PADDING_T + MENU_PADDING_B);
	_div.setFilled(true);
	_div.setTitle(_text_engine, _font, title);
	_div.setTitlePos((_div.getPos().x * 2 + _div.getSize().w) / 2 - _div.getTitleSize().w / 2
					, _div.getPos().y + MENU_TITLE_PADDING_T);
}

void	MenuScreen::_setButtons() {
	if (!_menu_buttons.empty())
		_menu_buttons.clear();
	float	y = _starting_pos.y;
	for (int i = 0; i < _nbButtons; i++) {
		MenuButton button;
		button.setSize(MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT);
		button.setTheme(*_theme);
		button.setText(_current_menu.sub[i]->content, _text_engine, _font);
		button.setValues(_starting_pos.x, y, MENU_BUTTON_WIDTH, MENU_BUTTON_HEIGHT, _window_size);
		_menu_buttons.push_back(button);
		y += MENU_BUTTON_HEIGHT + MENU_BUTTON_SPACING;
	}
}

void	MenuScreen::draw() {

	SDL_SetRenderDrawColor(_renderer, _background_color->r + 20 , _background_color->g + 20, _background_color->b + 20, SDL_ALPHA_OPAQUE);
	_div.draw(_renderer);
	SDL_SetRenderDrawColor(_renderer, _background_color->r , _background_color->g, _background_color->b, SDL_ALPHA_OPAQUE);
	for (int i = 0; i < _nbButtons; i++) {
		_menu_buttons[i].draw(_renderer);
	}
}


std::vector<MenuButton>&	MenuScreen::getMenuButtons() {
	return _menu_buttons;
}

t_menu&	MenuScreen::getCurrentMenu() {
	return _current_menu;
}

void	MenuScreen::setWindowSize(int w, int h) {
	_window_size.w = w;
	_window_size.h = h;
	_setMenuData();
	_setDiv();
	_setButtons();
}

void	MenuScreen::printInfo() {
	std::cout << "Nb buttons : " << _nbButtons << '\n';
	std::cout << "Button size : " << MENU_BUTTON_WIDTH << "x" << MENU_BUTTON_HEIGHT << '\n';
	std::cout << "Starting position : [" << _starting_pos.x << "," << _starting_pos.y << "]" << '\n';
	std::cout << "Menu size : " << MENU_BUTTON_WIDTH << "x" <<  _menu_height << '\n';
	std::cout << "Button spacing : " << MENU_BUTTON_SPACING << '\n';
}

void	MenuScreen::_printChangeMenuInfo() {

	if (DEBUG_MODE != 2)
		return ;
	std::cout << "\n===== PRINT MENU CHANGE ====\n\n";
	std::cout << "Buttons number : " << _nbButtons << '\n';
	for (size_t i = 0; i < _current_menu.sub.size(); i++)
		std::cout <<  _current_menu.sub[i]->content << "\n";
	std::cout << "\n===========================\n\n";
	//for (size_t i = 0; i < _current.sub.size(); i++)
	//	std::cout <<  _current.sub[i].content << "\n";
}



