#ifndef DEBUG_H
# define DEBUG_H

// Example : PRINT_DEBUG("The value is: " << value);

#define PRINT_DEBUG(msg) \
	do { \
		std::cerr << "DEBUG: " << __FILE__ << ":" << __LINE__ \
					<< " | " << msg << '\n'; \
	} while (false)



#endif