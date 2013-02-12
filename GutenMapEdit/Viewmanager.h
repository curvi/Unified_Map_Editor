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

namespace ume {

class Viewmanager
{
	
public:
	
	void registerWindow(sf::RenderWindow & win);
	bool setGameView(sf::RenderWindow & win);
	sf::Vector2f transformPointToView(sf::Vector2i);
	
	
private:
	
	sf::Vector2u frameSize;
	sf::View gameView;
	sf::Vector2i mouseOffset;
	float zoomFactor;
	
	bool inputLock;
	//sf::Vector2f transformPointToView (sf::Vector2f);
};

}




#endif /* defined(__GutenMapEdit__Viewmanager__) */
