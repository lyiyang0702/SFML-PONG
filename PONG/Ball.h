#pragma once
//#include <SFML/System.hpp>
//#include <SFML/Graphics.hpp>
#include "Movable.h"

class Ball: public Movable
{
private:
	const float START_SPEED = 200.0f;
	const float MAX_SPEED = 1000.0f;
	const float RADIUS = 10.0f;
	const float PI = 3.1415926;
	//const float START_RADIAN = PI / 4;
	const float START_RADIAN = PI / 4;
	float acceleration = 20.0f;
	float stillDuration = 0.5f;
	float stillTimer = 0.0f;
public:
	enum State {
		Still,
		Starting,
		OutLeftBound,
		OutRightBound,
		CollidePaddleCenter,
		CollideUpperPaddle,
		CollideBottomPaddle,
		CollideUpperScreen,
		CollideBottomScreen
	};
	float currentRadian;
	State ballState;
	int forceX = 1;
	int forceY = 1;
	Ball() {
		/*printf("%f,%f\n", WIDTH, HEIGHT);*/
		this->circleShape = sf::CircleShape(RADIUS);
		circleShape.setOrigin(sf::Vector2f(RADIUS,RADIUS));
		this->speed = START_SPEED;
		ballState = Still;
		currentRadian = START_RADIAN;
	};
	~Ball() { };
	void Accelerate();
	void Init(float resX, float resY) override;
	void Update(float deltaTime) override;
	void BoundMovable(float resoultionX, float resolutionY) override;
	float GetSpeed();
	sf::Vector2f GetPos() override;
};

