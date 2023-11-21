#include "Movable.h"

Movable:: ~Movable() {};
void Movable::Update() {};
void Movable::Init() {};
void Movable::Move(const float dirX, const float dirY) {
	this->circleShape.move(dirX * speed, dirY * speed);
	this->rectShape.move(dirX * speed, dirY * speed);
}

void Movable::Render(sf::RenderWindow* window) {
	window->draw(this->circleShape);
	window->draw(this->rectShape);
}

void Movable::SetPos(float x, float y) {
	this->circleShape.setPosition(sf::Vector2f(x, y));
	this->rectShape.setPosition(sf::Vector2f(x, y));
}
