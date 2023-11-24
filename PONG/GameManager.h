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
	TitleScreen* titleScreen;
	MainGame* mainScreen = nullptr;
	sf::Clock clock;
	float deltaTime = 0;
	GameManager() {
		window = new sf::RenderWindow(sf::VideoMode(800, 600), "PONG");
		titleScreen = new TitleScreen(window);
		currentstate = titleScreen;

		currentstate->Run();
	}
	void SwitchScene();
	~GameManager() {};
	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;
public:
	bool isTwoPlayerMode = false;
	sf::RenderWindow* window;
	void Run();
	void Update(float dt);
	static GameManager& GetInstance() {
		static GameManager instance;
		return instance;
	};
};



