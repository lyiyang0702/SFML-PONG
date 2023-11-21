#pragma once
#include "GameState.h"
#include "TitleScreen.h"
#include "MainGame.h"
class GameManager
{

private:

	bool isPaused = false;
	bool isPlaying = false;
	bool hasStarted = false;
	void ProcessEvent();
	void HandleInput(sf::Keyboard::Key key, bool isPressed);
	void Start();

	void Render();
	GameState* currentstate;
	GameManager() {
		currentstate = new TitleScreen;
		window = new sf::RenderWindow(sf::VideoMode(800, 600), "PONG");
		currentstate->Run(window);
	}
	~GameManager() {};
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
public:
	bool isTwoPlayerMode = false;
	sf::RenderWindow* window;
	void Update();
	static GameManager& GetInstance() {
		static GameManager instance;
		return instance;
	};
};


