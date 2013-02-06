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

#include "Input.h"
#include "Sprites/ASprite.h"
#include "Menu.h"

class Menu;

class Spriteman
{
public:
	
	Spriteman ();
	void registerMenu(Menu* menuptr);
	
	float getTime();
	void updateSprites(sf::RenderWindow &window);
	bool editSprites(sf::RenderWindow &window);

	std::string printfps();
    void includeSprite(ASprite* Figure);
	void loadMenu();

	
private:
	
	std::list<ASprite*> listOfObjects;	
	
	void rotate(float x, float y);
	void scale(float x, float y);
	ASprite* selectedSprite;
	sf::RectangleShape selectionRectangle;
	sf::RectangleShape hoverRectangle;
	
	sf::Clock clock;
	float frameTime;
	float timesave, fpsSave;
	int counter;
	sf::Vector2f framePosition;
	int xOffset, yOffset;
	float rotationOffset;
	bool firstClick;

	
	
	Menu * menu;

	
 
};




#endif





