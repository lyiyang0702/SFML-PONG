#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Main.hpp>
#include <cmath>
#include "Ball.h"
#include "Paddle.h"
#include "GameState.h"
#include "TitleScreen.h"
#include "GameManager.h"
int main()
{
	/*const double pi = 3.14159;
	sf::RenderWindow window(sf::VideoMode(800, 600), "PONG");
	Ball ball;
	Paddle paddle;
	ball.SetPos(390, 300);
	paddle .SetPos(400, 300);
	int forceX = 1;
	int forceY = 1;
	float shapeX = ball.GetPos().x;
	float shapeY = ball.GetPos().y;
	float paddleX = paddle.GetPos().x;
	float paddleY = paddle.GetPos().y;
	float dis = (shapeY - paddleY) / 50.0f;*/
	//sf::CircleShape shape(10.f);
	//shape.setFillColor(sf::Color::Green);
	//sf::RectangleShape rect(sf::Vector2f(10.0f, 50.0f));
	//shape.setPosition(sf::Vector2f(480,300));
	//shape.setOrigin(sf::Vector2f(shape.getRadius(), shape.getRadius()));
	//rect.setPosition(sf::Vector2f(500,300));
	////printf("%f, %f", rect.getSize().x/2, rect.getSize().y/2);
	//rect.setOrigin(sf::Vector2f(rect.getSize().x /2 , rect.getSize().y/2));
	//GameState* currentstate = new TitleScreen;
	//while (currentstate != 0)
	//{
	//	GameState* nextstate = currentstate->Run();
	//	delete currentstate;
	//	currentstate = nextstate;
	//}
	//bool isBouncing = false;
	GameManager& gm = GameManager::GetInstance();
	gm.Run();
	//while (gm->window->isOpen())
	//{
	//	sf::Event event;
	//	while (gm->window->pollEvent(event))
	//	{
	//		if (event.type == sf::Event::Closed)
	//			gm->window->close();
	//	}

	//	//int speed = 1;



	//	//if (ball.GetCircleShape().getGlobalBounds().intersects(paddle.GetRectShape().getGlobalBounds()))
	//	//{

	//	//	//printf("A collision happened\n");

	//	//	if (!isBouncing) {
	//	//		if (shapeX - paddleX > 0) {
	//	//			printf("Right\n");
	//	//			forceX = 1;
	//	//		}
	//	//		else if (shapeX - paddleX < 0) {
	//	//			printf("Left\n");
	//	//			forceX = -1;
	//	//		}

	//	//		isBouncing = true;
	//	//	}
	//	//}
	//	//
	//	//if (isBouncing) {
	//	//	if (dis < 0.05f && dis > -0.05f) {
	//			//printf("Collide in center\n");
	//			//printf("%d\n", forceX);
	//			//ball.Move(cos(0)*forceX, sin(0));
	//			//shape.move(cos(0) * speed*(-1), sin(0) * speed);
	//			//shapeX += cos(0) * speed ;
	//			//shapeY += sin(0) * speed;
	//			/*shape.setPosition((shape.getPosition().x + cos(0)*speed), (shape.getPosition().y + sin(0) * speed));*/
	//		//}
	//	//}


	//	//		else if (dis < -0.05f) {
	//	//			printf("Collide in upper area\n");
	//	//			shapeX += forceX * cos(pi / 4) * speed;
	//	//			shapeY += -sin(pi / 4) * speed;
	//	//			//shape.setPosition((shape.getPosition().x + cos(pi / 4) * speed), (shape.getPosition().y + sin(pi / 4) * -speed));
	//	//		}
	//	//		else if (dis > 0.05f) {
	//	//			printf("Collide in bottom area\n");
	//	//			shapeX += forceX * cos(pi / 4) * speed;
	//	//			shapeY += sin(pi / 4) * speed;
	//	//			//shape.setPosition((shape.getPosition().x + cos(pi / 4) * speed), (shape.getPosition().y + sin(pi / 4) * speed));
	//	//		}

	//		//shape.setPosition(shapeX, shapeY);
	//	//}
	//		
	//		//if (new_pos.x - ball_radius < 0) { // left window edge
	//		//	direction.x *= -1;
	//		//	new_pos.x = 0 + ball_radius;
	//		//}
	//		//else if (new_pos.x + ball_radius >= window_width) { // right window edge
	//		//	direction.x *= -1;
	//		//	new_pos.x = window_width - ball_radius;
	//		//}
	//		//else if (new_pos.y - ball_radius < 0) { // top of window
	//		//	direction.y *= -1;
	//		//	new_pos.y = 0 + ball_radius;
	//		//}
	//		//else if (new_pos.y + ball_radius >= window_height) { // bottom of window
	//		//	direction.y *= -1;
	//		//	new_pos.y = window_height - ball_radius;
	//		//}
	//	//}
	//	gm->window->clear();
	//	gm->Render();
	//	//window.draw(shape);
	//	//ball.Render(window);
	//	//paddle.Render(window);
	//	gm->window->display();
	//}
	return 0;
}