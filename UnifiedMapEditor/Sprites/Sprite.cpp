//
//  Sprite.cpp
//  Proto
//
//  Created by Michael Schwegel on 05.01.13.
//
//

#include "Sprite.h"
#include "ResourceManager.h"

using namespace ume;

Sprite::Sprite()
{
/*	sampleTime = 0.5;
	numberOfFrames = 1;
	setPosition(200.f, 200.f);
	
	//setTextureRect(sf::IntRect(0,0,pictures.getSize().x/numberOfFrames,pictures.getSize().y));
	
*/	//Standard Values
	
	animationFrame = numberOfFrames = animationTime = sampleTime = 0;

}



Sprite::Sprite(sf::Texture pic) : sf::Sprite(pic)
{
	//Nur fürs Debugging gleich laden! Dann eigen funkt für be-/entladen
	pictures = pic;

	//Standard Values
	numberOfFrames = 1;
}


void Sprite::move(float frameTime)
{
	float x = Speed.x * frameTime;
	float y = Speed.y * frameTime;
	sf::Transformable::move(x, y);
	
	return;
}



void Sprite::animate(float gameLoopTime)
{
	if ( numberOfFrames == 1) return;
	
	animationTime += gameLoopTime;
	if (animationTime > sampleTime)
	{
		animationTime = 0;
		animationFrame++;
		if (animationFrame >= numberOfFrames){ animationFrame = 0; }
		
		int dx = pictures.getSize().x / numberOfFrames;
		
		setTextureRect(sf::IntRect(animationFrame*dx, 0,
								   dx, pictures.getSize().y ));
	}
}




bool Sprite::checkIfInSight(sf::Vector2<float> framePosition)
{
	if(getPosition().x < framePosition.x - 1000 &&
	   getPosition().x > framePosition.x + 1000)
	{
		return false;
	}
	else
	{
		return true;
	}
}
					   
					   
					   








					   
					   

