//
//  Viewmanager.h
//  GutenMapEdit
//
//  Created by Michael Schwegel on 06.02.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

#ifndef __GutenMapEdit__Viewmanager__
#define __GutenMapEdit__Viewmanager__

#include <SFML/Graphics.hpp>
#include "Input.h"

namespace ume {

class Viewmanager
{
	
public:
	
	Viewmanager();
	
	bool update (sf::RenderWindow *);
	
	sf::Vector2f transformPointToView (sf::Vector2i);
	
	
private:
	
	bool scroll();
	bool zoom();
	
	sf::View gameView;
	sf::Vector2u frameSize;
	sf::Vector2i mouseOffset;
	float zoomFactor;
	
	bool firstExecution;
	
};

}




#endif /* defined(__GutenMapEdit__Viewmanager__) */
