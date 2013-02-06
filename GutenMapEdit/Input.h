//
//  Input.h
//  GutenMapEdit
//
//  Created by Michael Schwegel on 27.01.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

#ifndef __GutenMapEdit__Input__
#define __GutenMapEdit__Input__ 1


#include <iostream>
#include <set>
#include <SFML/Graphics.hpp>


class Input
{

public:
	
	void poll(sf::RenderWindow & window);
	
	void update(sf::Event event);
	bool heldDown	(int value, bool mouse = false);
	bool pressed	(int value, bool mouse = false);
	bool released	(int value, bool mouse = false);
	void clearUnique ();
	sf::Vector2i getMousePosition(){return mousePosition;}
	
private:
	
	std::set<int> down;
	std::set<int> mouseDown;
	std::set<int> pressedMouse;
	std::set<int> releasedMouse;
	std::set<int> pressedKeyboard;
	std::set<int> releasedKeyboard;
	sf::Vector2i mousePosition;

	
	
	/* Singleton */
public:
	static Input& instance()
	{
		static Input _instance;
		return _instance;
	}
private:
	Input () { };
	/* prohibition for copying a new instance */
	
	Input ( const Input& );
	~Input () { };

};





#endif /* defined(__GutenMapEdit__Input__) */




