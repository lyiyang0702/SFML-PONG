#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
class Movable
{
protected:
	const float START_SPEED = 1.0;
	sf::CircleShape circleShape;
	sf::RectangleShape rectShape;
	float speed;
	

public:

	Movable(sf::CircleShape circle) :circleShape(circle) {
		this->speed = START_SPEED;
	};	
	Movable(sf::RectangleShape rect) :rectShape(rect) {
		this->speed = START_SPEED;
	};

	virtual ~Movable();
	virtual void Init();
	virtual void Update();
	virtual void Move(const float dirX, const float dirY);
	virtual void Render(sf::RenderWindow* window);
	virtual void SetPos(float x, float y);
	virtual sf::Vector2f GetPos() { return sf::Vector2f(0, 0); };
	sf::CircleShape GetCircleShape() { return circleShape; };
	sf::RectangleShape GetRectShape() { return rectShape; };
	
};

