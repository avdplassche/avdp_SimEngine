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
		newLog("App : SDL Window initialized", INFO_LOG);
		_initRenderer();
		newLog("App : SDL Renderer initialized", INFO_LOG);
		_initTextEngine();
		newLog("App : SDL Text Engine", INFO_LOG);
		_initThemeList();
		_menu_tree.load(APP_MENU_FILE, &_theme_list);
		newLog("App : Menu loaded", INFO_LOG);
		_theme.setTheme(THEME);
		_initMenuScreen();
		newLog("App : Main menu screen Loaded", INFO_LOG);
		newLog("App : Theme list Loaded", INFO_LOG);
		_state = APP_STATE_MAIN_MENU;
		//printInfos();
	}
	catch (std::exception &e){
		std::cout << "Exception catched : " << e.what() << '\n';
	}
}

int	Application::_initWindow() {

	_window = SDL_CreateWindow("GOL", WINDOW_WIDTH, WINDOW_HEIGHT,SDL_WINDOW_RESIZABLE);
	if (!_window)
	{
		newLog(SDL_GetError(), ERROR_LOG);
		throw ExceptionSDLWindow();
	}
	SDL_GetWindowSize(_window, &_window_size.w, &_window_size.h);
	return 0;
}

int	Application::_initRenderer() {
	_renderer = SDL_CreateRenderer(_window, NULL);
	if (!_renderer)
	{
		newLog(SDL_GetError(), ERROR_LOG);
		throw ExceptionSDLRenderer();
	}
	return 0;
}

int	Application::_initTextEngine() {
	_text_engine = TTF_CreateRendererTextEngine(_renderer);
	if (!_text_engine)
	{
		newLog("Couldn't open text engine", ERROR_LOG);
		throw ExceptionSDLTextEngine();
	}
	_font = TTF_OpenFont(FONT_CURRENT, FONT_SIZE);
	if (!_font)
	{
		newLog(SDL_GetError(), ERROR_LOG);
		throw ExceptionSDLFont();
	}
	return 0;
}

/** Used to switch theme easily
 */
int Application::_initThemeList() {

	size_t	i = 0;

	std::filesystem::path dir_path = "themes/";
	for (auto const& dir_entry : std::filesystem::directory_iterator{dir_path})
	{
		if (dir_entry.path().string().size() < 6 || dir_entry.path().string().size() - dir_entry.path().string().rfind(".theme") != 6)
			newLog("Theme format error : " + dir_entry.path().string(), WARNING_LOG);
		std::string	theme_name(dir_entry.path().string());
		theme_name.erase(theme_name.size() - 6, theme_name.size() - 5);
		theme_name.erase(0, 7);
		if (theme_name == _theme.getName())
			_current_theme_index = i;
		_theme_list.push_back(theme_name);
		i++;
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
	return 0;
}

////////////////////////////////////////
////			RUN					////
////////////////////////////////////////


int	Application::run() {

	bool		close_window = false;
	SDL_Event	e;

	newLog("Window loop ready.", INFO_LOG);


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

		// Game elements here

		SDL_RenderPresent(_renderer);
	}
	return 0;
}

void	Application::setState(t_appState state){
	_state = state;
}


void	Application::setTheme(std::string theme_name) {
	if (_theme.getName() == theme_name)
	{
		newLog(theme_name + "theme already loaded", WARNING_LOG);
		return ;
	}
	_theme.setTheme(theme_name);
	//_menu_screen.setTheme(_theme);
	//_ui.setTheme(_theme);
	//_game_screen.setTheme(_theme);
}

void	Application::setFont(std::string font_path) {

	TTF_Font	*new_font = TTF_OpenFont(font_path.c_str(), FONT_SIZE);
	if (!new_font)
	{
		newLog("Couldn't open font", ERROR_LOG);
		newLog(SDL_GetError(), ERROR_LOG);
		return ;
	}
	_font = new_font;
}

void	Application::setWindowSize(int w, int h) {
	_window_size.w = w;
	_window_size.h = h;
}

void	Application::setMousePos(int x, int y) {
	_mouse_pos.x = x;
	_mouse_pos.y = y;
}

void	Application::switchTheme() {
	_current_theme_index++;
	if (_current_theme_index == _theme_list.size())
		_current_theme_index = 0;
	setTheme(_theme_list.at(_current_theme_index));
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

t_appState		Application::getState() const {
	return _state;
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

SDL_Point	Application::getMousePos() const {
	return _mouse_pos;
}

void	Application::printInfos() {
	std::cout << "\n===== PRINT WINDOW INFO ====\n\n";

	std::cout << "Size : " << _window_size.w << "x" << _window_size.h << '\n';

	std::cout << "\n===========================\n\n";
}
