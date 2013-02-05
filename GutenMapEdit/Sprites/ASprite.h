//
//  ASprite.h
//  Proto - Advanced Sprite Model
//
//  Created by Michael Schwegel on 05.01.13.
//
//

#ifndef Proto_ASprite_h
#define Proto_ASprite_h

#include <SFML/Graphics.hpp>
#include "ResourceManager.h"


class ASprite : public sf::Sprite
{
    
public:
	
	virtual std::string getClass(){return "ASprite";}
	ASprite();
	ASprite(sf::Texture pic);
	
	sf::Vector2i Speed;
	virtual void move(float frameTime);
	
	virtual void update(float frameTime){animate(frameTime); return;}
	
	bool checkIfInSight(sf::Vector2<float> framePosition);
    
    
protected:
	
    virtual void animate(float frameTime);
	
	//bool lifeStatus;
	
	//Animation
	sf::Texture pictures;
	int animationFrame, numberOfFrames;
	float animationTime, sampleTime;
	
	
};




#endif


