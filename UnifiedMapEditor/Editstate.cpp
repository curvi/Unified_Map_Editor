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



void Editstate::update(sf::RenderWindow* window)
{
	distributeInput();
	
}



void Editstate::draw(sf::RenderWindow* win)
{
	//TODO: replace it by updating func
	//Input::instance().poll(win);
	
	viewmanager->update(win);
	spritemanager->update(win);
	
	spriteeditor.update();
	spriteeditor.draw(win); //must be last to draw due to menu
}



//state specific input distribution
void Editstate::distributeInput()
{
	//KEYBOARD
	if(event.type == sf::Event::KeyPressed)
	{
		return;
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		return;
	}
	
	//MOUSE
	else if (event.type == sf::Event::MouseMoved)
	{
		if(viewmanager->moveView(event))
			return;
	}
	else if(event.type == sf::Event::MouseButtonPressed)
	{
		if(viewmanager->zoom(event))
			return;
		else if(viewmanager->setLock(event))
			return;
	}
	else if (event.type == sf::Event::MouseButtonReleased)
	{
		if(viewmanager->setLock(event))
			return;
	}
	else if (event.type == sf::Event::MouseWheelMoved)
	{
		if(viewmanager->zoom(event))
			return;
	}
	
	
	//unused input is saved and stands ready in the singleton
	Input::instance().update(event);
	
}

