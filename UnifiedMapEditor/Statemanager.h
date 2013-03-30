//
//  Statemanager.h
//  UnifiedMapEditor
//
//  Created by Michael Schwegel on 23.03.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

#ifndef __UnifiedMapEditor__Statemanager__
#define __UnifiedMapEditor__Statemanager__

#include "State.h"

namespace ume {

class Statemanager : public State
{
public:
	
	Statemanager();
	void changeState(int);
	void update(sf::RenderWindow*);
	void draw(sf::RenderWindow*);
	
private:
	
	State* currentState;
	
};

	
}//namespace

#endif /* defined(__UnifiedMapEditor__Statemanager__) */
