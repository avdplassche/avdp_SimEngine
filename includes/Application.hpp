#pragma once

#include "pch.h"
#include "Theme.hpp"
#include "Menu.hpp"

class Application {

private:
	GLFWwindow			*_window = NULL;
	GLFWmonitor			*_monitor = NULL;
	GLFWmonitor			**_monitor_list = NULL;
	const GLFWvidmode	*_mode = NULL;
	int					_nbMonitors;

	t_size				_window_resolution;
	t_size				_monitor_resolution;

	int					_initWindow();
	int					_initMonitor();
	int					_initCursor();

	Menu				_app_menu;
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

	GLFWwindow			*getWindow() const;
	GLFWmonitor			*getMonitor() const;

	Menu&				getAppMenus();
	Theme&				getTheme();

};

