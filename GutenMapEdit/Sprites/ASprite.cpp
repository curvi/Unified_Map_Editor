//
//  ASprite.cpp
//  Proto
//
//  Created by Michael Schwegel on 05.01.13.
//
//

#include "ASprite.h"
#include "ResourceManager.h"


ASprite::ASprite()
{
	//Nur fürs Debugging gleich laden! Dann eigen funkt für be-/entladen
	this->loadPicture();
	this->setTexture(pictures);
	this->setTextureRect(sf::IntRect(0, 0, 100, 48));
	
	//Standard Values
	sampleTime = 0.5;
	numberOfFrames = 1;
	setPosition(200.f, 200.f);
	
}

ASprite::ASprite(sf::Texture pic)
{
	//Nur fürs Debugging gleich laden! Dann eigen funkt für be-/entladen
	pictures = pic;
	this->setTexture(pictures);
	
	//Standard Values
	sampleTime = 0.5;
	numberOfFrames = 1;
	
}


void ASprite::move(float frameTime)
{
	float x = Speed.x * frameTime;
	float y = Speed.y * frameTime;
	sf::Transformable::move(x, y);
	
	return;
}



void ASprite::animate(float gameLoopTime)
{
	animationTime += gameLoopTime;
	if (animationTime > sampleTime)
	{
		animationTime = 0;
		animationFrame++;
		int dx = pictures.getSize().x / numberOfFrames;
		if (animationFrame > numberOfFrames-1){ animationFrame = 0; }
		setTextureRect(sf::IntRect(0+animationFrame*dx, 0,
									 dx+animationFrame*dx, pictures.getSize().y ));
	}
}




void ASprite::loadPicture()
{
	pictures = ResourceManager::instance().getImage("player.png");
}



bool ASprite::checkIfInSight(sf::Vector2<float> framePosition)
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

