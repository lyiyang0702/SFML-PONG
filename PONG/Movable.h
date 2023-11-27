#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
class Movable
{
protected:

	sf::CircleShape circleShape;
	sf::RectangleShape rectShape;
	float resolutionX = 0;
	float resolutionY = 0;
	float speed = 0.0;

public:

	//Movable(sf::CircleShape circle) :circleShape(circle) {};	
	//Movable(sf::RectangleShape rect) :rectShape(rect) {};

	virtual ~Movable() {};
	virtual void Init(float resX, float resY);
	virtual void Update(float deltaTime);
	virtual void Move(const float dirX, const float dirY, float dt);
	virtual void Render(sf::RenderWindow* window);
	virtual void SetPos(float x, float y);
	virtual void BoundMovable(float resoultionX, float resolutionY) {};
	virtual sf::Vector2f GetPos() { return sf::Vector2f(0, 0); };
	sf::CircleShape& GetCircleShape() { return circleShape; };
	sf::RectangleShape& GetRectShape() { return rectShape; };
	
};

