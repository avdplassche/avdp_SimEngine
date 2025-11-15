#include "MainScreen.hpp"

MainScreen::MainScreen(int nbButtons, int buttonWidth, int buttonHeight):
					_nbButtons(nbButtons),
					_buttonWidth(buttonWidth),
					_buttonHeight(buttonHeight)
{

	for (int i = 0; i < _nbButtons; i++) {
		MenuButton button;
		button.setSize(_buttonWidth, _buttonHeight);
		_menu_buttons.push_back(button);
	}
}



void	MainScreen::draw() {

}
