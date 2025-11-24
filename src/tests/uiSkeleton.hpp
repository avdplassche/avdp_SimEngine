#include <string>
#include <vector>
#include "pch.h"

class	Widget {

};


// Question : how to put a container in another one

class Container {

private:
	std::string				name; // if name.empty, no name
	std::vector<Widget>		_widgets;
	std::vector<Container>	_containers;
	//bool

	//GLfloat					_colour[4];

	int						_width;
	int						_height;
	int						_col;
	int						_row;

public:
	int						addWidget(const Widget &);
	void					draw();
	Container();
	~Container();



};

