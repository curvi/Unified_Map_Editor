//
//  Menu.cpp
//  GutenMapEdit
//
//  Created by Michael Schwegel on 04.02.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

// TODO: introduce fps to menu


#include "Menu.h"


/*
 
 sf::Font font = ResourceManager::instance().getFont();
 sf::Text fps("", font, 18);
 fps.setColor(sf::Color(155,155,155));
 fps.setPosition(10, 10);
 
 
 */





Menu::Menu()
{
	/*
	sf::Image img;
	img.create(200, 890, sf::Color(150,150,150));
	img.createMaskFromColor(sf::Color(200,200,200),100);
	sf::Texture * tex = new sf::Texture;
	tex->loadFromImage(img);
	ASprite* MenuBackground = new ASprite(*tex);
	MenuBackground->setPosition(995, 5);
	menuList.push_back(MenuBackground);
	*/
		
	font = ResourceManager::instance().getFont();
	
	sf::Text * text = new sf::Text("Add", font, 25);
	menuList.push_back(text);
	
	//delete
	
	sf::Text * text1 = new sf::Text("Rotate", font, 25);
	menuList.push_back(text1);
	
	sf::Text * text2 = new sf::Text("Scale", font, 25);
	menuList.push_back(text2);
	
	
	sf::Text * play = new sf::Text("Player", font, 25);
	menuList.push_back(play);
	
	
	int pos = 10;
	std::list<sf::Text*>::iterator it;
	for (it = menuList.begin(); it != menuList.end(); ++it)
	{
		(*it)->setPosition(1050, pos);
		(*it)->setColor(sf::Color::White);
		pos += 35;
	}
}



void Menu::registerSpriteMan(Spriteman * spritey)
{
	spriteman = spritey;
}





void Menu::update(sf::RenderWindow &window)
{
	/*
	 // TODO: Deactivate Buttons
	 
	//Deactivate Buttons
	if((Input::instance().pressed(sf::Mouse::Left, true))
	   &&(Input::instance().getMousePosition().x < 995) )
	{
		add = false;
	}
	if(Input::instance().pressed(sf::Keyboard::Return))
	{
		scale = false;
		rotate = false;
	}
	*/
	
	std::list<sf::Text*>::iterator it;
	for (it = menuList.begin(); it != menuList.end(); ++it)
	{
		window.draw((**it));
		
		if(Input::instance().pressed(sf::Mouse::Left, true))
		{
			sf::Rect<float> border = ((**it)).getGlobalBounds();
			if( border.contains(Input::instance().getMousePosition().x ,
								Input::instance().getMousePosition().y ) )
			{
				std::string itemName = ((**it)).getString();
				((**it)).setColor(sf::Color::Green);
				std::cout << "Clicked Menu Item: " << itemName <<std::endl;
				
				if(itemName == "Add")
					add = true;
				else if (itemName == "Scale")
					scale = true;
				else if (itemName == "Rotate")
					rotate = true;
			
				
				((**it)).setColor(sf::Color::White);
				if(add && itemName == "Player")
				{
					std::cout <<"Player"<<std::endl;
					ASprite * copy = new Player();
					copy->setPosition(450, 300);
					spriteman->includeSprite(copy);
				}
				
			}
		}
	}
	
	return;
	
}//Menu




