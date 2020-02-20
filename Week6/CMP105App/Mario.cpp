#include "Mario.h"

Mario::Mario()
{
	gravity = sf::Vector2f (0, 9.8f)* marioScale;

}
Mario::~Mario()
{

}
void Mario::marioSetTexture()
{
	marioTexture.loadFromFile("gfx/Mushroom.png");
	setSize(sf::Vector2f(40, 40));
	setPosition(sf::Vector2f(100, 100));
	setTexture(&marioTexture);
}

void Mario::update(float dt, Input* input, int wX, int wY)
{
	sf::Vector2f pos = velocity * dt + 0.5f * gravity * dt * dt;
	velocity += gravity * dt;
	setPosition(getPosition() + pos);
	if (getPosition().y >= wY-getSize().y)
	{
		setPosition(getPosition().x, wY -getSize().y);
		velocity = sf::Vector2f(0, 0);
		
	}
}
