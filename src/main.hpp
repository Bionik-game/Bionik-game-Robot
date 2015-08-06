/*
 * main.hpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Tomek Ferens (fero)
 */

#ifndef MAIN_HPP_
#define MAIN_HPP_

#define NO_MODULES 3	//Number of modules

						//Module's identifiers
#define NET 2
#define MOT0 0
#define MOT1 1
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


#include "Module.hpp"
#include "Controller.hpp"
#include "Motor.hpp"
#include "Network.hpp"

#endif /* MAIN_HPP_ */
