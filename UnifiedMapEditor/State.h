//
//  State.h
//  UnifiedMapEditor
//
//  Created by Michael Schwegel on 22.03.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

#ifndef __UnifiedMapEditor__State__
#define __UnifiedMapEditor__State__

#include <iostream>
#include <SFML/Graphics.hpp>

namespace ume {

class State
{

public:
	
	virtual void update()=0;
	virtual void draw(sf::RenderWindow*)=0;
	
};

}//namespace

#endif /* defined(__UnifiedMapEditor__State__) */
