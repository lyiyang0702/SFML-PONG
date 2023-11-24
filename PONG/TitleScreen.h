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
	TitleScreen(sf::RenderWindow* win);

	~TitleScreen() {
		printf("Destroied Title Screen\n");
	};
	void SelectPlayerMode();
	void Render() override;
	void Run() override;
	//GameState* Run() override;
};

