#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
#include <iostream>
class Mario:public GameObject
{
public:
	Mario();
	~Mario();
	float marioSpeed = 100.f;
	float marioScale = 200.f;
	float acceleration = 200.f;

	bool isJumping;


	sf::Vector2f  gravity, velocity,jump;
	

	void marioSetTexture();

	void update(float dt, Input* input,int wX,int wY);

	sf::Texture marioTexture;


};
