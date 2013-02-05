/*
 *  Spriteman.h
 *  Proto
 *
 *  Created by Michael Schwegel on 03.01.13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _Spriteman_H
#define _Spriteman_H 1

#include <list>
#include <string>
#include <sstream>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Sprites/ASprite.h"
#include "Sprites/Button.h"
#include "ResourceManager.h"
#include "Input.h"
#include "ResourcePath.hpp"


class Spriteman
{
public:
	
	Spriteman ();
	float getTime();
	void updateSprites(sf::RenderWindow &window);
	void updateMenu(sf::RenderWindow &window);
	std::string printfps();
    void includeSprite(ASprite* Figure);
	void loadMenu();

	
private:
	
	std::list<ASprite*> listOfObjects;
    
	sf::Clock clock;
	float frameTime;
	sf::Vector2f framePosition;
	
	int xOffset, yOffset;
	float rotationOffset;
	bool firstClick;

	float timesave, fpsSave;
	int counter;
	
	//Menu
	Button AddButton, RotateButton, ScaleButton;
	ASprite* selectedSprite;
	
 
};




#endif





