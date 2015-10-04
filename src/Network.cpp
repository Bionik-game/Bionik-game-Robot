/*
 * Network.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Tomek Ferens (fero)
 */

#include "main.hpp"
#include <stdlib.h>

using namespace jsonrpc;
using namespace std;

struct Command move;

class MyStubServer : public AbstractStubServer
{
public:
	MyStubServer(AbstractServerConnector &connector,Network *n);
	Network * N;
	virtual void notifyServer();
	virtual string moveRobot(int x,int y,int z);
};

MyStubServer::MyStubServer(AbstractServerConnector &connector,Network *n) :
    		AbstractStubServer(connector),N(n)
{
}
void MyStubServer::notifyServer()
{
	cout << "ROBOT#1 got notified" << endl;
}
string MyStubServer::moveRobot(int x,int y, int z)
{
	move.xCent=x;
	move.yCent=y;
	move.zRad=0;
	N->sendSig(&move);
	char buff[2];
//	itoa(N->robotId,buff,1);
	cout<<"po stronie servera wykonano z wartością x = "<<x<<endl;
	cout<<"po stronie servera wykonano z wartością y = "<<y<<endl;
	cout<<"po stronie servera wykonano z wartością z = "<<z<<endl;
	return "Robot executed command";
}




Network::Network(int port,Controller * C): httpserver(port),robotId(C->robotId){
	name="NETWORK";

}


bool Network::work(void *wsk)
{

	MyStubServer s(httpserver,this);
	s.StartListening();
	getchar();
	s.StopListening();
	return 0;
}

