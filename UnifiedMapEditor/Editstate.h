//
//  Editstate.h
//  UnifiedMapEditor
//
//  Created by Michael Schwegel on 22.03.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

#ifndef __UnifiedMapEditor__Editstate__
#define __UnifiedMapEditor__Editstate__


#include "State.h"
#include "Input.h"

#include "Spritemanager.h"
#include "Viewmanager.h"
#include "Level.h"

#include "Spriteeditor.h"


namespace ume {
	
class Editstate : public State
{
public:
	
	//DESTRUCTOR muss MENU sterben
	Editstate();
	void update(sf::RenderWindow*);
	void draw(sf::RenderWindow*);
	
private:
	
	void distributeInput(sf::Event);

	Spritemanager* spritemanager;
	Viewmanager* viewmanager;
	Level* level;
	
	Spriteeditor spriteeditor;
	
};
	
	
}//namespace



#endif /* defined(__UnifiedMapEditor__Editstate__) */
