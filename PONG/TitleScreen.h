#pragma once
#include "GameState.h"
#include "MainGame.h"
class TitleScreen : public GameState
{
private:
	sf::Text title;
	sf::Text prompt;

	sf::String promptString;
	void DisplayTitle();
	void DisplayPrompt();
	void UpdatePrompt();
public:
	TitleScreen() {

		promptString = "Press F To START";
	};
	~TitleScreen() {
	
	};
	void SelectPlayerMode();
	void Render() override;
	void Run(sf::RenderWindow* win) override;
	//GameState* Run() override;
};

