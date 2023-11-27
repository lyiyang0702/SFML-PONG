#include "Paddle.h"
void Paddle::Update(float deltaTime, Ball* ball) {
	if (!isAI) return;
	if (ball->ballState == Ball::Still) {
		shouldElapsedReactionTime = true;
		reactionTimer = 0.0f;
	}
	predictedY = PredictBallLanding(ball->GetPos());
	if (ReactionTimeElapsed(deltaTime)) {
		//move down
		//printf("%f\n", predictedY);
		predictedY += randomOffset;
		if (rectShape.getPosition().y < predictedY) {
			this->Move(0, 1, deltaTime);
		}
		//move up
		else if (rectShape.getPosition().y > predictedY) {
			this->Move(0, -1, deltaTime);
		}
	}

};

void Paddle::SetAIPaddleMoveDir(Ball* ball) {
	shouldElapsedReactionTime = true;
	randomOffset = GenerateRandomOffset(minOffset,maxOffset);
	reactionTimer = 0.0f;
	printf("random offset:%f\n", randomOffset);
	//predictedY += randomOffset;
}
sf::Vector2f Paddle::GetPos() {
	return rectShape.getPosition();
}
void Paddle::InitAIPaddle() {
	this->speed = AI_START_SPEED;
	minOffset = -resolutionY / 3;
	maxOffset = resolutionY / 3;
}
void Paddle::Init(float resX, float resY, ScreenPos pos) {
	Movable::Init(resX, resY);
	if (isAI) {
		this->InitAIPaddle();
	}
	paddlePos = pos;
	if (pos == ScreenPos::left) {
		rectShape.setPosition(SCREEN_OFFSET, resY / 2.);
	}
	else if (pos == ScreenPos::right) {
		rectShape.setPosition(resX - SCREEN_OFFSET, resY / 2.);
	}
}
void Paddle::BoundMovable(float resoultionX, float resolutionY) {
	float paddleX = rectShape.getPosition().x;
	float paddleY = rectShape.getPosition().y;
	if ((paddleY - HEIGHT / 2) < 0 ) {
		//printf("Out Upper Screen\n");
		rectShape.setPosition(paddleX, HEIGHT/2);
	}
	if ((paddleY + HEIGHT / 2) > resolutionY) {
		//printf("Out Bottom Screen\n");
		rectShape.setPosition(paddleX, resolutionY - HEIGHT / 2);
	}
}

float Paddle::PredictBallLanding(sf::Vector2f ballPos) {
	return ballPos.y;
}

float Paddle::GenerateRandomOffset(int min, int max) {
	return static_cast<float>(rand() % (max - min) + min + 1);
}

bool Paddle::ReactionTimeElapsed(float deltaTime) {
	
	if (shouldElapsedReactionTime) {
		//reactionTimer = 0.0f;
		reactionTimer += deltaTime;
	}
	//printf("%f\n", reactionTimer);
	if (reactionTimer > humanReationTime) {
		//printf("START MOVING\n");
		shouldElapsedReactionTime = false;
		return true;
	}
	return false;
}