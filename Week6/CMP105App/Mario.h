#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include "Framework/Vector.h"
class Mario:public GameObject
{
public:
	Mario();
	~Mario();
	float marioSpeed = 100.f;
	float marioScale = 200.f;
	float acceleration = 200.f;
	sf::Vector2f  gravity, velocity;
	

	void marioSetTexture();

	void update(float dt, Input* input,int wX,int wY);

	sf::Texture marioTexture;


};
