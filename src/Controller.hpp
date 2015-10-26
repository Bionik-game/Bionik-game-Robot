/*
 * Controller.hpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Tomek Ferens (fero)
 */

#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_
#include "main.hpp"

class Controller: public Module{
public:
	typedef boost::signals::connection conn;
	boost::signal <bool(void *wsk)>SigC;
	Controller(void*);
	bool detected;
	unsigned short int robotId;
	Module * modules[NO_MODULES];
	bool lunit(int nr,void* wsk);	//Logic unit - function handling all actions between objects
bool work(void *m){
	return 0;
}
	~Controller();
private:
	conn c_net;
	conn c_mot_0;
	conn c_gpd;
};


#endif /* CONTROLLER_HPP_ */
