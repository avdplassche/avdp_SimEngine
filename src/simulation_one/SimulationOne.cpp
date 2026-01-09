#include "SimulationOne.hpp"


SimulationOne::SimulationOne() {}

SimulationOne::~SimulationOne() {}

//void	SimulationOne::setUiMatrice(t_uiMatriceConfig& conf) {
//	_ui_matrice.setValues(conf);
//	_ui_matrice.printInfos();
//}

void	SimulationOne::draw() {
	_ui_matrice.draw();
}



UIMatrice&	SimulationOne::getUiMatrice() {
	return _ui_matrice;
}