#pragma once

#include "pch.h"
#include "Theme.hpp"
#include "MenuTree.hpp"
#include "MenuScreen.hpp"
#include "UI.hpp"

class Application {

private:
	SDL_Window					*_window = NULL;
	SDL_Renderer				*_renderer = NULL;
	TTF_TextEngine				*_text_engine = NULL;
	TTF_Font					*_font = NULL;
	SDL_Point					_mouse_pos = {0, 0};

	bool						_isRuning = true;

	t_appState					_state;

	t_size						_window_size;
	//t_size					_monitor_resolution;

	int							_initWindow();
	int							_initRenderer();
	int							_initTextEngine();
	int							_initThemeList();
	int							_initMenuScreen();

	MenuTree					_menu_tree;
	//MenuTree					_game_menu;

	//UI							_UI;

	MenuScreen					_menu_screen;


	std::vector<std::string>	_theme_list;
	size_t						_current_theme_index;
	Theme						_theme;



////	DEV		////

	int							_initUIDev();
	UIMatrice					_UI_matrice_dev;



////////////////////


public:
	Application();
	Application (const Application&);
	Application& operator=(const Application&);
	~Application();

	void				init();
	int					run();


	//void				recalculateData(); // used if resolution is changed

	t_size				getWindowSize() const;
	//t_size				getMonitorResolution() const;

	SDL_Window			*getWindow() const;
	SDL_Renderer		*getRenderer() const;

	t_appState			getState() const;

	MenuTree&			getAppMenus();
	Theme&				getTheme();
	MenuScreen&			getMenuScreen();
	SDL_Point			getMousePos() const;

	void				setState(t_appState state);
	void				setTheme(std::string theme_name);
	void				setFont(std::string font_path);
	void				setWindowSize(int w, int h);

	void				setMousePos(int x, int y);
	void				switchTheme();

	void				processInput(SDL_Event *event);

	void				printInfos();

	bool				isRuning() const;
	void				quit();


////	DEV		////

	UIMatrice&			getUIDevMatrice();

////////////////////

};

