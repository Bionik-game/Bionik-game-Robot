/*
 * Motor.hpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Tomek Ferens (fero)
 */

#ifndef Motor_HPP_
#define Motor_HPP_



class Motor : public Module{
public:
	Motor(int nr);
	bool work(void*);
	~Motor(){};
};


#endif /* Motor_HPP_ */
