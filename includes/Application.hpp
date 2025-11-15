#pragma once

#include "pch.h"
#include "Theme.hpp"

class Application {

private:
	GLFWwindow			*_window = NULL;
	GLFWmonitor			*_monitor = NULL;
	GLFWmonitor			**_monitor_list = NULL;
	const GLFWvidmode	*_mode = NULL;
	int					_nbMonitors;

	int					_window_width;
	int					_window_height;
	t_size				_window_size;
	int					_monitor_width;
	int					_monitor_height;

	int					_initWindow();
	int					_initMonitor();
	int					_initCursor();
	//Theme&				_theme;

public:
	Application();
	Application (const Application&);
	Application& operator=(const Application&);
	~Application();

	int					init();
	int					run();

	void				processInput();

	void				recalculateData(); // used if resolution is changed

	t_size				getWindowSize() const;
	int					getWindowHeight() const;
	int					getMonitorWidth() const;
	int					getMonitorHeight() const;

	GLFWwindow			*getWindow() const;
	GLFWmonitor			*getMonitor() const;


};

