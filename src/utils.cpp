#include "utils.h"

//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	(void)window;
//	glViewport(0, 0, width, height);
//	//
//}

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

void	new_log(std::string s, int c)
{
	switch (c)
	{
		case GREEN_LOG:
			std::cout << C_FG_GREEN_CODE;
			break;
		case RED_LOG:
			std::cout << C_FG_RED_CODE;
			break;
		case BLUE_LOG:
			std::cout << C_FG_BLUE_CODE;
			break;
		case YELLOW_LOG:
			std::cout << C_FG_YELLOW_CODE;
			break;
		default:
			break;
	}
	std::cout << "[INFO]	" << s << C_RESET << std::endl;

}


t_color	newColor(int r, int g, int b, int a) {
	assert (0 <= r && r <= 255);
	assert (0 <= g && g <= 255);
	assert (0 <= b && b <= 255);
	assert (0 <= a && a <= 100);

	t_color c;
	c.r = r;
	c.g = g;
	c.b = b;
	c.a = a;
	return c;
}
static int hexConverter(char c) {
	assert(isdigit(c) || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
	if (isdigit(c))
		return c - 48;
	else if ('a' <= c && c <= 'f')
		return c - 87;
	return c - 55;
}

t_color		colorHexToInt(std::string hex) {

	assert(hex[0] == '#');
	assert(hex.size() == 7);

	int	r = hexConverter(hex[1]) * 15 + hexConverter(hex[2]);
	int	g = hexConverter(hex[3]) * 15 + hexConverter(hex[4]);
	int	b = hexConverter(hex[5]) * 15 + hexConverter(hex[6]);
	int a = 100;

	return newColor(r, g, b, a);
}

//t_color		colFloatToInt(t_fColor &source) {
//	return newIntColor((int)source.r * 255, (int)source.g * 255, (int)source.b * 255, (int)source.r * 100);
//}

//t_fColor	newRgbColor(int r, int g, int b, int a) {
//	assert (0 <= r && r <= 255);
//	assert (0 <= g && g <= 255);
//	assert (0 <= b && b <= 255);
//	assert (0 <= a && a <= 100);

//	t_fColor c;
//	c.r = (float)r / 255.0f;
//	c.g = (float)g / 255.0f;
//	c.b = (float)b / 255.0f;
//	c.a = (float)a / 100.0f;
//	return c;
//}

//t_fColor	newFloatColor(float r, float g, float b, float a) {

//	assert (0.0f <= r && r <= 1.0f);
//	assert (0.0f <= g && g <= 1.0f);
//	assert (0.0f <= b && b <= 1.0f);
//	assert (0.0f <= a && a <= 1.0f);

//	t_fColor c;
//	c.r = r;
//	c.g = g;
//	c.b = b;
//	c.a = a;
//	return c;
//}