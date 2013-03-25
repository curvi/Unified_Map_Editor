//
//  Editstate.cpp
//  UnifiedMapEditor
//
//  Created by Michael Schwegel on 22.03.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

#include "Editstate.h"


using namespace ume;

Editstate::Editstate()
{
	spritemanager = new Spritemanager;
	viewmanager = new Viewmanager;
	
	//move Level to GameState
	level = new Level;
	level->loadLevel(spritemanager);

	spriteeditor.registerObjects(spritemanager, viewmanager);
}



void Editstate::update()
{
	if (Input::instance().heldDown(sf::Keyboard::Space) &&
		Input::instance().heldDown(sf::Mouse::Left, true) )
	{
		//Scroll
	}
	else if( Input::instance().heldDown(sf::Mouse::Left, true) ) // && Mousemove?
	{
		//Move
	}
	if (Input::instance().mouseWheel() != 0 )
	{
		//Mouse Wheel
	}
	if (Input::instance().pressed(sf::Mouse::Left, true))
	{
		//Pressed Mouse
	}
	
}


void Editstate::draw(sf::RenderWindow* win)
{
	Input::instance().poll(win);
	
	viewmanager->update(win);
	spritemanager->update(win);
	
	spriteeditor.update();
	spriteeditor.draw(win); //must be last to draw due to menu
}




