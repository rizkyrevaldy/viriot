#include "SceneGameplay.h"



SceneGameplay::SceneGameplay()
{
}

SceneGameplay::SceneGameplay(unsigned int screenWidth, unsigned int screenHeight)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	Init();

	
}


SceneGameplay::~SceneGameplay()
{
}

void SceneGameplay::Init() {
	

	virusCount = 10;
	virusA[10];
	bulletCount = 5;
	bulletA[5];
	bulgap = 0;
	state = play;
	

	player = PlayerScript("chara1", "playerSprite", startPos::CENTER_BOTTOM, screenWidth, screenHeight, 1, 1);
	player.batasAtas = 20;
	player.batasBawah = screenHeight - 100;
	player.batasKiri = screenWidth/2 - 240;
	player.batasKanan = screenWidth/2 + 140;

	for (int i = 0; i < virusCount; i++)
	{
		int tempHealth = rand() % 3, tempPoin;
		string tempvirusType;
		switch (tempHealth)
		{
		case 2:
			tempvirusType = "virus_ijo";
			break;
		case 1:
			tempvirusType = "virus_ungu";
			break;
		case 0:
			tempvirusType = "virus_merah";
			break;
		default:
			tempvirusType = "virus_merah";
			break;
		}
		virusA[i] = Virus(tempvirusType, "crateSprite", screenWidth / 2, -10, screenWidth, screenHeight, 1, 1, tempHealth, tempPoin);
		cout << tempvirusType << endl;
	}

	for (int i = 0; i < bulletCount; i++)
	{
		bulletA[i] = Bullet("laser_fix", "crateSprite", screenWidth / 2, player.getPosx(), screenWidth, screenHeight, 1, 1);
	}

	bg = Background("bg", "crateSprite", startPos::CENTER, screenWidth, screenHeight, 1, 1);
	bannerGameOver = Background("gameOverBanner", "crateSprite", startPos::CENTER, screenWidth, screenHeight, 1, 1);
	bannerGameOver.ypos -= 150;
	logoGame = Background("logo", "crateSprite", startPos::CENTER_TOP, screenWidth, screenHeight, 1, 1);
	logoGame.ypos += 50;

	uipause = UIPauseMenu(screenWidth, screenHeight, bg.frame_width, bg.frame_height);
	uigameover = UIGameOverMenu(screenWidth, screenHeight,bg.frame_width,bg.frame_height);
}

void SceneGameplay::Update(float deltaTime) {
	switch (state)
	{
	case play:
		updatePlay(deltaTime);
		
		break;
	case pause:
		updatePause(deltaTime);
		break;
	case gameOver:
		updateGameOver(deltaTime);
		break;
	default:
		break;
	}
}

void SceneGameplay::Render() {

	bg.Render();

	switch (state)
	{
	case play:
		renderPlay();
		break;
	case pause:
		renderPause();
		logoGame.Render();
		break;
	case gameOver:
		renderGameOver();
		bannerGameOver.Render();
		logoGame.Render();
		break;
	default:
		break;
	}

}


void SceneGameplay::updateGameOver(float deltaTime) {
	uigameover.Update(deltaTime);
}
void SceneGameplay::renderGameOver() {
	uigameover.Render();
}

void SceneGameplay::updatePause(float deltaTime) {
	uipause.Update(deltaTime);
}
void SceneGameplay::renderPause() {
	uipause.Render();
}

void SceneGameplay::updatePlay(float deltaTime) {
	if (state!=gameOver) {
		timeGapCount += deltaTime;
		if (timeGapCount>timeGapLimit) {
			timeGapCount = 0;

			for (int i = 0; i < virusCount; i++)
			{
				//generate virus pos
				if (virusA[i].virusLife <= 0) {
					int randxPos = rand() % (((screenWidth / 2 + 120) + 1) - (screenWidth / 2 - 220)) + (screenWidth / 2 - 220);
					virusA[i].xpos = randxPos;
					virusA[i].virusLife = 1;
					virusA[i].ypos = -15;
					break;
				}
			}
		}

		for (int i = 0; i < virusCount; i++)
		{

			virusA[i].Update(deltaTime);
			player.Update(deltaTime);
			//player collide with virus
			if (player.IsCollided(virusA[i])) {
				virusA[i].virusLife = 0;
				player.PlayerLife--;
				timeGapLimit = 700;
				if (player.PlayerLife == 0) {
					state = gameOver;
				}
				cout << "player life decreased !!" << endl;
				cout << player.PlayerLife << endl;
			}
			//if virus get past border
			if (virusA[i].ypos >= screenHeight - 50) {
				virusA[i].virusLife = 0;
			}

			for (int j = 0; j < bulletCount; j++)
			{
				//bullet generate pos
				bulgap++;
				if (bulgap>500 && !bulletA[j].BulletActive && !player.canShoot) {
					bulgap = 0;
					bulletA[j].setPosy(player.getPosy());
					bulletA[j].setPosx(player.getPosx() + 50);
					bulletA[j].BulletActive = true;
				}
				//if bullet get past border
				if (bulletA[j].getPosy() <= 30) {
					bulletA[j].BulletActive = false;
				}
				//bullet Collide
				if (virusA[i].IsCollided(bulletA[j])) {
					virusA[i].virusLife--;
					bulletA[j].BulletActive = false;
					bulletA[j].Update(deltaTime);
					virusA[i].Update(deltaTime);
				}
			}
		}
	}
	for (int i = 0; i < bulletCount; i++)
	{
		bulletA[i].Update(deltaTime);
	}
	
}
void SceneGameplay::renderPlay() {
	player.Render();
	for (int i = 0; i < virusCount; i++)
	{
		virusA[i].Render();
	}
	for (int i = 0; i < bulletCount; i++)
	{
		bulletA[i].Render();
	}
}
