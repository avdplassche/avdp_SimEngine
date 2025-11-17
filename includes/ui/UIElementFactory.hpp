#pragma once
#include "AUIElement.hpp"
#include "Div.hpp"
#include "MenuButton.hpp"

class UIElementFactory {


public :
	AUIElement			*createMenuButton() const;
	AUIElement			*createDiv() const;

};
