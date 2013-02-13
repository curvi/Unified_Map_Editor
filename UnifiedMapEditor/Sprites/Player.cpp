//
//  Player.cpp
//  Proto
//
//  Created by Michael Schwegel on 05.01.13.
//
//

#include "Player.h"
#include "Input.h"

using namespace ume;

Player::Player() : Sprite()
{
	numberOfFrames = 4;
	sampleTime = 150;
	
	sf::Texture pic = ResourceManager::instance().getTexture("player.png");
	pictures = pic;

	this->setTexture(pictures, true);
	setTextureRect(sf::IntRect(0,0,pic.getSize().x / numberOfFrames,pictures.getSize().y));

}

Player::Player(std::string path) : Sprite(path)
{
	texturePath = path;
	Player();
}


void Player::update(float frameTime)
{
	animate(frameTime);
	
}