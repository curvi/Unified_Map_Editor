//
//  Level.h
//  Proto
//
//  Created by Michael Schwegel on 06.01.13.
//
//

#ifndef Proto_Level_h
#define Proto_Level_h


#include "Sprite.h"
#include "ResourceManager.h"


//Anfangs immer das Menü laden! und bei Engine ablegen
//dann Level gewählt und dann wirds geladen via virtual funkt. mit
// Abstrakte Klasse: virtual void bla = 0;

namespace ume {

class Level {

public:
  
    void loadLevel();
	void placeVisibleObjects(sf::Vector2f pos);

private:
	
	
    
};

}
#endif