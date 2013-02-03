//
//  Player.h
//  Proto
//
//  Created by Michael Schwegel on 05.01.13.
//
//

#ifndef Proto_Player_h
#define Proto_Player_h

#include "ASprite.h"


class Player : public ASprite
{
    
public:
    
    std::string getClass(){return "Player";}
    Player();
    Player(sf::Texture pic);
	void update(float frameTime);
    
private:
	
		
};


//Muss sich selbst das sf::Image zuteilen fürs Ändern


#endif
