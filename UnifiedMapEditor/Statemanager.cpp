//
//  Statemanager.cpp
//  UnifiedMapEditor
//
//  Created by Michael Schwegel on 23.03.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

#include "Statemanager.h"
#include "Editstate.h"

using namespace ume;


Statemanager::Statemanager()
{
	//replace this by game/intro-state!
	currentState = new Editstate;
}


void Statemanager::changeState(int)
{
	//move objects from currentstate, then delete
}


void Statemanager::update(sf::RenderWindow* window)
{
	currentState->update(window);
}


void Statemanager::draw(sf::RenderWindow* window)
{
	currentState->draw(window);
}