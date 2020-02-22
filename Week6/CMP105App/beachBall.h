#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>
#include "Framework/Vector.h"
#include "Framework/GameObject.h"
class beachBall:public GameObject
{
public:
	beachBall();
	~beachBall();


	float speed;
	float acceleration;
	

	void setTextureBall();
	void update(float dt,int mouseX,int mouseY);

	sf::Texture ballTexture;
	sf::Vector2f target,direction,velocity;
	

};

