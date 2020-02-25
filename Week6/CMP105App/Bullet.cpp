#include "Bullet.h"
Bullet::Bullet()
{
	mouseStartPos = sf::Vector2f(0.f, 0.f);
	mouseEndPos = sf::Vector2f(0.f, 0.f);
	mousedown = false;
	activation = false;
	bulletScale = 100.f;
	gravity = sf::Vector2f(0,9.8)*bulletScale;
	fired = false;
}


void Bullet::setTextureBullet()
{
	bulletText.loadFromFile("gfx/Beach_Ball.png");
	setSize(sf::Vector2f(100, 100));
	setPosition(sf::Vector2f(100, 500));
	setTexture(&bulletText);
}
void Bullet::Handleinput(Input* input)
{
	if (input->isMouseLDown() && !mousedown)
	{
		mouseStartPos = sf::Vector2f(input->getMouseX(), input->getMouseY());
		std::cout << "Dragging mouse\n";
		mousedown = true;
	}
	if (!input->isMouseLDown()&&mousedown)
	{
		mouseEndPos = sf::Vector2f(input->getMouseX(), input->getMouseY());
		std::cout << "Projectile fired\n";
		mousedown = false;
		activation = true;
	}


}
void Bullet::update(float dt, Input* input)
{
	
	if (activation == true)
	{
		sf::Vector2f trajectory = (mouseStartPos-mouseEndPos);
		float force = (Vector::magnitude(trajectory) * 10);
		trajectory = Vector::normalise(trajectory);
		sf::Vector2f velocity = (trajectory * force);
		setPosition(getPosition() + (velocity * dt));
		fired = true;
	}
	if (fired == true)
	{
		sf::Vector2f pos = velocity * dt + 0.5f * gravity * dt * dt;
		velocity += gravity * dt;
		setPosition(getPosition() + pos);
	}
}