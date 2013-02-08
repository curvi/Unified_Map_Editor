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
	zoomFactor = 1;
	inputLock = false;
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
	frameSize = win.getSize();
	
	if(Input::instance().heldDown(sf::Keyboard::Space))
	{
		//Beim Drücken erstmal speichern, dann beim halten ziehen
		if(Input::instance().pressed(sf::Mouse::Left, true))
		{
			mouseOffset = Input::instance().getMousePosition();
			inputLock = true;
		}
		else if(Input::instance().heldDown(sf::Mouse::Left, true) && inputLock)
		{
			sf::Vector2i distance = Input::instance().getMousePosition() - mouseOffset;
			distance *= -1;
			mouseOffset = Input::instance().getMousePosition();
			gameView.move(distance.x, distance.y);
		}
	}
	if(Input::instance().released(sf::Mouse::Left, true) ||
	   Input::instance().released(sf::Keyboard::Space))
	{	inputLock = false; }
	
	if(Input::instance().mouseWheel() != 0)
	{
		float currentZoom = 1 - (Input::instance().mouseWheel() * 0.01 );
		zoomFactor *= currentZoom;
		gameView.zoom(currentZoom); // 2% zoom per Click of Wheel
	}
	if(Input::instance().pressed(sf::Mouse::Middle, true))
	{
		zoomFactor = 1;
		gameView.setSize(win.getDefaultView().getSize());
	}
	
	// std::cout << "zoom: " << (zoomFactor) << std::endl;
	// std::cout << "wheel: " << Input::instance().mouseWheel() << std::endl;
	
	win.setView(gameView);
	
	return inputLock;
}



sf::Vector2f Viewmanager::transformPointToView(sf::Vector2i a)
{
	//Translation
	sf::Vector2f offset = gameView.getCenter() - sf::Vector2f(frameSize.x / 2, frameSize.y / 2) ;
	
	//Scaling-Zooming
	sf::Vector2f zoomCorrection = (sf::Vector2f(a.x, a.y)
								   - sf::Vector2f(frameSize.x / 2, frameSize.y / 2))
									* (zoomFactor - 1);
	
	return sf::Vector2f(a.x, a.y) + offset + zoomCorrection;
}





sf::Vector2f Viewmanager::transformPointToView (sf::Vector2f a)
{
	

	return a;
}











