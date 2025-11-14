#ifndef INFO_HANDLER_H
# define INFO_HANDLER_H

#include "Application.hpp"


int			handleArgument(char *argv, Application& app);
int			printMonitorInfo();
int			printWindowInfo(GLFWwindow* window);
void		setWindowHintEvent(GLFWwindow *window);


#define SEPARATOR "---------------------------------------------------------------------------------------------"


#endif