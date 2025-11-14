#ifndef DEBUG_H
# define DEBUG_H

#define PRINT_DEBUG(msg) \
	do { \
		std::cerr << "DEBUG: " << __FILE__ << ":" << __LINE__ \
					<< " | " << msg << std::endl; \
	} while (false)

// Example : PRINT_DEBUG("The value is: " << value);


#endif