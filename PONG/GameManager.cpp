#include "GameManager.h"
void GameManager::Update() {

	while (window->isOpen())
	{
		this->ProcessEvent();
		if (currentstate != 0 && isPlaying) {
			delete currentstate;
			GameState* nextstate = new MainGame;
			currentstate = nextstate;
			currentstate->Run(window);
		}

		
		Render();
		

	}
}
void GameManager::HandleInput(sf::Keyboard::Key key, bool isPressed) {

	if (isPressed) {
		if (key == sf::Keyboard::Key::F) {
			if (hasStarted) return;
			printf("Start Game\n");
			hasStarted = true;
			TitleScreen* titleScreen = (TitleScreen*)currentstate;
			titleScreen->SelectPlayerMode();
		}
		if (key == sf::Keyboard::Key::Num1) {
			printf("Entered one player mode \n");
			isTwoPlayerMode = true;
			isPlaying = true;
		}

		if (key == sf::Keyboard::Key::Num2) {
			printf("Entered one player mode \n");
			isPlaying = true;
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
		
			
		/*if (event.type == sf::Event::KeyPressed) {
			if (event.key.code == sf::Keyboard::F) {
				if (!startGame) {
					
					startGame = true;
				}
			}
		}*/
	}

}
void GameManager::Start() {
	
}

void GameManager::Render() {
	window->clear();
	currentstate->Render();
	window->display();
}



