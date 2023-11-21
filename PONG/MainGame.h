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
	Paddle leftPaddle;
	Paddle rightPaddle;
	int leftScore = 0;
	int rightScore = 0;
	Ball ball;
	sf::RectangleShape middleLine;
	sf::Text leftScoreText;
	sf::Text rightScoreText;
	void InitVriables();
	void InitPlayers();
	void InitScoreText(sf::Text& text, std::string s);
public:
	MainGame() {};
	~MainGame() {};
	void Update(sf::Time deltaTime);
	void Render() override;
	void Run(sf::RenderWindow* win) override;
	//GameState* Run() override;


};

