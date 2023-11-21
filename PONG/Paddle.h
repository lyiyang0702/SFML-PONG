#pragma once
#include "Movable.h"
class Paddle : public Movable
{
private:
	const float HEIGHT = 50.0;
	const float WIDTH = 10.0;
	const float MAX_SPEED = 10.0;

public:
	bool isAI = false;
	Paddle() :Movable(sf::RectangleShape(sf::Vector2f(10,50))){
		rectShape.setOrigin(sf::Vector2f(rectShape.getSize().x / 2, rectShape.getSize().y / 2));
	};
	~Paddle() {};

	void Update() override;
	sf::Vector2f GetPos() override;
};

