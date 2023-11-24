#pragma once
#include "GameState.h"
enum BallFlags {
	Ball_At_Center_Prerelease_Wait = 1 << 0,
	Ball_Now_Moving_In_Regular_Gameplay = 1 << 2,
	Ball_Went_In_So_Flash_Player_Score = 1 << 3
};


class MainGame: public GameState
{
private:
	const float PI = 3.1415926;
	const float START_RADIAN = PI / 4;
	float currentRadian = 0;
	int leftScore = 0;
	int rightScore = 0;

	sf::RectangleShape middleLine;
	sf::Text leftScoreText;
	sf::Text rightScoreText;
	void InitVriables();
	void InitPlayers();
	void InitScoreText(sf::Text& text, std::string s);
public:
	Paddle leftPaddle;
	Paddle rightPaddle;
	Ball ball;
	MainGame(sf::RenderWindow* win, int leftScore, int rightScore);
	~MainGame() {};
	void Update(float dt)override;
	void Render() override;
	void Run() override;
	//GameState* Run() override;


};

