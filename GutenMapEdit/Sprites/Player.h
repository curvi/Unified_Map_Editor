//
//  Player.h
//  Proto
//
//  Created by Michael Schwegel on 05.01.13.
//
//

#ifndef Proto_Player_h
#define Proto_Player_h

#include "Sprite.h"

namespace ume {

class Player : public Sprite
{
    
public:
    
    std::string getClass(){return "Player";}
    Player();
    Player(sf::Texture pic);
	void update(float frameTime);
    
private:
	
		
};

}

//Muss sich selbst das sf::Image zuteilen fürs Ändern


#endif
