/*
 * Controller.hpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Tomek Ferens (fero)
 */

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_
#include "main.hpp"

class Controller{
public:
	typedef boost::signals::connection conn;
	boost::signal <bool(void *wsk)>SigC;
	Controller();
	bool detected;
	Module * modules[NO_MODULES];
	bool lunit(int nr,void* wsk);	//Logic unit - function handling all actions between objects

	~Controller();
private:
	conn c_net;
	conn c_mot_0;
	conn c_mot_1;
};


#endif /* CONTROLLER_HPP_ */
