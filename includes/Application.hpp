#pragma once

#include "pch.h"
#include "Theme.hpp"
#include "MenuTree.hpp"
#include "MainScreen.hpp"

class Application {

private:
	SDL_Window			*_window = NULL;
	SDL_Renderer		*_renderer = NULL;
	SDL_Cursor			*cursor = NULL;

	t_size				_window_size;
	t_size				_monitor_resolution;

	int					_initWindow();
	int					_initRenderer();
	int					_initMainScreen();
	//int					_initCursor();

	MenuTree			_app_menu;
	//MenuTree			_game_menu;

	MainScreen			_main_screen;

	Theme				_theme;

public:
	Application();
	Application (const Application&);
	Application& operator=(const Application&);
	~Application();

	void				init();
	int					run();

	void				processInput();

	void				recalculateData(); // used if resolution is changed

	t_size				getWindowSize() const;
	t_size				getMonitorResolution() const;

	SDL_Window			*getWindow() const;
	SDL_Renderer		*getRenderer() const;

	MenuTree&			getAppMenus();
	Theme&				getTheme();
	MainScreen&			getMainScreen();

	void				applyTheme();

};

