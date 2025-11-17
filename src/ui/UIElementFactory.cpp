#include "UIElementFactory.hpp"


AUIElement	*UIElementFactory::createMenuButton() const {
	return new MenuButton();
}

AUIElement	*UIElementFactory::createDiv() const {
	return new Div();
}
