//
//  Button.cpp
//  GutenMapEdit
//
//  Created by Michael Schwegel on 29.01.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

#include "Button.h"
#include "Input.h"

Button::Button()
{
	numberOfFrames = 2;
}

 
Button::Button(std::string path)
{
	numberOfFrames = 2;
	sf::Texture pic = ResourceManager::instance().getTexture(path);
	pictures = pic;
	this->setTexture(pictures);
	setTextureRect(sf::IntRect(0,0,pic.getSize().x / numberOfFrames, pic.getSize().y));
}



void Button::animate(float frameTime)
{
	if(buttonStatus)
	{
		animationFrame = 1;
	}
	else animationFrame = 0;
	
	int dx = pictures.getSize().x/numberOfFrames;
	setTextureRect(sf::IntRect(animationFrame*dx, 0,
							   dx, pictures.getSize().y ));
}



void Button::update(float frameTime)
{
	animate(frameTime);
	
}








