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



class ASprite : public sf::Sprite
{
    
public:
	
	virtual std::string getClass(){return "ASprite";}
	ASprite();
	ASprite(sf::Texture pic);
	
	sf::Vector2i Speed;
	virtual void move(float frameTime);
	
	virtual void animate(float frameTime);
	void loadPicture();
	
	bool checkIfInSight(sf::Vector2<float> framePosition);
	//void killSprite();
    
    
protected:
    
	//bool lifeStatus;
	
	//Animation
	sf::Texture pictures;
	int animationFrame = 0, numberOfFrames;
	float animationTime = 0, sampleTime;
	
	
};




#endif


