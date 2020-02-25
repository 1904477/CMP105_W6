#pragma once
#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include <string.h>
#include <iostream>
#include "Framework/Vector.h"
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class Bullet:public GameObject
{
public:
	Bullet();

	
	   bool mousedown;
	   bool activation;
	   bool fired;
	float speed;
	float bulletScale;

	float finaldistance;

	void setTextureBullet();
	void update(float dt, Input* input);
	void Handleinput(Input* input);
	
	sf::Vector2f  mouseStartPos,mouseEndPos,gravity, velocity,direction;
	sf::Texture bulletText;

};

