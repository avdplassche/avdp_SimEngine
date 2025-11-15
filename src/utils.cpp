#include "utils.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	(void)window;
	glViewport(0, 0, width, height);
}

float	normalize(int val, int total) {

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

