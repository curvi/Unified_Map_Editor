//
//  Level.cpp
//  Proto
//
//  Created by Michael Schwegel on 06.01.13.
//
//

#include "Level.h"
#include <cstdio>

void Level::loadLevel()
{
    //readFile while file.. x, y = playground [] []
	
	//... if "affe"
	//	ASprite Berg12 = Berg(Position...);
	//	Berg12 = tiles [x][y];
    
	// gleich mit Tiles
	// Affe = monsterArray[x][y];
	
    return;
}


/*
	Hier kommt die Info rein, wo sich der Spieler befindet.
	Demnach wird ausgewählt, welcher Ausschnitt geladen wird, und dann
	werden die Sprites erstellt und in die Engine überreicht.
*/
void Level::placeVisibleObjects(sf::Vector2f pos)
{
	int tilebreite = 20;
	
	if (	int (pos.x / tilebreite) > int (ViewPosition.x / tilebreite) ||
			int (pos.x / tilebreite) < int (ViewPosition.x / tilebreite) )
	{
	
		//checkArrays
		//checkArrays
		//checkArrays
		//checkArrays
		
		// sf::Image kuh = ResourceManager::instance().getImage("Resources/test.png"));
		
		//ASprite Affe.(gib mir mein Bild);
		
		ViewPosition = pos;
	}

    
    
    //button1.SetImage(ResourceManager<sf::Image>::instance().getResource("testbild"));
   
	
	//Engine::instance().includeSprite(&one);
	return;
}
