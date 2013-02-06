//
//  Spriteman.cpp
//  Protos
//
//  Created by Michael Schwegel on 03.01.13
//
//

//TODO: Input, Draw trennen
//TODO: Transform und Move als eigene Funktion  void move(ASprite);


#include "Spriteman.h"
#include <cmath>



Spriteman::Spriteman ()
{
	timesave = fpsSave = counter = 0;
}
void Spriteman::registerMenu(Menu* menuptr)
{
	menu = menuptr;
}


bool Spriteman::editSprites(sf::RenderWindow &window)
{
	bool usedInput = false;
	//DEBUGGING
	//printf("Framepos: %.f, %.f", framePosition.x, framePosition.y);
	//printf("Sprites %li \n",listOfObjects.size()); //Wie viele Objekte gibts?
	
	if(Input::instance().pressed(sf::Mouse::Left, true))
	{
		firstClick = false;
		rotationOffset = 400;
		if(Input::instance().heldDown(sf::Keyboard::Space))
			selectedSprite = nullptr;
	}
	
  	std::list<ASprite*>::iterator it;
	for (it = listOfObjects.begin(); it != listOfObjects.end(); ++it)
	{
		if(Input::instance().pressed(sf::Mouse::Left, true) &&
		   !Input::instance().heldDown(sf::Keyboard::Space))
		{
			sf::Rect<float> border = ((**it)).getGlobalBounds();
			if( border.contains(Input::instance().getMousePosition().x + framePosition.x ,
								Input::instance().getMousePosition().y + framePosition.y) )
			{
				firstClick = true;	
				xOffset = ((**it)).getPosition().x + ((**it)).getOrigin().x
									- Input::instance().getMousePosition().x;
				yOffset = ((**it)).getPosition().y + ((**it)).getOrigin().y
									- Input::instance().getMousePosition().y;		
				selectedSprite = (*it);
				//selectedSprite->setOrigin(border.width/2, border.height/2);
			}
		}
	}
	
	if(Input::instance().released(sf::Mouse::Left, true) &&
	   !firstClick)
	{
		selectedSprite = nullptr;
	}
	
	if(selectedSprite != 0 &&
	   Input::instance().heldDown(sf::Mouse::Left, true) &&
	   Input::instance().getMousePosition().x < 995)
	{
		if(firstClick)
		{
			selectedSprite->setPosition(Input::instance().getMousePosition().x + xOffset,
										Input::instance().getMousePosition().y + yOffset);
		}
		else
		{
			float distanceX = selectedSprite->getPosition().x - Input::instance().getMousePosition().x;
			float distanceY = selectedSprite->getPosition().y - Input::instance().getMousePosition().y;
			
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
	double ankathete = Input::instance().getMousePosition().x - selectedSprite->getPosition().x;
	
	double angle = acos(ankathete/dist);
	angle *= 180 / 3.141592736;
	
	if(Input::instance().getMousePosition().y < selectedSprite->getPosition().y)
		angle *= -1;
	
	if (rotationOffset != 400){selectedSprite->setRotation(angle + rotationOffset);}
	else {rotationOffset = selectedSprite->getRotation() - angle;}
}





void Spriteman::updateSprites(sf::RenderWindow & window)
{
	sf::Time timeElapsed = clock.restart();
	frameTime = timeElapsed.asMilliseconds();
	
	
	//TODO: View Manager Position fragen
	// wg Sprite wählen
	//Vom View Manager hierher übergeben oda so
	
	framePosition = window.getView().getCenter()
	- sf::Vector2f(window.getSize().x / 2,
				   window.getSize().y / 2);
	
	
	std::list<ASprite*>::iterator it;
	for (it = listOfObjects.begin(); it != listOfObjects.end(); ++it)
	{
		if((**it).checkIfInSight(framePosition))
		{
			//listOfObjects.erase(it);
		}
		(**it).move(frameTime);
		(**it).update(frameTime);
		window.draw((**it));
	}
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










