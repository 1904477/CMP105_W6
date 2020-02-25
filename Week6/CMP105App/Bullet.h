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

	   int x;
	   int y;
	   bool mousedown;
	   bool activation;

	float speed;
	float bulletScale;
	float acceleration;
	float distancex;
	float distancey;
	float distance;
	float finaldistance;

	void setTextureBullet();
	void update(float dt, Input* input);

	sf::Vector2f  gravity, velocity,direction,pos;
	sf::Texture bulletText;

};

