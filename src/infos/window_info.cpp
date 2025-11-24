#include "pch.h"
#include "argument_handler.h"


void	printWindowInfo(SDL_Window* window) {
	int		width;
	int		height;
	int		x;
	int		y;

	SDL_GetWindowSize(window, &width, &height);
	SDL_GetWindowPosition(window, &x, &y);
	std::cout << std::endl;
	std::cout << "-================-" << std::endl;
	std::cout << "| --info-window  |" << std::endl;
	std::cout << "-================-\n" << std::endl;

	std::cout << SEPARATOR << std::endl;
	std::cout << "Window Display : 	" << SDL_GetDisplayForWindow(window) << std::endl;
	std::cout << "Window Size : 		" << width << " x " << height << std::endl;
	std::cout << "Window Position : 	" << x << " x " << y << std::endl;
	std::cout << SEPARATOR << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

}

int	runWindowInfoMode(Application &app) {

	bool		close_window = false;
	t_color		background = app.getTheme().getBackground();
	SDL_Event	e;
	bool		print_info = true;

	while (!close_window)
	{
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EVENT_QUIT) {
				close_window = true;
			}
			else if (e.type == SDL_EVENT_WINDOW_RESIZED || e.type == SDL_EVENT_WINDOW_MOVED)
			{
				print_info = true;
			}
		}
		if (print_info)
		{
			printWindowInfo(app.getWindow());
			print_info = false;
		}

		SDL_SetRenderDrawColor(app.getRenderer(), background.r , background.g, background.b, SDL_ALPHA_OPAQUE);
		// [...]
		SDL_RenderClear(app.getRenderer());
		SDL_RenderPresent(app.getRenderer());

	}
	return 0;
}
