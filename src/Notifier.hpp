/*
 * Notifier.hpp
 *
 *  Created on: Aug 3, 2015
 *      Author: Tomek Ferens (fero)
 */

#ifndef Notifier_HPP_
#define Notifier_HPP_



class Notifier : public Module{
public:
	char LEDS;
	Notifier();
	bool work(void*);
	~Notifier(){};
};


#endif /* Notifier_HPP_ */
