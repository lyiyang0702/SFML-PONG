#pragma once
//#include <SFML/System.hpp>
//#include <SFML/Graphics.hpp>
#include "Movable.h"
class Ball: public Movable
{
private:
	const float MAX_SPEED = 10.0;
	const float RADIUS = 10.0;
public:
	enum State {
		Bouncing,
		Disappear
	};


	Ball() :Movable(sf::CircleShape(10)){
		circleShape.setOrigin(sf::Vector2f(circleShape.getRadius(), circleShape.getRadius()));
	};
	~Ball() {};
	void Update() override {};
	void Init() override;
	sf::Vector2f GetPos() override;
};

