//
//  Spriteeditor.cpp
//  UnifiedMapSpriteeditor
//
//  Created by Michael Schwegel on 25.03.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

#include "Spriteeditor.h"

#include <cmath>


using namespace ume;


Spriteeditor::Spriteeditor()
{
	//menu is created here
	selectionRectangle.setFillColor(sf::Color::Transparent);
	selectionRectangle.setOutlineThickness(1);
	selectionRectangle.setOutlineColor(sf::Color::Red);
	hoverRectangle = selectionRectangle;
	hoverRectangle.setOutlineColor(sf::Color::White);
	selectedSprite = 0;
}




void Spriteeditor::draw(sf::RenderWindow * window)
{
	if(selectedSprite != 0)
	{
		selectionRectangle = shapeRealBorder(selectedSprite, selectionRectangle);
		window->draw(selectionRectangle);
	}
	window->draw(hoverRectangle);
	
	
	window->setView(window->getDefaultView());
	menu.draw(window);
}




void Spriteeditor::update()
{
	//TODO: Delete this due to Input splitting
	if(Input::instance().heldDown(sf::Keyboard::Space))
		return;
	if(Input::instance().pressed(sf::Mouse::Left, true)) //Presumption
	{
		firstClick = false;
		rotationOffset = 400;
	}
	
	
	std::list<Sprite*> spriteList = spritemanager->getListOfObjects();
	
	
  	std::list<Sprite*>::iterator it;
	for (it = spriteList.begin(); it != spriteList.end(); ++it)
	{
		sf::Rect<float> border = ((**it)).getGlobalBounds();
		
		
		// EDIT HERE
		if( border.contains(getViewMousePosition()) )
		{
			if(Input::instance().pressed(sf::Mouse::Left, true))
			{
				if(menu.del) //TEST USE ONLY!
				{	it = spriteList.erase(it--);
					menu.del = false;
					return;}
				
				firstClick = true;
				xOffset = ((**it)).getPosition().x + ((**it)).getOrigin().x
							- getViewMousePosition().x;
				yOffset = ((**it)).getPosition().y + ((**it)).getOrigin().y
							- getViewMousePosition().y;
				selectedSprite = (*it);
				
				if( (*it)->getPosition().x == hoverRectangle.getPosition().x)
					hoverRectangle.setOutlineColor(sf::Color::Transparent);
			}
			
			if( ! Input::instance().heldDown(sf::Mouse::Left, true) &&
			   (*it) != selectedSprite )
			{
				hoverRectangle = shapeRealBorder((*it), hoverRectangle);
				hoverRectangle.setOutlineColor(sf::Color::White);
			}
		}
	}
	
	if(Input::instance().released(sf::Mouse::Left, true) &&
	   !firstClick)
	{
		selectedSprite = nullptr;
		hoverRectangle.setOutlineColor(sf::Color::Transparent);
	}
	
	if(selectedSprite != 0 &&
	   Input::instance().heldDown(sf::Mouse::Left, true) &&
	   Input::instance().getMousePosition().x < 995)
	{
		if(firstClick)
		{
			selectedSprite->setPosition(getViewMousePosition().x + xOffset,
										getViewMousePosition().y + yOffset);
		}
		else
		{
			float distanceX = selectedSprite->getPosition().x - getViewMousePosition().x;
			float distanceY = selectedSprite->getPosition().y - getViewMousePosition().y;
			
			if(menu.scale)
				scale(distanceX, distanceY);
			else if(menu.rotate)
				rotate(distanceX, distanceY);
		}
	}
	return;
}




void Spriteeditor::scale(float x, float y)
{
	float distanceY = abs(y);
	float distanceX = abs(x);
	if(!Input::instance().heldDown(sf::Keyboard::LShift) &&
	   !Input::instance().heldDown(sf::Keyboard::LControl))
		distanceY = distanceX;
	selectedSprite->setScale(distanceX/100 , distanceY/100);
}


void Spriteeditor::rotate(float x, float y)
{
	double dist = x*x + y*y;
	dist = sqrt(dist);
	double ankathete = getViewMousePosition().x - selectedSprite->getPosition().x;
	
	double angle = acos(ankathete/dist);
	angle *= 180 / 3.141592736;
	
	if(getViewMousePosition().y < selectedSprite->getPosition().y)
		angle *= -1;
	
	if (rotationOffset != 400){selectedSprite->setRotation(angle + rotationOffset);}
	else {rotationOffset = selectedSprite->getRotation() - angle;}
}


sf::RectangleShape Spriteeditor::shapeRealBorder(Sprite * sprite, sf::RectangleShape shape)
{
	shape.setPosition(sprite->getPosition().x, sprite->getPosition().y);
	sf::Rect<float> border = sprite->getLocalBounds();
	shape.setSize(sf::Vector2f(border.width, border.height));
	shape.setScale(sprite->getScale());
	shape.setRotation(sprite->getRotation());
	return shape;
}

sf::Vector2f Spriteeditor::getViewMousePosition()
{
	return viewmanager->transformPointToView(Input::instance().getMousePosition());
}








