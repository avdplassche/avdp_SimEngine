#ifndef UI_HPP
# define UI_HPP

#include "pch.h"
#include "UIMatrice.hpp"


class UI {

private:

	UIMatrice	_ui_matrice;
	t_pos		_pos;

public:
	UI();
	~UI();


	UIMatrice		getMatrice() const;
	// top bar


	void			setPos();

	t_pos			getPos();



};





#endif
