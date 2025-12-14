#ifndef DEBUG_H
# define DEBUG_H

// Example : PRINT_DEBUG("The value is: " << value);
#include "pch.h"

#define PRINT_DEBUG(msg) \
	do { \
		std::cerr << "DEBUG: " << __FILE__ << ":" << __LINE__ \
					<< " | " << msg << '\n'; \
	} while (false)

void		newLog(std::string s, int log_type);
void		debugPrintInt(std::string name, int n);
void		debugPrintString(std::string name, std::string s);



#endif