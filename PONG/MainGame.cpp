#include "MainGame.h"
//#include "GameManager.h"

//GameManager& gameManager = GameManager::GetInstance();
MainGame::MainGame(sf::RenderWindow* win, int leftScore, int rightScore) :GameState(win) {
	this->InitPlayers();
	this->InitVriables();
	currentRadian = START_RADIAN;
}
void MainGame:: Run() {

	
	//this->Update();
}

void MainGame::Render() {
	//printf("Current screen is main game\n");
	
	leftPaddle.Render(window);
	rightPaddle.Render(window);
	ball.Render(window);
	window->draw(middleLine);
	window->draw(leftScoreText);
	window->draw(rightScoreText);
}
void MainGame::InitPlayers() {
	//leftPaddle.isAI = !gameManager.isTwoPlayerMode;
}

void  MainGame::InitVriables() {
	leftPaddle.Init(RES_X, RES_Y);
	rightPaddle.Init(RES_X, RES_Y);
	ball.Init(RES_X, RES_Y);
	leftPaddle.SetPos(20, RES_Y / 2.);
	rightPaddle.SetPos(RES_X - 20, RES_Y / 2.);
	ball.SetPos(RES_X / 2., RES_Y / 2.);
	middleLine = sf::RectangleShape(sf::Vector2f(5., RES_Y));
	middleLine.setPosition(RES_X / 2 -2.5, 0);
	this->InitScoreText(leftScoreText, std::to_string(leftScore));
	this->InitScoreText(rightScoreText, std::to_string(rightScore));
	leftScoreText.setPosition(RES_X / 4, 50);
	rightScoreText.setPosition(RES_X *0.75, 50);
}

void MainGame::InitScoreText(sf::Text& text, std::string s) {
	text.setFont(font);
	text.setCharacterSize(80);
	text.setString(s);
	auto rect = text.getLocalBounds();
	text.setOrigin(rect.width / 2, rect.height / 2);
}

void MainGame::Update(float dt) {
	//printf("%f\n",dt);
	//ball.Move(cos(currentRadian), sin(currentRadian),dt );
}