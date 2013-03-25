//
//  Spritemanager.cpp
//  Protos
//
//  Created by Michael Schwegel on 03.01.13
//
//


#include "Spritemanager.h"
#include <cmath>

using namespace ume;

Spritemanager::Spritemanager ()
{
	timesave = fpsSave = counter = 0;
}



void Spritemanager::update(sf::RenderWindow* window)
{	
	sf::Time timeElapsed = clock.restart();
	frameTime = timeElapsed.asMilliseconds();
	
	//TODO: just show those within view
	
	//TODO: remove-flag within sprite to then remove them here
	

	std::list<Sprite*>::iterator it;
	for (it = listOfObjects.begin(); it != listOfObjects.end();)
	{
		/* if ((**it).alive())
		{
		*/ 
		
		(**it).move(frameTime);
		(**it).update(frameTime);
		window->draw((**it));

		++it;
		
		/* } 
		else
		it = listOfObjects.erase(it);
		*/
	}
}



void Spritemanager::includeSprite(Sprite* addSprite)
{
	listOfObjects.push_back(addSprite);
	return;
}




//TODO: outsource fps

std::string Spritemanager::printfps()
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
	std::string erg = "fps: --";
	
	if (fpsSave > 10e-3)
	{
		erg = stream.str();
	}
	
	return erg;
}


float Spritemanager::getTime()
{
	return frameTime;
}









