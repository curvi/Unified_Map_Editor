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
	//currentstate ausquetschen, dann löschen
}


void Statemanager::update()
{
	currentState->update();
}


void Statemanager::draw(sf::RenderWindow* win)
{
	currentState->draw(win);
}