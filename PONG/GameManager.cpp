#include "GameManager.h"
void GameManager::Run() {
	

	while (window->isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		this->ProcessEvent();
		
		this->Update(deltaTime);


		Render();
		

	}
}
void GameManager::Update(float dt) {
	//printf("%f\n", dt);
	currentstate->Update(dt);
}

void GameManager::SwitchScene() {
	if (currentstate != 0 && isPlaying) {
		delete currentstate;
		mainScreen = new MainGame(window, 0, 0);
		GameState* nextstate = mainScreen;
		currentstate = nextstate;
		currentstate->Run();
	}
}
void GameManager::HandleInput(sf::Keyboard::Key key, bool isPressed) {

	if (isPressed) {
		if (key == sf::Keyboard::Key::F) {
			if (hasStarted) return;
			printf("Start Game\n");
			hasStarted = true;
			titleScreen->SelectPlayerMode();
		}
		if (key == sf::Keyboard::Key::Num1) {
			printf("Entered one player mode \n");
			isTwoPlayerMode = true;
			isPlaying = true;
			this->SwitchScene();
		}
		if (key == sf::Keyboard::Key::P) {
			isPaused = !isPaused;
		}

		if (key == sf::Keyboard::Key::Num2) {
			printf("Entered one player mode \n");
			isPlaying = true;
			this->SwitchScene();
		}
		if (!isPlaying) return;
		if (isPaused) return;
		
		if (key == sf::Keyboard::Key::W) {;
			printf("Move Up\n");
			mainScreen->leftPaddle.Move(0, -1,deltaTime);
		}
		if (key == sf::Keyboard::Key::S) {
			printf("Move Down\n");
			mainScreen->leftPaddle.Move(0, 1, deltaTime);
		}

		if (key == sf::Keyboard::Key::Down) {
			mainScreen->rightPaddle.Move(0, 1, deltaTime);
		}
		if (key == sf::Keyboard::Key::Up) {
			mainScreen->rightPaddle.Move(0, -1, deltaTime);
		}
	}

}
void GameManager::ProcessEvent() {
	
	sf::Event event;
	
	while (window->pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::Closed:
			window->close();
			break;
		case sf::Event::KeyPressed:
			this->HandleInput(event.key.code,true);
			break;
		case sf::Event::KeyReleased:
			this->HandleInput(event.key.code, false);
		default:
			break;
		}
	}

}
void GameManager::Start() {
	
}

void GameManager::Render() {
	window->clear();
	//window->draw(test);
	currentstate->Render();
	window->display();
}



