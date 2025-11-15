#include "utils.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

float	normalizePosition(int val, int total, char axe) {
	assert(axe == 'y' || axe == 'x');
	if (axe == 'x')
		return ((float)val * 2 / (float)total - 1);
	val = total - val;
	return ((float)val * 2 / (float)total - 1);
}

float	normalizeColor(int color) {
	assert(color < 256 && color >= 0);
	return ((float)color / 255);
}

//val -> total
//? -> 2
