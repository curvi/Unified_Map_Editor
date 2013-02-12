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

#include "Sprites/Sprite.h"
#include "Menu.h"
#include "Input.h"

class ume::Menu;


namespace ume {

	
class Spriteman
{
public:
	
	Spriteman ();
	void registerObjects(ume::Menu* menuptr);
	
	float getTime();
	void updateSprites(sf::RenderWindow &window);
	bool editSprites(sf::RenderWindow &window);

	std::string printfps();
    void includeSprite(ume::Sprite* Figure);
	void loadMenu();

	
private:
	
	std::list<Sprite*> listOfObjects;	
		
	Sprite* selectedSprite;
	sf::RectangleShape selectionRectangle;
	sf::RectangleShape hoverRectangle;
	
	//Geometric Helper Functions
	sf::RectangleShape shapeRealBorder(Sprite * sprite, sf::RectangleShape shape);
	void rotate(float x, float y);
	void scale(float x, float y);
	
	sf::Clock clock;
	float frameTime;
	float timesave, fpsSave;
	int counter;

	int xOffset, yOffset;
	float rotationOffset;
	bool firstClick;

	ume::Menu * menu;
};

	
}



#endif





