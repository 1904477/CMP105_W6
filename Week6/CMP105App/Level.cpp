#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	mario.marioSetTexture();
	ball.setTextureBall();
	bullet.setTextureBullet();
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	bullet.Handleinput(input);
}

// Update game objects
void Level::update(float dt)
{
	ball.update(dt,input->getMouseX(),input->getMouseY());
	mario.update(dt,input,window->getSize().x, window->getSize().y);
	bullet.update(dt,input);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(mario);
	window->draw(ball);
	window->draw(bullet);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}