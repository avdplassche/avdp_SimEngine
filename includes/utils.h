#pragma once

#include "pch.h"

float		normalizePosition(int val, int total, char axe);
float		normalizeColor(int color);


t_color		newColor(int r, int g, int b, int a);
t_color		colorHexToInt(std::string hex);
void		copyColor(t_color& source, t_color& copy);


