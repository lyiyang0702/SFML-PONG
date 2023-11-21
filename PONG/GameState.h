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
	sf::RenderWindow *window = nullptr;
	sf::Font font;
	void InitWindow(sf::RenderWindow* win);
public:
	GameState() {
		if (!font.loadFromFile("font.ttf"))
		{
			printf("ERROR:Font loading failed!\n");
			return;
		}
	};
	virtual ~GameState() {
		window = nullptr;
	}
	//virtual GameState* Run() = 0;
	virtual void Run(sf::RenderWindow* win) = 0;
	virtual void Render() {};

};

