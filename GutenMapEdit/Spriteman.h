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
#include "Menu.h"
#include "Input.h"



class Menu;

class Spriteman
{
public:
	
	Spriteman ();
	void registerObjects(Menu* menuptr);
	
	float getTime();
	void updateSprites(sf::RenderWindow &window);
	bool editSprites(sf::RenderWindow &window);

	std::string printfps();
    void includeSprite(ASprite* Figure);
	void loadMenu();

	
private:
	
	std::list<ASprite*> listOfObjects;	
		
	ASprite* selectedSprite;
	sf::RectangleShape selectionRectangle;
	sf::RectangleShape hoverRectangle;
	
	//Geometric Helper Functions
	sf::RectangleShape shapeRealBorder(ASprite * sprite, sf::RectangleShape shape);
	void rotate(float x, float y);
	void scale(float x, float y);
	
	sf::Clock clock;
	float frameTime;
	float timesave, fpsSave;
	int counter;

	int xOffset, yOffset;
	float rotationOffset;
	bool firstClick;

	Menu * menu;
};




#endif





