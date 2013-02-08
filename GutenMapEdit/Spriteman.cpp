//
//  Spriteman.cpp
//  Protos
//
//  Created by Michael Schwegel on 03.01.13
//
//


#include "Spriteman.h"
#include <cmath>



Spriteman::Spriteman ()
{
	timesave = fpsSave = counter = 0;
	
	selectionRectangle.setFillColor(sf::Color::Transparent);
	selectionRectangle.setOutlineThickness(1);
	selectionRectangle.setOutlineColor(sf::Color::Red);
	
	hoverRectangle = selectionRectangle;
	hoverRectangle.setOutlineColor(sf::Color::White);
	
	selectedSprite = 0;
}

void Spriteman::registerObjects(Menu* menuptr)
{
	menu = menuptr;
}


bool Spriteman::editSprites(sf::RenderWindow &window)
{
	bool usedInput = false;
	if(Input::instance().heldDown(sf::Keyboard::Space))
		return false;
	
	//DEBUGGING
	//printf("Sprites %li \n",listOfObjects.size()); //Wie viele Objekte gibts?
	
	if(Input::instance().pressed(sf::Mouse::Left, true)) //Presumption
	{
		firstClick = false;
		rotationOffset = 400;
	}
	
  	std::list<ASprite*>::iterator it;
	for (it = listOfObjects.begin(); it != listOfObjects.end(); ++it)
	{
		sf::Rect<float> border = ((**it)).getGlobalBounds();
		if( border.contains(Input::instance().getViewMousePosition().x ,
							Input::instance().getViewMousePosition().y ))
		{
			if(Input::instance().pressed(sf::Mouse::Left, true))
			{
				firstClick = true;
				xOffset = ((**it)).getPosition().x + ((**it)).getOrigin().x
							- Input::instance().getViewMousePosition().x;
				yOffset = ((**it)).getPosition().y + ((**it)).getOrigin().y
							- Input::instance().getViewMousePosition().y;
				selectedSprite = (*it);
			}
			if(!Input::instance().heldDown(sf::Mouse::Left, true) &&
			   (*it) != selectedSprite )
			{
				hoverRectangle = shapeRealBorder((*it), hoverRectangle);
				hoverRectangle.setOutlineColor(sf::Color::White);
			}
			if( (*it) == selectedSprite)
				hoverRectangle.setOutlineColor(sf::Color::Transparent);
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
			selectedSprite->setPosition(Input::instance().getViewMousePosition().x + xOffset,
										Input::instance().getViewMousePosition().y + yOffset);
		}
		else
		{
			float distanceX = selectedSprite->getPosition().x - Input::instance().getViewMousePosition().x;
			float distanceY = selectedSprite->getPosition().y - Input::instance().getViewMousePosition().y;
			
			if(menu->scale)
				scale(distanceX, distanceY);
			else if(menu->rotate)
				rotate(distanceX, distanceY);
		}
	}
	return usedInput;
} //Update ^



void Spriteman::scale(float x, float y)
{
	float distanceY = abs(y);
	float distanceX = abs(x);
	if(!Input::instance().heldDown(sf::Keyboard::LShift) &&
	   !Input::instance().heldDown(sf::Keyboard::LControl))
		distanceY = distanceX;
	selectedSprite->setScale(distanceX/100 , distanceY/100);
}



void Spriteman::rotate(float x, float y)
{
	double dist = x*x + y*y;
	dist = sqrt(dist);
	double ankathete = Input::instance().getViewMousePosition().x - selectedSprite->getPosition().x;
	
	double angle = acos(ankathete/dist);
	angle *= 180 / 3.141592736;
	
	if(Input::instance().getViewMousePosition().y < selectedSprite->getPosition().y)
		angle *= -1;
	
	if (rotationOffset != 400){selectedSprite->setRotation(angle + rotationOffset);}
	else {rotationOffset = selectedSprite->getRotation() - angle;}
}





void Spriteman::updateSprites(sf::RenderWindow & window)
{
	sf::Time timeElapsed = clock.restart();
	frameTime = timeElapsed.asMilliseconds();
	
	
	//TODO: View Manager Position fragen
	//TODO: View Manager Zoom einbauen, wie oben
	// wg Sprite wählen
	//Vom View Manager hierher übergeben oda so
	
	
	std::list<ASprite*>::iterator it;
	for (it = listOfObjects.begin(); it != listOfObjects.end(); ++it)
	{
		//if((**it).checkIfInSight(viewman))
		{
			//listOfObjects.erase(it);
		}
		(**it).move(frameTime);
		(**it).update(frameTime);
		window.draw((**it));
	}
	
	if(selectedSprite != 0)
	{
		selectionRectangle = shapeRealBorder(selectedSprite, selectionRectangle);
		window.draw(selectionRectangle);
	}
	window.draw(hoverRectangle);
}



sf::RectangleShape Spriteman::shapeRealBorder(ASprite * sprite, sf::RectangleShape shape)
{
	shape.setPosition(sprite->getPosition().x, sprite->getPosition().y);
	sf::Rect<float> border = sprite->getLocalBounds();
	shape.setSize(sf::Vector2f(border.width, border.height));
	shape.setScale(sprite->getScale());
	shape.setRotation(sprite->getRotation());
	return shape;
}



void Spriteman::includeSprite(ASprite* figure)
{
	listOfObjects.push_back(figure);
	return;
}





//TODO: Auslagern von FPS

std::string Spriteman::printfps()
{
	timesave += frameTime*10e-3;
	
	counter ++;
    if (counter >= 100)
    {
        fpsSave = counter / timesave;
        timesave = 0;
        counter = 0;
    }
    
	std::stringstream stream;
	stream << "fps: " << int(fpsSave);
	std::string erg = "fps: --";
	
	if (fpsSave > 10e-3)
	{
		erg = stream.str();
	}
	
	return erg;
}


float Spriteman::getTime()
{
	return frameTime;
}









