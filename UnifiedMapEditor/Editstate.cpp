//
//  Editstate.cpp
//  UnifiedMapEditor
//
//  Created by Michael Schwegel on 22.03.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

#include "Editstate.h"


using namespace ume;

Editstate::Editstate()
{
	spritemanager = new Spritemanager;
	viewmanager = new Viewmanager;
	
	//move Level to GameState
	level = new Level;
	level->loadLevel(spritemanager);

	spriteeditor.registerObjects(spritemanager, viewmanager);
}



void Editstate::update(sf::RenderWindow* win)
{
	Input::instance().poll(win);
	
	viewmanager->update(win);
	spritemanager->update(win);
	
	spriteeditor.update();
	spriteeditor.draw(win); //must be last to draw due to menu
}









