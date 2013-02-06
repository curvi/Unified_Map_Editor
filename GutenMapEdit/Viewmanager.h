//
//  Viewmanager.h
//  GutenMapEdit
//
//  Created by Michael Schwegel on 06.02.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

#ifndef __GutenMapEdit__Viewmanager__
#define __GutenMapEdit__Viewmanager__

#include <iostream>

#include <SFML/Graphics.hpp>

#include "Input.h"


class Viewmanager
{
	
public:
	
	void registerWindow(sf::RenderWindow & win);
	bool setGameView(sf::RenderWindow & win);
	
private:
	
	sf::View gameView;
	sf::Vector2i mousePos;
	
	bool inputLock;
};






#endif /* defined(__GutenMapEdit__Viewmanager__) */
