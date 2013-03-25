//
//  App.h
//  GutenMapEdit
//
//  Created by Michael Schwegel on 05.02.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//


#ifndef __GutenMapEdit__App__
#define __GutenMapEdit__App__ 1


#include <SFML/Graphics.hpp>

#include "Input.h"
#include "Statemanager.h"

namespace ume {

class App
{

public:
	
	App();
	int run();
	
	
private:
	
	Statemanager statemanager;
	sf::RenderWindow window;
	
};

}

#endif /* defined(__GutenMapEdit__App__) */
