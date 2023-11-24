#include "Paddle.h"
void Paddle::Update() {};
sf::Vector2f Paddle::GetPos() {
	return rectShape.getPosition();
}

void Paddle::BoundMovable(float resoultionX, float resolutionY) {
	float paddleX = rectShape.getPosition().x;
	float paddleY = rectShape.getPosition().y;
	if ((paddleY - HEIGHT / 2) < 0 ) {
		printf("Out Upper Screen\n");
		rectShape.setPosition(paddleX, HEIGHT/2);
	}
	if ((paddleY + HEIGHT / 2) > resolutionY) {
		printf("Out Bottom Screen\n");
		rectShape.setPosition(paddleX, resolutionY - HEIGHT / 2);
	}
	//return (paddleY + )
}