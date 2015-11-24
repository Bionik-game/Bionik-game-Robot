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
void* checkState(void* param){

	Controller * C= (Controller *)param;
	//TODO: sprawdzenie stanu Li-pola i poinformowanie o tym Controllera
	C->modules[NOT];
}

int main(){
	/*
	 * Creation of fundamental objects
	 */
	Gamepad g;
	Controller k(&g);
	/*

	/*
	 * Li-pol's status check thread creation
	 */
	/*
	pthread_t tid2;
	pthread_attr_t attr2;
	pthread_attr_init(&attr2);
	if(pthread_create(&tid2,&attr2,&checkState,&k))
	{cerr<<"error in thread";}
	 */
	/*
	 * Network module starting and awaiting commands from CC
	 */
	 /* Gamepad's thread creation
	 */
// k.modules[NET]->work();

#ifdef GAMEPAD
	pthread_t tid1;
	pthread_attr_t attr1;
	pthread_attr_init(&attr1);
	if(pthread_create(&tid1,&attr1,&(Gamepad::runner),&g))
	{cerr<<"error in thread";}
	if(g.checkRequest()){
		if(pthread_join(tid1,NULL)){
			cerr<<"error joining Gamepad thread";
		}
		else cout<<"GPAD THREAD JOINED"<<endl;
	}
#endif
	cout<<"\nMain thread running\n";
	k.modules[NET]->work();


#ifdef GAMEPAD

	/*
	if(pthread_join(tid2,NULL)){
		cerr<<"error joining thread";
	}
	 */
#endif

	return 0;
}




