//
//  Level.cpp
//  Proto
//
//  Created by Michael Schwegel on 06.01.13.
//
//

#include "Level.h"

#include "ResourcePath.hpp"
#include "tinyxml2.h"

#include <iostream>


using namespace ume;

Level::Level()
{
	tinyxml2::XMLDocument doc;
	std::string a = resourcePath() + "testlevel.xml";
	char* path = (char*)malloc( sizeof( char ) *(a.length() +1) );
	std::string::traits_type::copy( path, a.c_str(), a.length() +1 );
	
	doc.LoadFile( path );
	
	//TODO: Einlesen und in map <ume::Sprite *> einfügen!
	
	std::cout << "Error ID: " << doc.ErrorID()  << std::endl;
}


void Level::loadLevel()
{
    
		
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
    //button1.SetImage(ResourceManager<sf::Image>::instance().getResource("testbild"));
   
	
	//Engine::instance().includeSprite(&one);
	return;
}
