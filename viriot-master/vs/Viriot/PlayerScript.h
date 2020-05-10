#ifndef PLAYERSCRIPT_H
#define PLAYERSCRIPT_H

#include "gameObject.h"

class PlayerScript : public gameObject
{
public:
	PlayerScript();
	PlayerScript(string SpriteName, string SpriteVertFrag, 
				startPos init_pos, int screenWidth, 
				int screenHeight, int Num_Frames, float scale) : gameObject(SpriteName, SpriteVertFrag,
																		init_pos, screenWidth, 
																		screenHeight, Num_Frames, scale) {};
	PlayerScript(string SpriteName, string SpriteVertFrag,
				float init_xpos, float init_ypos,
				int screenWidth, int screenHeight,
				int Num_Frames, float scale) : gameObject(SpriteName, SpriteVertFrag,
													init_xpos, init_ypos, screenWidth,
													screenHeight, Num_Frames, scale) {};
	~PlayerScript();

	virtual void Init();
	void Update(float deltaTime);
	virtual void Render();

	int PlayerLife = 3, timerCount = 0;
	bool canShoot = true;

	float batasKiri = 0, batasKanan = 0, batasAtas = 0, batasBawah = 0;

};

#endif