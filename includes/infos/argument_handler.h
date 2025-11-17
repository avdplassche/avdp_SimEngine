#ifndef INFO_HANDLER_H
# define INFO_HANDLER_H

#include "Application.hpp"


void		handleArgument(char *argv, Application& app);
void		printMonitorInfo();
void		printWindowInfo(GLFWwindow* window);
void		setWindowHintEvent(GLFWwindow *window);


#define SEPARATOR "---------------------------------------------------------------------------------------------"


#endif