#include "uiSkeleton.hpp"

Container::Container() {}
Container::~Container() {}


void			Container::draw() {
		//glBegin(GL_QUADS);
		//glColor3f(1.0f, .0f, .0f); // White color
		//glVertex2f(-0.2f,  0.2f); // Top-left vertex
		//glVertex2f( 0.2f,  0.2f); // Top-right vertex
		//glVertex2f( 0.2f, -0.2f); // Bottom-right vertex
		//glVertex2f(-0.2f, -0.2f); // Bottom-left vertex
		//glEnd();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glBegin(GL_TRIANGLES);
    	glColor4f(1.0f, 0.0f, 0.0f, 0.5f); // Red
    	glVertex2f(-0.2f,  -0.2f);
    	glColor4f(0.0f, 1.0f, 0.0f, 0.5f); // Green
    	glVertex2f(0.2f,  -0.2f);
    	glColor4f(0.0f, 0.0f, 1.0f, 0.5f); // Blue
    	glVertex2f(0.0f,  0.2f);
    // Pixels inside the triangle will be interpolated
glEnd();

}