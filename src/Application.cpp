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
	if (!TTF_Init())
		throw ExceptionTTFInitialize();
	try {
		_initWindow();
		_initRenderer();
		_initTextEngine();
		_menu_tree.load(APP_MENU_FILE);
		_theme.setTheme(THEME);
		_initMenuScreen();
	}
	catch (std::exception &e){
		std::cout << "Exception catched : " << e.what() << '\n';
	}
}

int	Application::_initWindow() {

	//_window = SDL_CreateWindow("GOL", WINDOW_WIDTH, WINDOW_HEIGHT,SDL_WINDOW_FULLSCREEN);
	_window = SDL_CreateWindow("GOL", WINDOW_WIDTH, WINDOW_HEIGHT,SDL_WINDOW_RESIZABLE);
	if (!_window)
	{
		new_log(SDL_GetError(), RED_LOG);
		throw ExceptionSDLWindow();
	}
	SDL_GetWindowSize(_window, &_window_size.w, &_window_size.h);
	SDL_GetWindowMaximumSize(_window, &_monitor_resolution.w, &_monitor_resolution.h);
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

int	Application::_initTextEngine() {
	_text_engine = TTF_CreateRendererTextEngine(_renderer);
	if (!_text_engine)
	{
		new_log("Couldn't open text engine", RED_LOG);
		throw ExceptionSDLTextEngine();
	}
	_font = TTF_OpenFont(FONT_CURRENT, 20);
	if (!_font)
	{
		new_log(SDL_GetError(), RED_LOG);
		throw ExceptionSDLFont();
	}
	return 0;
}

int	Application::_initMenuScreen() {
	t_MenuScreenConfig	msc;
	msc.renderer = _renderer;
	msc.window_size = _window_size;
	msc.theme = &_theme;
	msc.text_engine = _text_engine;
	msc.font = _font;
	_menu_screen.setValues(_menu_tree, msc);
	new_log("Menu Screen Loaded", GREEN_LOG);
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
			//std::cout << "Type : " << e.type <<  "\n";
			//processInput(&e);
		}

		//SDL_SetRenderDrawColor(_renderer, 0 , 0, 0, SDL_ALPHA_OPAQUE);

		// [...]

		SDL_RenderClear(_renderer);

		// *You would draw your game elements here*

		SDL_RenderPresent(_renderer);
	}
	return 0;
}


void	Application::setTheme(std::string theme_name) {
	_theme.setTheme(theme_name);
	//_menu_screen.setTheme(_theme);
	//_ui.setTheme(_theme);
	//_game_screen.setTheme(_theme);
}

void	Application::setFont(std::string font_path) {

	TTF_Font	*new_font = TTF_OpenFont(font_path.c_str(), 24);
	if (!new_font)
	{
		new_log("Couldn't open font", RED_LOG);
		new_log(SDL_GetError(), RED_LOG);
		return ;
	}
	_font = new_font;
}

void Application::processInput(SDL_Event *e) {
	(void)e;
	//if (e->type == SDL_EVENT_KEY_DOWN && e->key.scancode == 4)
	//{
		//std::cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa\n";

	//}
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
	return _menu_tree;
}

Theme&			Application::getTheme() {
	return _theme;
}

MenuScreen&		Application::getMenuScreen(){
	return _menu_screen;
}

