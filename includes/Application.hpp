#pragma once

#include "pch.h"
#include "Theme.hpp"
#include "MenuTree.hpp"
#include "MenuScreen.hpp"

class Application {

private:
	SDL_Window			*_window = NULL;
	SDL_Renderer		*_renderer = NULL;
	//SDL_Cursor			*_cursor = NULL;
	TTF_TextEngine		*_text_engine = NULL;
	TTF_Font			*_font = NULL;

	t_size				_window_size;
	t_size				_monitor_resolution;

	int					_initWindow();
	int					_initRenderer();
	int					_initTextEngine();
	int					_initMenuScreen();
	//int					_initCursor();

	MenuTree			_menu_tree;
	//MenuTree			_game_menu;

	MenuScreen			_menu_screen;

	Theme				_theme;




public:
	Application();
	Application (const Application&);
	Application& operator=(const Application&);
	~Application();

	void				init();
	int					run();


	void				recalculateData(); // used if resolution is changed

	t_size				getWindowSize() const;
	t_size				getMonitorResolution() const;

	SDL_Window			*getWindow() const;
	SDL_Renderer		*getRenderer() const;


	MenuTree&			getAppMenus();
	Theme&				getTheme();
	MenuScreen&			getMenuScreen();
	void				setTheme(std::string theme_name);
	void				setFont(std::string font_path);

	void				processInput(SDL_Event *event);

};

