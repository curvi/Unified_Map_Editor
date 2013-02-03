//
//  Player.cpp
//  Proto
//
//  Created by Michael Schwegel on 05.01.13.
//
//

#include "Player.h"
#include "Input.h"


Player::Player() : ASprite()
{
	numberOfFrames = 4;
	sampleTime = 150;
	
	sf::Texture pic = ResourceManager::instance().getTexture("player.png");
	pictures = pic;

	this->setTexture(pictures, true);
	setTextureRect(sf::IntRect(0,0,pic.getSize().x / numberOfFrames,pictures.getSize().y));

}

Player::Player(sf::Texture pic) : ASprite(pic)
{
	Player();
}


void Player::update(float frameTime)
{
	animate(frameTime);
	
}