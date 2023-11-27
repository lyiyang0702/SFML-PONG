#include "MainGame.h"
#include "GameManager.h"

GameManager& gameManager = GameManager::GetInstance();
MainGame::MainGame(sf::RenderWindow* win, int leftScore, int rightScore) :GameState(win) {
	this->InitPlayers();
	this->InitVriables();
}
void MainGame:: Run() {

	
	//this->Update();
}

void MainGame::Render() {
	//printf("Current screen is main game\n");

	leftPaddle.Render(window);
	rightPaddle.Render(window);
	if (hasBall) {
		ball->Render(window);
	}

	window->draw(middleLine);
	if (isScoreVisible) {
		window->draw(leftScoreText);
		window->draw(rightScoreText);
	}

}
void MainGame::InitPlayers() {
	leftPaddle.isAI = !gameManager.isTwoPlayerMode;
}

void  MainGame::InitVriables() {
	leftPaddle.Init(RES_X, RES_Y,Paddle::left);
	rightPaddle.Init(RES_X, RES_Y,Paddle::right);
	ball->Init(RES_X, RES_Y);
	middleLine = sf::RectangleShape(sf::Vector2f(5., RES_Y));
	middleLine.setPosition(RES_X / 2 -2.5, 0);
	this->InitScoreText(leftScoreText, std::to_string(leftScore));
	this->InitScoreText(rightScoreText, std::to_string(rightScore));
	leftScoreText.setPosition(RES_X / 4, 50);
	rightScoreText.setPosition(RES_X *0.75, 50);
}

void MainGame::InitScoreText(sf::Text& text, std::string s) {
	text.setFont(font);
	text.setCharacterSize(80);
	text.setString(s);
	auto rect = text.getLocalBounds();
	text.setOrigin(rect.width / 2, rect.height / 2);
}

void MainGame::Update(float dt) {
	//printf("%f\n",dt);
	deltaTime = dt;
	
	IsBallOutBound();
	if (!hasBall) return;
	ball->Update(dt);
	leftPaddle.Update(dt, ball);
	//printf("Update\n");
	OnCollision(ball, leftPaddle);
	OnCollision(ball, rightPaddle);
}


bool MainGame::IsBallOutBound() {
	if (ball->ballState == Ball::OutRightBound) {
		hasBall = false;
		delete ball;
		if (this->UpdateScore("Left")) {
			OnBallDestroy();
		}
	}
	else if (ball->ballState == Ball::OutLeftBound) {
		hasBall = false;
		delete ball;
		if (this->UpdateScore("Right")) {
			OnBallDestroy();
		}
	}
	return !hasBall;
}
bool MainGame::UpdateScore(std::string pos) {
	if (pos == "Left") {
		leftScore++;
		leftScoreText.setString(std::to_string(leftScore));

	}
	if (pos == "Right") {
		rightScore++;
		rightScoreText.setString(std::to_string(rightScore));

	}
	return true;
}
void MainGame::OnBallDestroy() {
	ball = new Ball();
	ball->Init(RES_X, RES_Y);
	hasBall = true;
}
void MainGame::OnCollision(Ball* ball, Paddle& paddle) {
	bool hasEntered = false;
	float shapeX = ball->GetPos().x;
	float shapeY = ball->GetPos().y;
	float paddleX = paddle.GetPos().x;
	float paddleY = paddle.GetPos().y;
	float dis = (shapeY - paddleY) / paddle.HEIGHT;

	if (ball->GetCircleShape().getGlobalBounds().intersects(paddle.GetRectShape().getGlobalBounds())) {
		ballHasBouncedPlayerSide = true;
		printf("Has Entered Collison\n");
		ball->Accelerate();
		if (shapeX - paddleX > 0) {
			if (paddle.paddlePos == Paddle::left) {
				//printf("Right\n");
				ball->forceX = 1;
			}
			else {
				//printf("Left\n");
				if (leftPaddle.isAI) {
					leftPaddle.SetAIPaddleMoveDir(ball);
				}
				printf("Bouncing\n");
				ball->forceX = -1;
			}
		}
		else if (shapeX - paddleX < 0) {
			if (paddle.paddlePos == Paddle::right) {
				printf("Bouncing\n");
				if (leftPaddle.isAI) {
					leftPaddle.SetAIPaddleMoveDir(ball);
				}

				//printf("Left\n");
				ball->forceX = -1;
			}
			else {
				//printf("Right\n");

				ball->forceX = 1;
			}
		}

		if (dis < 0.05f && dis > -0.05f) {
			//printf("Collide in center\n");
			ball->ballState = Ball::CollidePaddleCenter;
		}

		else if (dis < -0.05f) {
			//printf("Collide in upper area\n");
			ball->ballState = Ball::CollideUpperPaddle;
		}
		else if (dis > 0.05f) {
			//printf("Collide in bottom area\n");
			ball->ballState = Ball::CollideBottomPaddle;
		}

	}
	ballHasBouncedPlayerSide = false;
	//printf("Has Exited Collison\n");
}