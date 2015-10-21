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
#define DEBUG

/*
 * Module's identifiers for Controller
 */
#define MOT  0
#define MOT1 1
#define NET  2
#define GPD	 3
						//Robot movement instruction identifiers
#define VERTICAL 10
#define HORIZONTAL 11
#define ROTATE 12

#define GAMEPAD			//If defined - Gamepad Steering enabled (conditional compilation)

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
#include <pthread.h>


#include "Module.hpp"
#include "Controller.hpp"
#include "Motor.hpp"
#include "Network.hpp"
#include "mainjoystick.h"
#include "Gamepad.hpp"



#endif /* MAIN_HPP_ */
