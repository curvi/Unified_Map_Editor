//
//  Editor.h
//  UnifiedMapEditor
//
//  Created by Michael Schwegel on 25.03.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

#ifndef __UnifiedMapEditor__Spriteeditor__
#define __UnifiedMapEditor__Spriteeditor__

#include <iostream>
#include <list>

#include <SFML/Graphics.hpp>

#include "Input.h"
#include "Menu.h"
#include "Sprite.h"

#include "Spritemanager.h"
#include "Viewmanager.h"


namespace ume {
	
class Spriteeditor
{
	
public:

	Spriteeditor();	
	void update();
	void draw(sf::RenderWindow* );
	
	void registerObjects(Spritemanager* s, Viewmanager* v){spritemanager = s; viewmanager = v;}
	
private:
	
	Spritemanager* spritemanager;
	Viewmanager* viewmanager;
	
	Menu menu;
	
	Sprite* selectedSprite;
	sf::RectangleShape selectionRectangle;
	sf::RectangleShape hoverRectangle;
	
	//geometric helper functions
	sf::Vector2f getViewMousePosition();
	sf::RectangleShape shapeRealBorder(Sprite * sprite, sf::RectangleShape shape);
	void rotate(float x, float y);
	void scale(float x, float y);
	
	int xOffset, yOffset;
	float rotationOffset;
	bool firstClick;
	
	
};

}


#endif
