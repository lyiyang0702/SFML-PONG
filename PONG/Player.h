#pragma once
#include "Paddle.h"
class Player
{
public:
	int score = 0;
	bool isAI = false;
	Paddle paddle;
	enum PlayerScreenPos {
		RightScreen,
		LeftScreen
	};

	PlayerScreenPos playerScreen;

	Player(PlayerScreenPos screenPos) :playerScreen(screenPos) {
		paddle.SetPos(130, 300);
	};
};

