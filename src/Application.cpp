#include "Application.hpp"
#include "argument_handler.h"
#include "MenuTree.hpp"


Application::Application() {}

Application::Application (const Application& source) {
	*this = source;
}

Application& Application::operator=(const Application& source) {
	if (this != &source)
	{
		this->_renderer = source._renderer;
		this->_window = source._window;
	}
	return *this;
}

Application::~Application() {
}

////////////////////////////////////////
////			INIT				////
////////////////////////////////////////


void	Application::init() {
	if (!SDL_Init(SDL_INIT_VIDEO))
		throw ExceptionSDLInitialize();
	try {
		_initWindow();
		_initRenderer();
		_app_menu.load(APP_MENU_FILE);
		_theme.setTheme(THEME);
		_initMainScreen();
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

int	Application::_initWindow() {

	_window = SDL_CreateWindow("GOL", WINDOW_WIDTH, WINDOW_HEIGHT,SDL_WINDOW_FULLSCREEN);
	if (!_window)
	{
		new_log(SDL_GetError(), RED_LOG);
		throw ExceptionSDLWindow();
	}
	SDL_GetWindowSize(_window, &_window_size.width, &_window_size.height);
	SDL_GetWindowMaximumSize(_window, &_monitor_resolution.width, &_monitor_resolution.height);
	return 0;
}

int	Application::_initRenderer() {
	_renderer = SDL_CreateRenderer(_window, NULL);
	if (!_renderer)
	{
		new_log(SDL_GetError(), RED_LOG);
		throw ExceptionSDLRenderer();
	}
	return 0;
}

int	Application::_initMainScreen() {
	t_mainScreenConfig	msc;
	msc.renderer = _renderer;
	msc.nbButtons = _app_menu.getTree().size() + 1;
	msc.window_size = _window_size;
	msc.theme = &_theme;
	_main_screen.setValues(_app_menu, msc);
	return 0;
}

////////////////////////////////////////
////			RUN					////
////////////////////////////////////////


int	Application::run() {

	bool		close_window = false;
	SDL_Event	e;

	new_log("Window loop ready.", GREEN_LOG);


	while (!close_window)
	{
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_EVENT_QUIT) {
				close_window = true;
			}
		}

		processInput();

		SDL_SetRenderDrawColor(_renderer, 0 , 0, 0, SDL_ALPHA_OPAQUE);

		// [...]

		SDL_RenderClear(_renderer);

		// *You would draw your game elements here*

		SDL_RenderPresent(_renderer);
	}
	return 0;
}

void	Application::applyTheme() {
	_main_screen.setTheme(_theme);
}


void Application::processInput()
{
}

SDL_Window*		Application::getWindow() const {
	return _window;
}

SDL_Renderer*	Application::getRenderer() const {
	return _renderer;
}

t_size			Application::getWindowSize() const {
	return _window_size;
}

t_size			Application::getMonitorResolution() const {
	return _monitor_resolution;
}

MenuTree&		Application::getAppMenus(){
	return _app_menu;
}

Theme&			Application::getTheme() {
	return _theme;
}

MainScreen&		Application::getMainScreen(){
	return _main_screen;
}

