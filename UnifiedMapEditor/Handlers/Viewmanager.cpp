//
//  Viewmanager.cpp
//  
//

#include "Viewmanager.h"

using namespace ume;


Viewmanager::Viewmanager()
{
	zoomFactor = 1;
	inputLock = false;
	firstExecution = true;
}

/*
void Viewmanager::registerWindow (sf::RenderWindow * win)
{
	gameView = sf::View(win->getDefaultView());
}	
*/

bool Viewmanager::update (sf::RenderWindow * win)
{
	if (firstExecution)
	{
		gameView = sf::View(win->getDefaultView());
		firstExecution = false;
	}
	
	frameSize = win->getSize();
	
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
			distance.x *= -zoomFactor;
			distance.y *= -zoomFactor;
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
		gameView.zoom(currentZoom); // 1% zoom per Click of Wheel
	}
	if(Input::instance().pressed(sf::Mouse::Middle, true))
	{
		zoomFactor = 1;
		gameView.setSize(win->getDefaultView().getSize());
	}
	
	win->setView(gameView);
	
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













