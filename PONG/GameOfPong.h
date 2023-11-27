#pragma once
#include "Ball.h"
#include "Paddle.h"
#include "GameManager.h"
enum BallFlags {
	ALL = -1,
	Ball_At_Center_Prerelease_Wait = 1 << 0,
	Ball_Now_Moving_In_Regular_Gameplay = 1 << 2,
	Ball_Went_In_So_Flash_Player_Score = 1 << 3
};

//void HandleGameState(BallFlags flags, Ball* ball) {
//	if (flags & BallFlags::Ball_Went_In_So_Flash_Player_Score) {
//		GameManager& gm = GameManager::GetInstance();
//		gm.mainScreen->UpdateScore();
//	}
//}
