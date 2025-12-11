#ifndef CONFIG_H
# define CONFIG_H



#ifndef DEBUG_MODE
# define DEBUG_MODE 0
#endif


////////////////////////////////////////
////			GRAPHIC				////
////////////////////////////////////////


#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

#define	MENU_BUTTON_WIDTH 200
#define	MENU_BUTTON_HEIGHT 32
#define	MENU_BUTTON_SPACING 16

#define MENU_PADDING_L 50
#define MENU_PADDING_R 50
#define MENU_PADDING_T 100
#define MENU_PADDING_B 50
#define MENU_TITLE_PADDING_T 30


////////////////////////////////////////
////			DATA				////
////////////////////////////////////////

#define THEME "Riga"
#define APP_MENU_FILE "data/app_menu.txt"
#define GAME_MENU_FILE "data/game_menu.txt"

#define FONT_MONTSERRAT "assets/fonts/Montserrat-Medium.ttf"
#define FONT_ARIAL "assets/fonts/Arial.ttf"
#define FONT_INTER "assets/fonts/Inter-VariableFont_opsz,wght.ttf"
#define FONT_MANROPE "assets/fonts/Manrope-VariableFont_wght.ttf"

#define FONT_CURRENT FONT_INTER


#ifndef THEME
# define THEME "default"
#endif

#endif
