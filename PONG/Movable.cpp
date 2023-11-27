#include "Movable.h"

//Movable:: ~Movable() {};
void Movable::Update(float deltaTime) {};
void Movable::Init(float resX, float resY) {
	this->resolutionX = resX;
	this->resolutionY = resY;
};
void Movable::Move(const float dirX, const float dirY,float dt) {
	//printf("%f,%f,%f\n", dirX,dirY,speed);
	this->circleShape.move(dirX * speed * dt, dirY * speed * dt);
	this->rectShape.move(dirX * speed * dt, dirY * speed* dt);
	BoundMovable(resolutionX, resolutionY);
	//printf("%f,%f\n", circleShape.getPosition().x, circleShape.getPosition().y);
}

void Movable::Render(sf::RenderWindow* window) {

	window->draw(this->circleShape);
	window->draw(this->rectShape);
}

void Movable::SetPos(float x, float y) {
	this->circleShape.setPosition(sf::Vector2f(x, y));
	this->rectShape.setPosition(sf::Vector2f(x, y));
}
