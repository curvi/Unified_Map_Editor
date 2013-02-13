//
//  Menu.h
//  GutenMapEdit
//
//  Created by Michael Schwegel on 04.02.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

#ifndef __GutenMapEdit__Menu__
#define __GutenMapEdit__Menu__ 1

#include <iostream>
#include <list>

#include <SFML/Graphics.hpp>

#include "Input.h"
#include "Spriteman.h"
#include "Sprites/Player.h"



namespace ume {
	
	
class Spriteman;
	
	

class Menu
{

public:
	
	Menu();
	void registerSpriteMan(ume::Spriteman * spritey);
	
	bool update();
	void draw(sf::RenderWindow &window);

	bool add, rotate, remove, scale;

	

private:

	sf::Font font;
	std::list<sf::Text*> menuList;
	ume::Spriteman* spriteman;
	

};

}
	
#endif /* defined(__GutenMapEdit__Menu__) */
