

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ResourcePath.hpp"

#include "Sprites/Player.h"//Test
#include "Engine.h"
#include "Input.h"
#include "Level/Level.h"

#include <iostream>

////////////////////////////////////////////////////////////



bool up, down, right, left;
bool hidemenu = false;
sf::Vector2i mousePos;


int main(int, char const**)
{
    // Create main window Mode 0 = best supported
    // sf::VideoMode(1920, 1080)
    // sf::VideoMode::getFullscreenModes()[0]
	// Fullscreen
    sf::RenderWindow window(sf::VideoMode(1200,900), "Protos", sf::Style::None );
	//window.setFramerateLimit(120);
	//window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	
	
    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath()+"icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

	sf::Font font = ResourceManager::instance().getFont();
	sf::Text fps("", font, 18);
	fps.setColor(sf::Color(155,155,155));
	fps.setPosition(10, 10);

	sf::View defaultView = window.getDefaultView();
	sf::View gameView = window.getView();
	window.setView(gameView);
	
	Engine::instance().loadMenu();
	
	
	// Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {return EXIT_FAILURE;}
    //music.play();
   
   
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
								&& event.key.code == sf::Keyboard::Q) ) ) )
			{ window.close(); }
			
			Input::instance().update(event);

		
        }// Process events ^


		//Event Handling
		float time = Engine::instance().getTime();
		
		if(Input::instance().heldDown(sf::Keyboard::Right))	{gameView.move(0.7*time, 0);	}
		if(Input::instance().heldDown(sf::Keyboard::Left))	{gameView.move(-0.7*time, 0);	}
		if(Input::instance().heldDown(sf::Keyboard::Up))	{gameView.move(0, -0.7*time);	}
		if(Input::instance().heldDown(sf::Keyboard::Down))	{gameView.move(0, 0.7*time);	}
		
		if(!Input::instance().heldDown(sf::Mouse::Left, true))
		{
			mousePos = Input::instance().getMousePosition();
		}
		if(Input::instance().heldDown(sf::Keyboard::Space) &&
		   Input::instance().heldDown(sf::Mouse::Left, true))
		{
			sf::Vector2i distance = Input::instance().getMousePosition() - mousePos;
			distance *= -1;
			mousePos = Input::instance().getMousePosition();
			gameView.move(distance.x, distance.y);
		}
		
		/*
	 	std::cout << "GameView:" << std::endl;
		std::cout << "x: " << gameView.getCenter().x << std::endl;
		std::cout << "y: " << gameView.getCenter().y << std::endl;
		*/
	
		
		
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
		Input::instance().clearUnique();
		
		//sf::sleep(sf::seconds(0.0001f));
		
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