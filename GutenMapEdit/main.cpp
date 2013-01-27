

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

#include "Sprites/Player.h"//Test
#include "Engine.h"
#include "Level/Level.h"

#include <iostream>

////////////////////////////////////////////////////////////



bool up, down, right, left;
bool hidemenu = false;



int main(int, char const**)
{
    // Create main window Mode 0 = best supported
    // sf::VideoMode(1920, 1080)
    // sf::VideoMode::getFullscreenModes()[0]
	// Fullscreen
    sf::RenderWindow window(sf::VideoMode(1200,900), "Protos", sf::Style::None );
	//window.setFramerateLimit(120);
	//window.setVerticalSyncEnabled(true);
	
	
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath()+"icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	sf::Text fps("fps: --- ", ResourceManager::instance().getFont(), 18);
	fps.setColor(sf::Color(155,155,155));
	fps.setPosition(10, 10);

	
	// Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {return EXIT_FAILURE;}
    //music.play();

	
	Engine::instance().loadMenu();
	
	
	sf::View defaultView = window.getDefaultView();
	sf::View gameView = window.getView();
	window.setView(gameView);
	
	
     
   
   
    // Start the game loop
    while (window.isOpen())
    {
        
		// Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Espace pressed, close Window, Super+Q : exit
            if (event.type == sf::Event::Closed ||
					(event.type == sf::Event::KeyPressed &&
						((event.key.code == sf::Keyboard::Escape)
							|| (sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem)
								&& event.key.code == sf::Keyboard::Q)))
				){ window.close(); }
		
			
			if (event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Right)	{ right = true; }
                if(event.key.code == sf::Keyboard::Left)	{ left	= true; }
                if(event.key.code == sf::Keyboard::Down)	{ down	= true; }
                if(event.key.code == sf::Keyboard::Up)		{ up	= true; }
				
				if(event.key.code == sf::Keyboard::M){hidemenu = !hidemenu;}
            
				
            } //KeyPressed
            
            if (event.type == sf::Event::KeyReleased)
            {
                if(event.key.code == sf::Keyboard::Right)	{right 	= false; }
                if(event.key.code == sf::Keyboard::Left)	{left 	= false; }
                if(event.key.code == sf::Keyboard::Down)	{down 	= false; }
                if(event.key.code == sf::Keyboard::Up)		{up 	= false; }
				
            } //KeyReleased ^
            
			
			
			
		// Process events
        }

		//Event Handling
		
		float time = Engine::instance().getTime();
		if (right)		{gameView.move(0.7*time, 0);}
		else if (!left)	{gameView.move(0,0);}
		if (left)		{gameView.move(-0.7*time, 0);}
		
		if (down) 		{gameView.move(0, 0.7*time);}
		else if (!up)	{gameView.move(0, 0);}
		if(up)			{gameView.move(0, -0.7*time);}
		
		
		
		
		
		//Event Handling ^
		
			

        window.clear();

		
		//GameView
		window.setView(gameView);
		
        Engine::instance().updateSprites(window);
		
		
		
		//DefaultView
		window.setView(defaultView);
		
		if (!hidemenu)
		{
			Engine::instance().updateMenu(window);
			fps.setString(Engine::instance().printfps());
			window.draw(fps);
		}
		
		
		
		
		// Update the window
        window.display();
    }
    
    return EXIT_SUCCESS;
}









// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//