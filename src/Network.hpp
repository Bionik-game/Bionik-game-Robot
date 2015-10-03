/*
 * Network.hpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Tomek Ferens (fero)
 */

#ifndef NETWORK_HPP_
#define NETWORK_HPP_
#include "main.hpp"
using namespace std;
using namespace jsonrpc;

struct Command{
	int type;
	unsigned xCent;
	unsigned yCent;
	unsigned zRad;

};

class Network : public Module{
public:
	friend class MyStubServer;

	inline void sendSig(Command * c){
		SigW(NET,c);
	}
	HttpServer httpserver;
	Network(int);
	bool work(void*);
	~Network(){};
};



#endif /* NETWORK_HPP_ */
