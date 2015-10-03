/*
 * Network.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Tomek Ferens (fero)
 */

#include "main.hpp"


using namespace jsonrpc;
using namespace std;

struct Command move;

class MyStubServer : public AbstractStubServer
{
public:
	MyStubServer(AbstractServerConnector &connector,Network *n);
	Network * N;
	virtual void notifyServer();
	virtual string moveRobot(int x,int y);
	virtual string rotateRobot(int z);
};

MyStubServer::MyStubServer(AbstractServerConnector &connector,Network *n) :
    		AbstractStubServer(connector),N(n)
{
}
void MyStubServer::notifyServer()
{
	cout << "ROBOT#1 got notified" << endl;
}
string MyStubServer::moveRobot(int x,int y)
{



	move.xCent=x;
	move.yCent=y;
	move.zRad=0;
	N->sendSig(&move);
	cout<<"po stronie servera wykonano z wartością x = "<<x<<endl;
	cout<<"po stronie servera wykonano z wartością y = "<<y<<endl;
	return "Executed";
}
string MyStubServer::rotateRobot(int z)
{

	move.xCent=0;
	move.yCent=0;
	move.zRad=z;
	N->sendSig(&move);
	cout<<"po stronie servera wykonano z wartością z = "<<z<<endl;
	return "Executed";
}



Network::Network(int port): httpserver(port){
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

