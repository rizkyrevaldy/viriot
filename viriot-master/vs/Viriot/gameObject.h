#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "SpriteHandler.h"
//#include "Game.h"

// mengatur kecepatan animasi
#define FRAME_DUR 60

using namespace glm;

enum startPos {CENTER, CENTER_BOTTOM, CENTER_TOP};

class gameObject : public Sprite::SpriteHandler
{
public:
	gameObject();
	gameObject(string SpriteName, string SpriteVertFrag, float init_xpos, float init_ypos, int screenWidth, int screenHeight, int Num_Frames, float scale);
	gameObject(string SpriteName, string SpriteVertFrag, startPos init_pos, int screenWidth, int screenHeight, int Num_Frames, float scale);
	~gameObject();
	//virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();
	virtual void UpdateSprite(float deltaTime);

	//void BuildSprite(
	
	void reposSprite(float x, float y);
	bool IsCollided(gameObject obj);
	
	float getPosx();
	void setPosx(float value);
	float getPosy();
	void setPosy(float value);
	void setFlip(bool value);

	int getScreenHeight();
	void setScreenHeight(int value);
	int getScreenWidth();
	void setScreenWidth(int value);

};

#endif

