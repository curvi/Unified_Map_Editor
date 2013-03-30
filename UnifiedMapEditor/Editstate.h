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
	
	Editstate();
	void update(sf::RenderWindow*);
	
private:
	
	Spritemanager* spritemanager;
	Viewmanager* viewmanager;
	Level* level;
	
	Spriteeditor spriteeditor;
	
};
	
	
}//namespace



#endif /* defined(__UnifiedMapEditor__Editstate__) */
