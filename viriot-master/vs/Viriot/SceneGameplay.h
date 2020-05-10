#ifndef SCENEGAMEPLAY_H
#define SCENEGAMEPLAY_H

#include "SceneHandler.h"
#include "PlayerScript.h"
#include "Virus.h"
#include "UIPauseMenu.h"
#include "UIGameOverMenu.h"
#include "Background.h"
#include "Bullet.h"



enum stateGame {
	play = 0,
	pause = 1,
	gameOver = 2,
};

class SceneGameplay : public SceneHandler

{
public:
	SceneGameplay();
	SceneGameplay(unsigned int screenWidth, unsigned int screenHeight);
	~SceneGameplay();

	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();

	

	void updateGameOver(float deltaTime);
	void renderGameOver();

	void updatePause(float deltaTime);
	void renderPause();

	void updatePlay(float deltaTime);
	void renderPlay();

	stateGame state = pause;
	PlayerScript player;
	Virus virus;

	Background bg, logoGame, bannerGameOver;

	int timeGapLimit=700, timeGapCount=0;

	UIPauseMenu uipause;
	UIGameOverMenu uigameover;

	int virusCount = 10;
	Virus virusA[10];
	int bulletCount = 5;
	Bullet bulletA[5];
	int bulgap = 0;
};

#endif