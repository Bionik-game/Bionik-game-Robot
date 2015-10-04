/*
 * main.hpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Tomek Ferens (fero)
 */

#ifndef MAIN_HPP_
#define MAIN_HPP_

#define NO_MODULES 3	//Number of modules
#define NET_PORT 8383	//Network module (server's) port
						//Module's identifiers

#define MOT0 0
#define MOT1 1
#define NET  2
						//Robot movement instruction identifiers
#define STRAIGHT 10
#define BACK 	 11
#define LEFT	 12
#define RIGHT	 13

#include <boost/signal.hpp>
#include <boost/bind.hpp>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <cstddef>
#include "abstractstubserver.h"
#include "stubclient.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
#include <stdio.h>
#include <jsonrpccpp/client/connectors/httpclient.h>


#include "Module.hpp"
#include "Controller.hpp"
#include "Motor.hpp"
#include "Network.hpp"

#endif /* MAIN_HPP_ */
