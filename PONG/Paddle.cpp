#include "Paddle.h"
void Paddle::Update() {};

sf::Vector2f Paddle::GetPos() {
	return rectShape.getPosition();
}