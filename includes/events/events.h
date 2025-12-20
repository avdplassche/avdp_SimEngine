#pragma once


#include "Application.hpp"
#include "pch.h"

void	handleEvents(SDL_Event *e, Application *app);
void	handleGeneralEvents(SDL_Event *e, Application *app);

void	handleMenuScreenEvents(SDL_Event *e, Application *app);
void	handleUIDevEvents(SDL_Event *e, Application *app);
