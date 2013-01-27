//
//  Engine.cpp
//  Protos
//
//  Created by Michael Schwegel on 03.01.13
//
//


#include "Engine.h"



void Engine::updateSprites(sf::RenderWindow &window)
{
	sf::Time timeElapsed = clock.restart();
	frameTime = timeElapsed.asMilliseconds();
	
	//std::cout<< "time: " << (frameTime) << std::endl;
	//std::cout<<"Engine: List Size: "<< listOfObjects.size() << std::endl;
	
	
  	std::list<ASprite*>::iterator it;
	for (it = listOfObjects.begin(); it != listOfObjects.end(); ++it)
	{
    	if((**it).checkIfInSight(framePosition))
    	{
			//listOfObjects.erase(it);
    	}
    	(**it).move(frameTime);
		(**it).animate(frameTime);
		window.draw((**it));
	}
	
}


void Engine::updateMenu(sf::RenderWindow &window)
{
	std::list<ASprite*>::iterator it2;
	for (it2 = listOfMenuItems.begin(); it2 != listOfMenuItems.end(); ++it2)
	{
		(**it2).animate(frameTime);
		window.draw((**it2));
	}
}



void Engine::includeSprite(ASprite* figure)
{
	listOfObjects.push_back(figure);
	return;
}

void Engine::loadMenu()
{
	sf::Image img;
	img.create(200, 890, sf::Color(255, 255, 255,200));
	sf::Texture tex;
	tex.loadFromImage(img);
	ASprite* MenuBackground = new ASprite(tex);
	MenuBackground->setPosition(995, 5);
	listOfMenuItems.push_back(MenuBackground);
	
	
	/*
	
	
	sf::Text * fps1 = new sf::Text("fps: --- ", ResourceManager::instance().getFont(), 18);
	fps1->setColor(sf::Color(155,155,155));
	fps1->setPosition(20, 10);
	fps = fps1;
	printf("prepared Text\n");
	*/
	
	return;
}




std::string Engine::printfps()
{
	timesave += frameTime*10e-3;
	
	counter ++;
    if (counter >= 100)
    {
        fpsSave = counter / timesave;
        timesave = 0;
        counter = 0;
    }
    
	std::stringstream stream;
	stream << "fps: " << int(fpsSave);

	std::string erg;
	
	if (fpsSave > 10e-3)
	{
		erg = stream.str();
	}
	
	std::cout<< erg << std::endl;
	
	return erg;
}


float Engine::getTime()
{
	return frameTime;
}










