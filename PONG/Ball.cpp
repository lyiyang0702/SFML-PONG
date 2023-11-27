#include "Ball.h"
//#include "GameManager.h"

//GameManager& gm = GameManager::GetInstance();

sf::Vector2f Ball::GetPos() {
	return circleShape.getPosition();
}

void Ball::Init(float resX, float resY) {
	Movable::Init(resX, resY);
	this->currentRadian = START_RADIAN;
	this->speed = START_SPEED;
	circleShape.setPosition(this->resolutionX / 2, this->resolutionY / 2);
}

void Ball::Accelerate() {
	speed += acceleration;
	if (speed > MAX_SPEED) {
		speed = MAX_SPEED;
	}
}
void Ball::BoundMovable(float resoultionX, float resolutionY) {
	float ballX = circleShape.getPosition().x;
	float ballY = circleShape.getPosition().y;
	if ((ballY - RADIUS) < 0) {
		//printf("Out Upper Screen\n");
		ballState = CollideUpperScreen;
	}
	if ((ballY + RADIUS) > resolutionY) {
		//printf("Out Bottom Screen\n");
		ballState = CollideBottomScreen;
	}
	if ((ballX - RADIUS) < 0) {
		
		ballState = OutLeftBound;

		
	}
	if ((ballX + RADIUS) > resolutionX) {
		ballState = OutRightBound;
	}
}
void Ball::Update(float deltaTime) {
	switch (ballState)
	{
	case Ball::Starting:
		//this->Init(this->resolutionX, this->resolutionY);
		break;
	case Ball::Still:
		//printf("Still\n");
		stillTimer += deltaTime;
		speed = 0;
		if (stillTimer >= stillDuration) {
			speed = START_SPEED;
			ballState = Starting;
			stillTimer = 0.0f;
		}
		break;
	case Ball::OutLeftBound:
		//printf("Out Screen\n");
		//gm.mainScreen->hasBall = false;
		//gm.mainScreen->UpdateScore("Left");
		//ballState = Ball::Still;
		//return;
		break;
	case Ball::OutRightBound:
		//gm.mainScreen->hasBall = false;
		//gm.mainScreen->UpdateScore("Right");
		//ballState = Ball::Still;
		//return;
		//gm.mainScreen->UpdateScore("Right");
		break;
	case Ball::CollidePaddleCenter:
		currentRadian = 0;
		break;
	case Ball::CollideUpperPaddle:
		currentRadian = PI / 4;
		forceY = -1;
		break;
	case Ball::CollideBottomPaddle:
		currentRadian = PI / 4;
		forceY = 1;
		break;
	case Ball::CollideUpperScreen:
		currentRadian = PI / 4;
		forceY = 1;
		break;
	case Ball::CollideBottomScreen:
		currentRadian = PI / 4;
		forceY = -1;
		break;
	default:
		break;
	}
	//printf("Current Raidian: %f\n",currentRadian);
	this->Move(cos(this->currentRadian)*forceX, sin(this->currentRadian) * forceY, deltaTime );
}

float Ball::GetSpeed() {
	return speed;
}