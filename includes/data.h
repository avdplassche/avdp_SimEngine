#pragma once

typedef enum e_debugMode {
	DEFAULT,
	WINDOW,
	TEST
}				t_debugMode;


typedef enum e_coordinates_rl {
	LEFT,
	RIGHT
}				t_coordinates_rl;

typedef enum e_coordinates_tb {
	TOP,
	BOTTOM
}				t_coordinates_tb;


typedef struct s_size {
	float		width;
	float		height;
}				t_size;


typedef struct s_pos {
	float		x;
	float		y;
}				t_pos;




