/*
 * BRapp.cpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Tomek Ferens (fero)
 *      Project:
 *      BionikRobotapp - main application running on Robot instance.
 */
#include "main.hpp"

using namespace std;
using namespace boost;

int main(){


	Controller k;
k.modules[NET]->work();
	return 0;
}




