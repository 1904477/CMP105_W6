#include "beachBall.h"
beachBall::beachBall()
{
	speed = 100.f;
	acceleration = 50.f;
	

}
beachBall::~beachBall()
{


}
void beachBall::setTextureBall()
{
	ballTexture.loadFromFile("gfx/Beach_Ball.png");
	setSize(sf::Vector2f(100, 100));
	setPosition(300, 300);
	setTexture(&ballTexture);

}
void beachBall::update(float dt,int mouseX,int mouseY)
{
	target = sf::Vector2f(mouseX, mouseY);
	direction = target - getPosition();
	direction = Vector::normalise(direction);
	velocity += (direction * acceleration)*dt;

	setPosition(getPosition() + (velocity * dt));
	if (Vector::magnitude(target - getPosition()) < 10.f)
	{
		setPosition(target);
	}
}