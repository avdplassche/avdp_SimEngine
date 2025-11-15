#include "Color.hpp"

Color::Color():r(1.0f), g(1.0f), b(1.0f), a(1.0f)  {}

Color::Color(int red, int green, int blue, int alpha):
			r(normalizeColor(red)), g(normalizeColor(green)), b(normalizeColor(blue)), a(normalizeColor(alpha))
{

}

Color::Color(float red, float green, float blue, float alpha):
			r(red), g(green), b(blue), a(alpha)
{

}
