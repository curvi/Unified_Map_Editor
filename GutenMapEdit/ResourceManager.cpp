//
//  RessourceManager.cpp
//  Protos
//
//  Created by Michael Schwegel on 01.01.13
//
//

#include "ResourceManager.h"
#include "ResourcePath.hpp"
#include <iostream>


bool ResourceManager::loadTexture(std::string path)
{
	sf::Texture pic;
	if (!pic.loadFromFile(resourcePath() + path))
	{
  		return false;
	}
	pictureMap[path] = pic;
	printf("res %li",pictureMap.size());
	return true;
}

sf::Texture ResourceManager::getImage(std::string key)
{
	if (pictureMap.find(key) == pictureMap.end())
	{
		if(!loadTexture(key))
		{
			printf("Fehler beim Laden des Bildes\n");
		}
	}
	return pictureMap[key];
}

sf::Font ResourceManager::getFont()
{
    if (!font.loadFromFile(resourcePath() + "sansation.ttf"))
	{
		std::cout<< "couldn't load font."<<std::endl;
		//return sf::Font::getDefaultFont();
	}
	printf("loaded Font\n");
	return font;
}






























