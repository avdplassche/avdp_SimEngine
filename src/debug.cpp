#include "debug.h"


void		debugPrintInt(std::string name, int n) {

	if (DEBUG_MODE)
		std::cout << C_FG_BLUE_CODE  << "[DEBUG]		Print debug int " << name << " : [" << n << "]\n" << C_RESET;
}

void		debugPrintString(std::string name, std::string s) {

	if (DEBUG_MODE)
		std::cout << C_FG_BLUE_CODE  << "[DEBUG]		Print debug string " << name << " : [" << s << "]\n" << C_RESET;
}