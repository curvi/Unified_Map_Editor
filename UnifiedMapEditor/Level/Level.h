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
#include "Player.h"
#include "ResourceManager.h"
#include "Spritemanager.h"

#include "Input.h"


namespace ume {

class Level {

public:
	
  	Level();
    void loadLevel(ume::Spritemanager*);
	void saveLevel(ume::Spritemanager*);

private:
	
	float	getXMLData(tinyxml2::XMLElement*, const char*);
	void	setXMLData(tinyxml2::XMLNode*, const char*, float);

};

}
#endif