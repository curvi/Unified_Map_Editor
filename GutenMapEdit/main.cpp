
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////



// TODO: move View incl. move, hidemenu, mousepos for spacemove



////////////////////////////////////////////////////////////

// #include <SFML/Audio.hpp>
// #include <SFML/Graphics.hpp>



#include "App.h"
#include <assert.h>


//TODO: Hide Menu
//bool hidemenu = false;


int main(int, char const**)
{
	
	App* app = new App();
	assert(NULL != app && "main() Can't create App");
	
	
	int exitCode = app->run();
	
	
	delete app;
	app = NULL;
	
    return exitCode;
}





/*	// Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {return EXIT_FAILURE;}
    //music.play();
*/

	


/*
	sf::View defaultView = window.getDefaultView();
	sf::View gameView = window.getView();
	window.setView(gameView);
*/
	

		#pragma mark View Move
		//View Moving
/*		float time = Engine::instance().getTime();
	
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
 
 
*/		
		/*
	 	std::cout << "GameView:" << std::endl;
		std::cout << "x: " << gameView.getCenter().x << std::endl;
		std::cout << "y: " << gameView.getCenter().y << std::endl;
		*/

		









// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your App bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// App bundle. To get the path to these resource, use the helper
// method resourcePath() from ResourcePath.hpp
//