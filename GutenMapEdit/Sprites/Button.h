//
//  Button.h
//  GutenMapEdit
//
//  Created by Michael Schwegel on 29.01.13.
//  Copyright (c) 2013 Michael Schwegel. All rights reserved.
//

#ifndef __GutenMapEdit__Button__
#define __GutenMapEdit__Button__ 1

#include "ASprite.h"


class Button : public ASprite
{
    
public:
    
    std::string getClass(){return "Button";}
    Button();
    Button(std::string path);
    
	void update(float frameTime);
	bool buttonStatus = false;


private:
	
	void animate(float frameTime);

	
};










#endif /* defined(__GutenMapEdit__Button__) */
