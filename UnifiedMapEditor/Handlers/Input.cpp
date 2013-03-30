//
//  Input.cpp
//  GutenMapEdit
//
//  Created by Michael Schwegel on 27.01.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

#include "Input.h"

#include <iostream>

using namespace ume;

void Input::poll(sf::RenderWindow * window)
{
	clearUnique();
	
	mouseWheelClicks = 0;
	
	// Process events
	sf::Event event;
	while (window->pollEvent(event))
	{
		// Espace pressed, close Window, Super+Q : exit
		if (event.type == sf::Event::Closed ||
			(event.type == sf::Event::KeyPressed &&
			 event.key.code == sf::Keyboard::Escape)  )
		{ window->close(); }
		
		update(event);
		
		
	}// Process events ^
}



void Input::update(sf::Event event)
{
	if (event.type == sf::Event::MouseMoved)
	{
		mousePosition.x = event.mouseMove.x;
		mousePosition.y = event.mouseMove.y;
		return;
	}
	
	//KEYBOARD
	if(event.type == sf::Event::KeyPressed)
	{
		pressedKeyboard.insert(event.key.code); //single event
		down.insert(event.key.code);
		return;
	}
	else if (event.type == sf::Event::KeyReleased)
	{
		releasedKeyboard.insert(event.key.code);	//single event
		down.erase(event.key.code);
		return;
	}
	
	//MOUSE
	else if(event.type == sf::Event::MouseButtonPressed)
	{
		pressedMouse.insert(event.mouseButton.button);	//single event
		mouseDown.insert(event.mouseButton.button);
		return;
		
	}
	else if (event.type == sf::Event::MouseButtonReleased)
	{
		releasedMouse.insert(event.mouseButton.button);	//single event
		mouseDown.erase(event.mouseButton.button);
		return;
	}
	else if (event.type == sf::Event::MouseWheelMoved)
	{
		mouseWheelClicks = event.mouseWheel.delta; // number of clicks
	}
	
}

bool Input::pressed(int value, bool mouse) //default false
{
	if(!mouse)
	{
		if (pressedKeyboard.find(value) == pressedKeyboard.end())
			return false;
		else return true;
	}
	else if(pressedMouse.find(value) == pressedMouse.end())
		return false;
	else return true;
}


bool Input::released(int value, bool mouse) //default false
{
	if(!mouse)
	{
		if (releasedKeyboard.find(value) == releasedKeyboard.end())
			return false;
		else return true;
	}
	else if(releasedMouse.find(value) == releasedMouse.end())
		return false;
	else return true;
}

void Input::clearUnique ()
{
	pressedKeyboard.clear();
	releasedKeyboard.clear();
	pressedMouse.clear();
	releasedMouse.clear();
}


bool Input::heldDown(int value, bool mouse)
{
	if(!mouse){	
		if(down.find(value) == down.end())
		{
			return false;
		}
		else return true;
	}
	else if(mouseDown.find(value) == mouseDown.end())
		return false;
	else return true;	
}















