#pragma once

#include "pch.h"

//void		framebuffer_size_callback(GLFWwindow* window, int width, int height);
float		normalizePosition(int val, int total, char axe);
float		normalizeColor(int color);
void		new_log(std::string s, int c);

//t_fColor		newFloatColor(float r, float g, float b, float a);
t_color		newColor(int r, int g, int b, int a);
t_color		colorHexToInt(std::string hex);
void		copyColor(t_color& source, t_color& copy);
//t_color		colFloatToInt(t_fColor &c);

