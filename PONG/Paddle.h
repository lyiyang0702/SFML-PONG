#pragma once
#include "Movable.h"
class Paddle : public Movable
{
private:
	const float START_SPEED = 10000.0;
	const float HEIGHT = 80.0;
	const float WIDTH = 10.0;
	const float MAX_SPEED = 10.0;

public:
	bool isAI = false;
	
	Paddle(){
		/*printf("%f,%f\n", WIDTH, HEIGHT);*/
		this->rectShape = sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT));
		this->rectShape.setOrigin(sf::Vector2f(WIDTH / 2, HEIGHT / 2));
		this->speed = START_SPEED;
	};
	~Paddle() {};

	void Update() override;
	sf::Vector2f GetPos() override;
	void BoundMovable(float resoultionX, float resolutionY) override;
};

