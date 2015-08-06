/*
 * Network.hpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Tomek Ferens (fero)
 */

#ifndef NETWORK_HPP_
#define NETWORK_HPP_

class Network : public Module{
public:
	Network();
	bool work(void*);
	~Network(){};
};



#endif /* NETWORK_HPP_ */
