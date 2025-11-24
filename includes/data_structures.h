#pragma once

typedef enum e_debugMode {
	DEFAULT_MODE,
	WINDOW_INFO_MODE,
	TEST_MODE
}				t_debugMode;

typedef enum e_logColor {
	GREEN_LOG,
	RED_LOG,
	BLUE_LOG,
	YELLOW_LOG
}				t_logColor;

typedef enum e_menuType
{
	ROUTE,
	CHECKBOX,
	ACTION,
	BACK,
	QUIT
}			t_menuType;

typedef enum e_coordinates_rl {
	LEFT,
	RIGHT
}				t_coordinates_rl;

typedef enum e_coordinates_tb {
	TOP,
	BOTTOM
}				t_coordinates_tb;


typedef enum e_appState {
	MENU,
	GAME_MENU,
	GAME
}				t_appState;

typedef struct s_size {
	int			width;
	int			height;
}				t_size;

typedef struct s_color {
	int			r;
	int			g;
	int			b;
	int			a;
}				t_color;

typedef struct s_menu
{
	std::string				content;
	std::vector<s_menu>		sub;
	s_menu					*parent;
	int						level;
	t_menuType				type;
}				t_menu;

class Theme;

typedef struct s_mainScreenConfig {
	SDL_Renderer	*renderer;
	int				nbButtons = 0;
	t_size			window_size;
	Theme			*theme;
}					t_mainScreenConfig;


typedef struct s_pos {
	int			x;
	int			y;
}				t_pos;



