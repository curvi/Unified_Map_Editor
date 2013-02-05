//
//  Spriteman.cpp
//  Protos
//
//  Created by Michael Schwegel on 03.01.13
//
//


#include "Spriteman.h"

#include "Sprites/Player.h"
#include "Sprites/Button.h"
#include <cmath>


Spriteman::Spriteman ()
{
	timesave = fpsSave = counter = 0;

}

void Spriteman::updateSprites(sf::RenderWindow &window)
{
	sf::Time timeElapsed = clock.restart();
	frameTime = timeElapsed.asMilliseconds();
	
	framePosition = window.getView().getCenter()
					- sf::Vector2f(window.getSize().x / 2,
								   window.getSize().y / 2);
	
	//DEBUGGING
	//printf("Framepos: %.f, %.f", framePosition.x, framePosition.y);
	//printf("Sprites %li \n",listOfObjects.size()); //Wie viele Objekte gibts?
	
	if(Input::instance().pressed(sf::Mouse::Left, true))
	{
		//printf("Clicked without space, first = false\n");
		firstClick = false;
		rotationOffset = 400;
		if(Input::instance().heldDown(sf::Keyboard::Space))
			selectedSprite = nullptr;
	}
	
	
  	std::list<ASprite*>::iterator it;
	for (it = listOfObjects.begin(); it != listOfObjects.end(); ++it)
	{
		//***************
		//Editor Mechanic
		if(Input::instance().pressed(sf::Mouse::Left, true) &&
		   !Input::instance().heldDown(sf::Keyboard::Space))
		{
			sf::Rect<float> border = ((**it)).getGlobalBounds();
			if( border.contains(Input::instance().getMousePosition().x + framePosition.x ,
								Input::instance().getMousePosition().y + framePosition.y) )
			{
				firstClick = true;
				
				xOffset = border.left - Input::instance().getMousePosition().x;
				yOffset = border.top - Input::instance().getMousePosition().y;
				
				selectedSprite = (*it);
				//selectedSprite->setOrigin(border.width/2, border.height/2);
			}
		}
		

		//*************
		//Game Mechanic
		
    	if((**it).checkIfInSight(framePosition))
    	{
			//listOfObjects.erase(it);
    	}
    	(**it).move(frameTime);
		(**it).update(frameTime);
		window.draw((**it));
		
	}//For ALL Sprites ^
	
	
	//***************
	//Editor Mechanic
	if(Input::instance().released(sf::Mouse::Left, true) &&
	   !firstClick)
	{
		//selectedSprite = nullptr;
		printf("set nullptr\n");
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
			//Transform
			float distanceX = selectedSprite->getPosition().x - Input::instance().getMousePosition().x;
			float distanceY = selectedSprite->getPosition().y - Input::instance().getMousePosition().y;
			
			if(ScaleButton.buttonStatus)
			{
				float x = abs(distanceX);
				float y = abs(distanceY);
				
				selectedSprite->setScale(x/100 , y/100);
			}
			
			if(RotateButton.buttonStatus)
			{
				double dist = distanceX*distanceX + distanceY*distanceY;
				dist = sqrt(dist);
				double ankathete = Input::instance().getMousePosition().x - selectedSprite->getPosition().x;
				
				double angle = acos(ankathete/dist);
				angle *= 180 / 3.141592736;
				
				if(Input::instance().getMousePosition().y < selectedSprite->getPosition().y)
					angle *= -1;
				
				if (rotationOffset != 400){selectedSprite->setRotation(angle + rotationOffset);}
				else {rotationOffset = selectedSprite->getRotation() - angle;}
			}
		}
	}
} //UpdateSprites ^





void Spriteman::includeSprite(ASprite* figure)
{
	listOfObjects.push_back(figure);
	return;
}



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










