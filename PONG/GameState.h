#pragma once
#include "Ball.h"
#include "Paddle.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
class GameState
{
protected:
	sf::RenderWindow* window;
	sf::Font font;
	void InitWindow(sf::RenderWindow& win);
	float RES_X = 0;
	float RES_Y = 0;

public:
	GameState(sf::RenderWindow* win):window(win) {
		if (!font.loadFromFile("font.ttf"))
		{
			printf("ERROR:Font loading failed!\n");
			return;
		}
		RES_X = window->getSize().x;
		RES_Y = window->getSize().y;

	};
	virtual ~GameState() {
		
	}
	virtual void Update(float dt) {};
	//virtual GameState* Run() = 0;
	virtual void Run() = 0;
	virtual void Render() {};

};

