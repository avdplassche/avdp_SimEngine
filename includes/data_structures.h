#pragma once

typedef enum e_debugMode {
	DEFAULT_MODE,
	WINDOW_INFO_MODE,
	TEST_MODE
}				t_debugMode;

typedef enum e_logType {
	INFO_LOG,
	ERROR_LOG,
	DEBUG_LOG,
	WARNING_LOG
}				t_logType;

typedef enum e_menuType
{
	MENU_ROUTE,
	MENU_CHECKBOX,
	MENU_ACTION,
	MENU_BACK,
	MENU_THEME,
	MENU_QUIT
}			t_menuType;

typedef enum e_coordinates_rl {
	LEFT,
	RIGHT
}				t_coordinates_rl;

typedef enum e_coordinates_tb {
	TOP,
	BOTTOM
}				t_coordinates_tb;

typedef enum e_buttonState {
	BUTTON_STATE_DEFAULT,
	BUTTON_STATE_HOVER,
	BUTTON_STATE_INACTIVE
}				t_buttonState;

typedef enum e_appState {
	APP_STATE_MAIN_MENU,
	APP_STATE_UI_DEV,
	APP_STATE_GOL_MENU,
	APP_STATE_GOL
}				t_appState;


typedef struct s_size {
	int			w;
	int			h;
}				t_size;

typedef struct s_padding {
	int			l;
	int			r;
	int			t;
	int			b;
}				t_padding;

typedef struct s_color {
	int			r;
	int			g;
	int			b;
	int			a;
}				t_color;

typedef struct s_menu
{
	std::string				content;
	std::vector<s_menu *>	sub;
	s_menu					*parent;
	int						level;
	t_menuType				type;
}				t_menu;

class Theme;

typedef struct s_MenuScreenConfig {
	SDL_Renderer	*renderer;
	int				nbButtons = 0;
	t_size			window_size;
	Theme			*theme;
	TTF_TextEngine	*text_engine;
	TTF_Font		*font;
}					t_MenuScreenConfig;

typedef struct s_pos {
	int				x;
	int				y;
}					t_pos;


typedef struct s_UIMatriceConfig {
	SDL_Renderer	*renderer;
	t_pos			pos;
	t_size			size;
	t_size			table_size;
	t_size			cell_size;
	char			orientation;
	bool			isVisible;
	Theme			*theme;
}					t_UIMatriceConfig;


typedef struct s_cell {
	int				i;
	int				j;
	SDL_Rect		*rect;
	bool			hover;
	t_color			c;
}				t_cell;


