#include "MainGame.h"
#include "GameManager.h"

GameManager& gameManager = GameManager::GetInstance();
void MainGame:: Run(sf::RenderWindow* win) {
	this->InitWindow(win);
	this->InitPlayers();
	this->InitVriables();
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
	leftPaddle.isAI = !gameManager.isTwoPlayerMode;
}

void  MainGame::InitVriables() {
	leftPaddle.SetPos(10, window->getSize().y / 2.);
	rightPaddle.SetPos(window->getSize().x - 10, window->getSize().y / 2.);
	ball.SetPos(window->getSize().x / 2., window->getSize().y / 2.);
	middleLine = sf::RectangleShape(sf::Vector2f(5., window->getSize().y));
	middleLine.setPosition(window->getSize().x / 2 -2.5, 0);
	this->InitScoreText(leftScoreText, std::to_string(leftScore));
	this->InitScoreText(rightScoreText, std::to_string(rightScore));
	leftScoreText.setPosition(window->getSize().x / 4, 50);
	rightScoreText.setPosition(window->getSize().x *0.75, 50);
}

void MainGame::InitScoreText(sf::Text& text, std::string s) {
	text.setFont(font);
	text.setCharacterSize(80);
	text.setString(s);
	auto rect = text.getLocalBounds();
	text.setOrigin(rect.width / 2, rect.height / 2);
}

void  MainGame::Update(sf::Time deltaTime) {

}