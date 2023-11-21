#include "TitleScreen.h"
#include "GameManager.h"
//GameManager& gm = GameManager::GetInstance();
void TitleScreen::SelectPlayerMode() {
	this->UpdatePrompt();
	//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
	//	printf("Entered One Player Mode");
	//	return true;
	//}
	//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
	//	printf("Entered Two Player Mode");
	//	gm.isTwoPlayerMode = true;
	//	return true;
	//}
	//return false;
}

void TitleScreen::DisplayTitle() {
	title.setFont(font);
	title.setString("PONG");
	auto rect = title.getLocalBounds();
	title.setOrigin(rect.width / 2, rect.height / 2);
	title.setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y/4));
	title.setCharacterSize(50);
	window->draw(title);
}
void TitleScreen::DisplayPrompt() {
	prompt.setFont(font);
	prompt.setString(promptString);
	auto rect = prompt.getLocalBounds();
	prompt.setOrigin(rect.width / 2, rect.height / 2);
	prompt.setPosition(sf::Vector2f(window->getSize().x / 2, window->getSize().y / 2 +100));
	prompt.setCharacterSize(24);
	//std::string s = prompt.getString();
	//std::cout << s << std::endl;
	window->draw(prompt);
}

void TitleScreen::UpdatePrompt() {
	promptString = "Press 1 Enter One Player Mode\nPress 2 Enter Two Players Mode\n";
}
void TitleScreen::Render() {
	DisplayTitle();
	DisplayPrompt();
}

void TitleScreen::Run(sf::RenderWindow* win) {
	this->InitWindow(win);
}
//GameState* TitleScreen::Run() {
//
//	return new MainGame;
//}