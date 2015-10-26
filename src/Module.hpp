/*
 * Module.hpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Tomek Ferens (fero)
 */

#ifndef MODULE_HPP_
#define MODULE_HPP_
#include "main.hpp"
class Module{
public:
	std::string name;
	virtual bool work(void*wsk=0)=0;
	virtual ~Module(){};
	boost::signal<bool(int nr,void* wsk)> SigW;
	bool on;
	/*
	 * Prints debug message in format : [type_of_message][module_name]: message
	 */
	 void dbg_msg(std::string msg,int type=0){
		if(!type)
			std::cout<<"[DEBUG]"<<"["<<name<<"]: "<<msg<<std::endl;
		else if(type==ERR){
			std::cout<<"[ERROR]"<<"["<<name<<"]: "<<msg<<std::endl;
		}
		else if(type==INF){
			std::cout<<"[INFO]"<<"["<<name<<"]: "<<msg<<std::endl;
		}
	}
};



#endif /* MODULE_HPP_ */
