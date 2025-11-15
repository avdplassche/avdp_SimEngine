#include "utils.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

float	normalizePosition(int val, int total) {

	int	half = total / 2;

	if (val < half)
	{
		return (-1 + (float)val / (float)half);
	}
	else
	{
		return ((float)val - (float)half) / half;
	}
}

float	normalizeColor(int color) {
	assert(color < 256 && color >= 0);
	return ((float)color / 255);
}
