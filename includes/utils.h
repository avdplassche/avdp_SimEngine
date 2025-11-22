#pragma once

#include "pch.h"

void		framebuffer_size_callback(GLFWwindow* window, int width, int height);
float		normalizePosition(int val, int total, char axe);
float		normalizeColor(int color);
void		info_log(std::string s, int c);

t_color		newColor(float r, float g, float b, float a);
t_color		newRgbColor(int r, int g, int b, int a);
t_color		newHexColor(std::string hex);
