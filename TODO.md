### Todo

#### Current

- [ ] Main Menu screen
	- [X] Fill constants graphics.h menu button width, height, space
	- [ ] make the structure (is Main Screen the all tree or just one menu )
	- [ ] add back and quit to the structure
	- [X] Make the Div
	- [ ] add Border class
	- [ ] Main Screen must become Abstract
	- [ ] Make the window size callback
	- [ ] Make a new parsing for menus (like a file with a certain style, like config)



#### Important

- [ ] Make factory (to change the main screen constructor for example)
- [ ] Think about color

#### Done

- [X] Conversion -1 | 1 -> 0 | width/height

#### Other


### Ideas

- [ ] Print UI table, to be able to change UI
- [ ] Make a Resolution class
- [ ] Another window for debug


Menus :


Game of Life
	Classic
	Colour
Attraction
Settings
	Resolution
		$cb Fullscreen
		800x600
		1280×720
		1920x1080
		2560×1440
		3840x2160
	Themes

1 -

t_menu ROOT
level = -1
type = ROUTE


t_menu Game of Life
level = 0
sub = [Classic]
type = ROUTE

current = Game of Life
new_node = Classic
level = 1

current = Classic
new_mode = Colour
level = 1




