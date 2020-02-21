#include "Mario.h"

Mario::Mario()
{
	//declare gravity value
	gravity = sf::Vector2f (0, 9.8f)* marioScale;
	jump = sf::Vector2f (0, -5.0f) * marioScale;
	isJumping = false;
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
	//falling mario
	sf::Vector2f pos = velocity * dt + 0.5f * gravity * dt * dt;
	velocity += gravity * dt;
	setPosition(getPosition() + pos);
	if (getPosition().y >= wY-getSize().y)
	{
		setPosition(getPosition().x, wY -getSize().y);
		velocity = sf::Vector2f(0, 0);
		isJumping = false;
	}

	if (input->isKeyDown(sf::Keyboard::Space))
	{
		if (!isJumping)
		{
			velocity = jump;
			isJumping = true;

		}
	}

	if (input->isMouseLDown())
	{
		setPosition(input->getMouseX(), input->getMouseY());

	}
	
}
