//
//  App.cpp
//  GutenMapEdit
//
//  Created by Michael Schwegel on 05.02.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

#pragma mark -
// TODO: Hide Menu -> Editor Mode / Game Mode
// TODO: 
#pragma mark -



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
	
	Input::instance().registerObjects(&viewman);
	menu.registerSpriteMan(&spritey);
	spritey.registerObjects(&menu);
	viewman.registerWindow(window);
}


App::~App()
{
	
}



int App::run()
{
	
	level.loadLevel();
	
	// Start the game loop
    while (window.isOpen())
    {
		
		Input::instance().poll(window);
        	
		window.clear();
		
		//Input Queue
		if (!viewman.setGameView(window))
		{	if(!menu.update())
			{	spritey.editSprites(window); }}
		
		
				
		spritey.updateSprites(window);

		
		window.setView(window.getDefaultView());
		menu.draw(window);
		
		
		window.display();

		
		Input::instance().clearUnique();
		
		//sf::sleep(sf::seconds(0.0001f));
	
	}//Loop ^
	
	
	return EXIT_SUCCESS;
}














