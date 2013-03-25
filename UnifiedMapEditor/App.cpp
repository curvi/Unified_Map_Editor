//
//  App.cpp
//  
//



#include "App.h"
#include "Input.h"

using namespace ume;


App::App()
{
	// Create main window Mode 0 = best supported
    // sf::VideoMode(1920, 1080)
    // sf::VideoMode::getFullscreenModes()[0]
	// sf::Style::Fullscreen
	window.create(sf::VideoMode(1200,900), "Guten Map Edit", sf::Style::None );
	
	//window.setFramerateLimit(120);
	//window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
		
	
    // Set the Icon
/*  sf::Image icon;
    if (!icon.loadFromFile(resourcePath()+"icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
*/

}


int App::run()
{
	
	// Start the game loop
    while (window.isOpen())
    {
		window.clear();
		
		statemanager.update();
		statemanager.draw(&window);

		window.display();

		//sf::sleep(sf::seconds(0.0001f));
	}
	
	
	return EXIT_SUCCESS;
}










