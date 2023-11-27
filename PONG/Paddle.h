#pragma once
#include "Movable.h"
#include "Ball.h"
#include <random>
class Paddle : public Movable
{
private:
	bool shouldElapsedReactionTime = false;
	const float START_SPEED = 5000.0f;
	const float AI_START_SPEED = 1000.0f;
	const float MAX_SPEED = 10.0f;
	const float SCREEN_OFFSET = 30.0f;
	const float humanReationTime = 0.3f;
	float minOffset = 0.0f;
	float maxOffset = 0.0f;
	float predictedY = 0.0f;
	float randomOffset = 0.0f;
	float reactionTimer = 0.0f;
	float PredictBallLanding(sf::Vector2f ballPos);
	float GenerateRandomOffset(int min, int max);
	void InitAIPaddle();
	bool ReactionTimeElapsed(float deltaTime);
public:
	const float HEIGHT = 80.0;
	const float WIDTH = 10.0;
	bool isAI = false;
	enum ScreenPos{left,right};
	ScreenPos paddlePos;
	Paddle(){
		/*printf("%f,%f\n", WIDTH, HEIGHT);*/
		this->rectShape = sf::RectangleShape(sf::Vector2f(WIDTH, HEIGHT));
		this->rectShape.setOrigin(sf::Vector2f(WIDTH / 2, HEIGHT / 2));
		this->speed = START_SPEED;
		srand(static_cast<unsigned>(time(nullptr)));
		
	};
	~Paddle() {};
	void SetAIPaddleMoveDir(Ball* ball);
	void Update(float deltaTime, Ball* ball);
	sf::Vector2f GetPos() override;
	void Init(float resX, float resY, ScreenPos pos);
	void BoundMovable(float resoultionX, float resolutionY) override;
};

