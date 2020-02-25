#include "Bullet.h"
Bullet::Bullet()
{
	
	speed = 200;
	bulletScale = 25.f;
	x = 0;
	y = 0;
	gravity = sf::Vector2f(0,9.8) * bulletScale;
	velocity = sf::Vector2f(10, -10) * bulletScale;
	mousedown = false;
	activation = false;
}


void Bullet::setTextureBullet()
{
	bulletText.loadFromFile("gfx/Beach_Ball.png");
	setSize(sf::Vector2f(100, 100));
	setPosition(sf::Vector2f(100, 500));
	setTexture(&bulletText);
}

void Bullet::update(float dt, Input* input)
{
	
	if (input->isMouseLDown() && mousedown == false)
	{
		x = input->getMouseX();
		y = input->getMouseY();
		mousedown = true;
	}
	if (!input->isMouseLDown() && mousedown == true)
	{
		int x1 = input->getMouseX();
		int y1 = input->getMouseY();
		distancex = (x - x1) * (x - x1);
		distancey = (y - y1) * (y - y1);
		distance = distancex * distancey;
		finaldistance = sqrt(distance);
		std::cout << finaldistance << "\n";
		mousedown = false;
		activation = true;
	}
	if (activation == true)
	{
		
		sf::Vector2f pos = velocity * dt + 0.5f * gravity * dt * dt;
		velocity += gravity * dt;
		setPosition(getPosition() + pos);
	}



}