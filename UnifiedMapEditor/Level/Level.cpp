//
//  Level.cpp
//  Proto
//
//  Created by Michael Schwegel on 06.01.13.
//
//

#include "Level.h"

#include "ResourcePath.hpp"
#include <sstream>

#include <iostream>


// Structure of the XML file:
// - Element "PLAYFIELD" the root Element, which is the
//                       FirstChildElement of the Document
// - - Element "Sprite"   child of the root PLAY Element
// - - - Text            child of the TITLE Element


using namespace ume;

Level::Level()
{


}


void Level::loadLevel(ume::Spritemanager* spritemanager)
{	
	tinyxml2::XMLDocument doc;
	std::string tmp = resourcePath() + "testlevel.xml";
	char* path = (char*)malloc( sizeof( char ) *(tmp.length() +1) );
	std::string::traits_type::copy( path, tmp.c_str(), tmp.length() +1 );
	
	if (! doc.LoadFile(path) == tinyxml2::XML_SUCCESS)
	{
		std::cout<< "Loading error" <<std::endl;
		return;
	}
	
	tinyxml2::XMLElement * info = doc.FirstChildElement( "info" );
	const char* title = info->FirstChildElement( "title" )->FirstChild()->ToText()->Value();
	const char* author = info->FirstChildElement( "author" )->FirstChild()->ToText()->Value();
	const char* version = info->FirstChildElement( "version" )->FirstChild()->ToText()->Value();
	printf("Title: %s\nAuthor: %s\nVersion: %s\n", title,author,version);
	info = 0;
	//^ READ Info
	
	
	tinyxml2::XMLElement * sprites = doc.FirstChildElement("playfield")->FirstChildElement("sprite");
	
	while (sprites)
	{
		//Neues Sprite erstellen
		//TODO: switch type case: "Player", case:"Monster" ...
		ume::Sprite * sprite = new ume::Player();
			
		float posx = getXMLData(sprites, "posx");
		float posy = getXMLData(sprites, "posy");
		sprite->setPosition(posx,posy);
		
		float scalex = getXMLData(sprites, "scalex");
		float scaley = getXMLData(sprites, "scaley");	
		sprite->setScale(scalex, scaley);
		
		float rot = getXMLData(sprites,"rotation");	
		sprite->setRotation(rot);
		
		
		//place sprite on field
		spritemanager->includeSprite(sprite);
		
		sprites = sprites->NextSiblingElement("sprite");
	}
		
	return;
}


void Level::saveLevel(ume::Spritemanager* spritemanager)
{
	std::cout<< "Saving Level" <<std::endl;
	
	tinyxml2::XMLDocument doc;
	
	std::string tmp = resourcePath() + "testlevel.xml";
	char* path = (char*)malloc( sizeof( char ) *(tmp.length() +1) );
	std::string::traits_type::copy( path, tmp.c_str(), tmp.length() +1 );
	
	std::list<Sprite*> playfield = spritemanager->getListOfObjects();
	
	
	tinyxml2::XMLElement * fieldElement = 0;
	if (doc.LoadFile(path) == tinyxml2::XML_SUCCESS)
	{
		if((fieldElement = doc.FirstChildElement("playfield")))
			fieldElement->DeleteChildren();
	}
	else
	{
		fieldElement = doc.NewElement("playfield");
		doc.LinkEndChild(fieldElement);
	}
	
	
	std::list<Sprite*>::iterator it;
	for (it = playfield.begin(); it != playfield.end(); ++it)
	{
		//SPRITE
		tinyxml2::XMLNode *spriteNode = doc.NewElement("sprite");
		
		sf::Vector2f posVector = (**it).getPosition();
		setXMLData(spriteNode, "posx",posVector.x);
		setXMLData(spriteNode, "posy",posVector.y);
		
		sf::Vector2f scaling = (**it).getScale();
		setXMLData(spriteNode, "scalex", scaling.x);
		setXMLData(spriteNode, "scaley", scaling.y);
		
		setXMLData(spriteNode, "rotation", (**it).getRotation());
		
		
		
		fieldElement->InsertEndChild(spriteNode);
		//SPRITE
		
	}//all sprites on the field
	
	doc.SaveFile(path);
	
}


void Level::setXMLData(tinyxml2::XMLNode* spriteNode, const char* name, float number)
{
	char chars [100];
	std::sprintf(chars,"%f",number);
	tinyxml2::XMLDocument* doc = spriteNode->GetDocument();
	 
	tinyxml2::XMLElement* element = doc->NewElement(name);
		
	tinyxml2::XMLText* value = doc->NewText(chars);
	
	element->InsertFirstChild(value);
	spriteNode->InsertEndChild(element);
}



float Level::getXMLData(tinyxml2::XMLElement * el, const char * chars)
{
	const char* value = el->FirstChildElement(chars)//
	->FirstChild()->ToText()->Value();
	std::stringstream stream(value);
	float a;
	stream >> a;
	return a;
}



