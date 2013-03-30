//
//  Viewmanager.cpp
//  
//

#include "Viewmanager.h"

using namespace ume;


Viewmanager::Viewmanager()
{
	zoomFactor = 1;
	firstExecution = true;
}


bool Viewmanager::update (sf::RenderWindow * window)
{
	if (firstExecution)
	{
		gameView = sf::View(window->getDefaultView());
		firstExecution = false;
	}
	
	frameSize = window->getSize();
	bool tookInput = false;
	
	if (scroll())
		tookInput = true;
	
	else if(zoom())
		tookInput = true;
		
	window->setView(gameView);
	
	return tookInput;
}




bool Viewmanager::scroll()
{
	if(Input::instance().heldDown(sf::Keyboard::Space))
	{
		//first save offset, then calculate distance
		if(Input::instance().pressed(sf::Mouse::Left, true))
		{
			mouseOffset = Input::instance().getMousePosition();
			return true;
		}
		else if( Input::instance().heldDown(sf::Mouse::Left, true) )
		{
			sf::Vector2i distance = Input::instance().getMousePosition() - mouseOffset;
			distance.x *= -zoomFactor;
			distance.y *= -zoomFactor;
			mouseOffset = Input::instance().getMousePosition();
			gameView.move(distance.x, distance.y);
			return true;
		}
	}
	return false;
}



bool Viewmanager::zoom()
{
	if(Input::instance().mouseWheel() != 0)
	{
		float currentZoom = 1 - (Input::instance().mouseWheel() * 0.01 );
		zoomFactor *= currentZoom;
		gameView.zoom(currentZoom); // 1% zoom per click of wheel
		return true;
	}
	if(Input::instance().pressed(sf::Mouse::Middle, true))
	{
		zoomFactor = 1;
		gameView.setSize(frameSize.x, frameSize.y);
		return true;
	}
	return false;
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













