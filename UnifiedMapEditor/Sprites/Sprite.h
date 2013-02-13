//
//  Sprite.h
//  Proto - Advanced Sprite Model
//
//  Created by Michael Schwegel on 05.01.13.
//
//

#ifndef Proto_Sprite_h
#define Proto_Sprite_h

#include <SFML/Graphics.hpp>
#include "ResourceManager.h"

namespace ume {


class Sprite : public sf::Sprite
{
    
public:
	
	virtual std::string getClass(){return "Sprite";}
	Sprite();
	Sprite(std::string tex);
	
	sf::Vector2i Speed;
	virtual void move(float frameTime);
	
	virtual void update(float frameTime){animate(frameTime); return;}
	
	bool checkIfInSight(sf::Vector2<float> framePosition);
    
    
protected:
	
    virtual void animate(float frameTime);
	
	//bool lifeStatus;
	
	//Animation
	sf::Texture pictures;
	std::string texturePath;
	int animationFrame, numberOfFrames;
	float animationTime, sampleTime;
	
	
	
};

}


#endif


