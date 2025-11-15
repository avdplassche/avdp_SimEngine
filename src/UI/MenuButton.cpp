#include "MenuButton.hpp"

MenuButton::MenuButton() {}

MenuButton::MenuButton(std::string text):_text(text) {}

MenuButton::~MenuButton() {}

void	MenuButton::draw() {
	glBegin(GL_QUADS);



	glColor3f(1.0f, .0f, .0f); // White color
	glVertex2f(-0.2f,  0.2f); // Top-left vertex
	glVertex2f( 0.2f,  0.2f); // Top-right vertex
	glVertex2f( 0.2f, -0.2f); // Bottom-right vertex
	glVertex2f(-0.2f, -0.2f); // Bottom-left vertex
	//glEnd();
}



