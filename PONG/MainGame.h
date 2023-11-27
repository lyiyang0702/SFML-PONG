#pragma once
#include "GameState.h"



class MainGame: public GameState
{
private:
	int leftScore = 0;
	int rightScore = 0;
	bool ballHasBouncedPlayerSide = false;
	sf::RectangleShape middleLine;
	sf::Text leftScoreText;
	sf::Text rightScoreText;
	float deltaTime = 0.0f;
	float flashDuration = 1.0f; 
	float flashTimer = 0.0f;   
	bool isScoreVisible = true;
	void InitVriables();
	void InitPlayers();
	void InitScoreText(sf::Text& text, std::string s);
	void OnCollision(Ball* ball, Paddle& paddle);
	bool IsBallOutBound();
	bool UpdateScore(std::string pos);
	void OnBallDestroy();
public:
	bool hasBall = true;
	Paddle leftPaddle;
	Paddle rightPaddle;
	Ball* ball = new Ball();
	MainGame(sf::RenderWindow* win, int leftScore, int rightScore);
	~MainGame() {};
	void Update(float dt)override;
	void Render() override;
	void Run() override;



};

