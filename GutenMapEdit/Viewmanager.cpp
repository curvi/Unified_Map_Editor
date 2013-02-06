//
//  Viewmanager.cpp
//  GutenMapEdit
//
//  Created by Michael Schwegel on 06.02.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

#include "Viewmanager.h"


void Viewmanager::registerWindow(sf::RenderWindow & win)
{
	gameView = sf::View(win.getDefaultView());
}


	//View Moving
/*		float time = Engine::instance().getTime();
	 
	 if(Input::instance().heldDown(sf::Keyboard::Right)){gameView.move(0.7*time, 0);	}
	 if(Input::instance().heldDown(sf::Keyboard::Left))	{gameView.move(-0.7*time, 0);	}
	 if(Input::instance().heldDown(sf::Keyboard::Up))	{gameView.move(0, -0.7*time);	}
	 if(Input::instance().heldDown(sf::Keyboard::Down))	{gameView.move(0, 0.7*time);	}
 */
	





bool Viewmanager::setGameView(sf::RenderWindow & win)
{
	if(Input::instance().heldDown(sf::Keyboard::Space))
	{
		//Beim Drücken erstmal speichern, dann beim halten ziehen
		if(Input::instance().pressed(sf::Mouse::Left, true))
		{
			mousePos = Input::instance().getMousePosition();
			inputLock = true;
		}
		else if(Input::instance().heldDown(sf::Mouse::Left, true) && inputLock)
		{
			sf::Vector2i distance = Input::instance().getMousePosition() - mousePos;
			distance *= -1;
			mousePos = Input::instance().getMousePosition();
			gameView.move(distance.x, distance.y);
		}
	}
	if(Input::instance().released(sf::Mouse::Left, true) ||
	   Input::instance().released(sf::Keyboard::Space))
		inputLock = false;
	
	win.setView(gameView);
	
	return inputLock;
}








