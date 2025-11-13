#pragma once

#include "pch.h"
#include "argument_handler.h"

class Application {

private:
	GLFWwindow			*_window = NULL;
	GLFWmonitor			*_monitor = NULL;
	//const GLFWvidmode	*_mode = NULL;
	int					_window_width;
	int					_window_height;
	int					_monitor_width;
	int					_monitor_height;

public:
	Application();
	Application (const Application&);
	Application& operator=(const Application&);
	~Application();

	int					init();
	int					run();

	void				processInput();



	int					getWindowWidth() const;
	int					getWindowHeight() const;
	int					getMonitorWidth() const;
	int					getMonitorHeight() const;

	GLFWwindow			*getWindow() const;
	GLFWmonitor			*getMonitor() const;


};

