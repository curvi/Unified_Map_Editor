/*
 *  Spritemanager.h
 *  Proto
 *
 *  Created by Michael Schwegel on 03.01.13.
 *  Copyright 2013 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef _SPRITEMANAGER_H
#define _SPRITEMANAGER_H 1

#include <list>
#include <string>
#include <sstream>
#include <iostream>

#include <SFML/Graphics.hpp>

#include "Sprites/Sprite.h"
#include "Menu.h"
#include "Input.h"


namespace ume {
	
class Menu;
	
	
class Spritemanager
{
public:
	
	Spritemanager ();

	float	getTime();
	void	update(sf::RenderWindow *);
    void	includeSprite(ume::Sprite* addSprite);
	
	std::string printfps();

	std::list<Sprite*> getListOfObjects() {return listOfObjects;}
	
private:
	
	std::list<Sprite*> listOfObjects;	
		
	sf::Clock clock;
	float	frameTime;
	float	timesave, fpsSave;
	int		counter;
	
};

	
}



#endif





