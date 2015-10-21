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
	/*
	 * Creation of fundamental objects
	 */
	Gamepad g;
	Controller k;
	/*
	 * Gamepad's thread creation
	 */
#ifdef GAMEPAD
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	if(pthread_create(&tid,&attr,&(Gamepad::runner),&g))
	{cerr<<"error in thread";}
#endif
	/*
	 * Network module starting and awaiting commands from CC
	 */
	cout<<"\nMain thread running\n";
	k.modules[NET]->work();
#ifdef GAMEPAD
	if(pthread_join(tid,NULL)){
		cerr<<"error joining thread";
	}
#endif

	return 0;
}




