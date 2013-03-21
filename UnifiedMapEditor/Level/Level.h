//
//  Level.h
//  Proto
//
//  Created by Michael Schwegel on 06.01.13.
//
//

#ifndef Level_h
#define Level_h

#include "tinyxml2.h"

#include "Sprite.h"
#include "ResourceManager.h"
#include "Spriteman.h"

#include "Input.h"

//Anfangs immer das Menü laden! und bei Engine ablegen
//dann Level gewählt und dann wirds geladen via virtual funkt. mit
// Abstrakte Klasse: virtual void bla = 0;

namespace ume {

class Level {

public:
	
  	Level();
    void loadLevel(ume::Spriteman*);
	void saveLevel();
	void act(/*sf::Vector2f pos*/);

private:
	
	float getXMLData(tinyxml2::XMLElement*, const char*);
	void setXMLData(tinyxml2::XMLNode*, const char*, float);
	
	ume::Spriteman* spriteman;
    
};

}
#endif