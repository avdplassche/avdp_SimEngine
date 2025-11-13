#ifndef INFO_HANDLER_H
# define INFO_HANDLER_H

int			handleArgument(char *argv, GLFWwindow* window);
int			printMonitorInfo();
int			printWindowInfo(GLFWwindow* window);
void		setWindowHintEvent(GLFWwindow *window);


#define SEPARATOR "----------------------------------------------------------"


#endif