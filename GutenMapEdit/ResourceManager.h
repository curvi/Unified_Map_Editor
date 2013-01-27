//
//  RessourceManager.cpp
//  Protos
//
//  Created by Michael Schwegel on 01.01.13
//
//

#ifndef _RESOURCEMANAGER_H
#define _RESOURCEMANAGER_H 1

#include <map>
#include <string>
#include <SFML/Graphics.hpp>


class ResourceManager
{
	
public:
	
	sf::Texture getImage (std::string key);
	sf::Font getFont();
	
private:
	
	bool loadTexture(std::string path);
	
	std::map <std::string, sf::Texture> pictureMap;
	sf::Font font;
	
	
 	/* Singleton */
public:
    static ResourceManager& instance()
    {
        static ResourceManager _instance;
        return _instance;
    }
private:
    ResourceManager () { };
    /* prohibition for copying a new instance */
    
    ResourceManager ( const ResourceManager& );
    ~ResourceManager () { };
    
	
};



#endif







