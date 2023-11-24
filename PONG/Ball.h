#pragma once
//#include <SFML/System.hpp>
//#include <SFML/Graphics.hpp>
#include "Movable.h"
class Ball: public Movable
{
private:
	const float START_SPEED = 500.0;
	//const float MAX_SPEED = 10.0;
	const float RADIUS = 10.0;

public:
	enum State {
		Starting,
		Bouncing,
		Disappear
	};

	State ballState;
	Ball() {
		/*printf("%f,%f\n", WIDTH, HEIGHT);*/
		this->circleShape = sf::CircleShape(RADIUS);
		circleShape.setOrigin(sf::Vector2f(circleShape.getRadius(), circleShape.getRadius()));
		this->speed = START_SPEED;
		ballState = Starting;
		this->speed = START_SPEED;
	};
	~Ball() {};
	void Update() override {};
	sf::Vector2f GetPos() override;
};

