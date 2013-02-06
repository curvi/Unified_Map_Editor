//
//  App.h
//  GutenMapEdit
//
//  Created by Michael Schwegel on 05.02.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//


#ifndef __GutenMapEdit__App__
#define __GutenMapEdit__App__ 1

#include <iostream>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "Input.h"
#include "Spriteman.h"
#include "Menu.h"
#include "Viewmanager.h"


class App
{

public:
	
	App();
	~App();
	
	int run();
	
	Viewmanager viewman;
	Spriteman spritey;
	Menu menu;

	
private:
	
	sf::RenderWindow window;
	
};




#endif /* defined(__GutenMapEdit__App__) */
