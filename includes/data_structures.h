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
	ACTION
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
	float		width;
	float		height;
}				t_size;

typedef struct s_color {
	float		r;
	float		g;
	float		b;
	float		a;
}				t_color;


typedef struct s_mainScreenConfig {
	int			nbButtons = 0;
	t_color		default_color;
	t_color		hover_color;
	t_color		inactive_color;
	t_size		window_size;
}				t_mainScreenConfig;


typedef struct s_pos {
	float		x;
	float		y;
}				t_pos;



