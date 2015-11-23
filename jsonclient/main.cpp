/*
 * main.cpp
 *
 *  Created on: Oct 1, 2015
 *      Author: fero
 */

#include <iostream>

#include "stubclient.h"
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdlib.h>
using namespace jsonrpc;
using namespace std;
/*
int main(int argc, char **argv)
{
    HttpClient httpclient("localhost:30000");
    StubClient c(httpclient);
    try
    {
        cout << c.moveRobot(atoi(argv[1]),atoi(argv[2]),atoi(argv[3])) << endl;
        c.notifyServer();
    }
    catch (JsonRpcException e)
    {
        cerr << e.what() << endl;
    }
}


*/
