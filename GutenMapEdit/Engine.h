/*
 *  Engine.h
 *  Proto
 *
 *  Created by Michael Schwegel on 03.01.13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _ENGINE_H
#define _ENGINE_H 1

#include <list>
#include <SFML/Graphics.hpp>
#include "Sprites/ASprite.h"
#include "Sprites/Button.h"
#include <string>
#include <sstream>
#include "ResourcePath.hpp"
#include "ResourceManager.h"
#include <iostream>
#include "Input.h"

class Engine
{
public:
 	
	float getTime();
	void updateSprites(sf::RenderWindow &window);
	void updateMenu(sf::RenderWindow &window);
	std::string printfps();
    void includeSprite(ASprite* Figure);
	void loadMenu();

	
private:
	
	std::list<ASprite*> listOfObjects;
    std::list<ASprite*> listOfMenuItems;
	
	sf::Clock clock;
	float frameTime;
	sf::Vector2f framePosition;
	
	int xOffset, yOffset;
	bool firstClick;
 	
	float timesave = 0, fpsSave = 0;
	int counter = 0;
	
	//Menu
	Button AddButton;
	ASprite* selectedSprite;
	
	
	
 	/* Singleton */
public:
    static Engine& instance()
    {
        static Engine _instance;
        return _instance;
    }
private:
    Engine (){};
	/* prohibition for copying a new instance */
	
    Engine ( const Engine& );
    ~Engine () { };
    
    
    
};




#endif





