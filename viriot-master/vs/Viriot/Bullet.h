#ifndef BULLET_H
#define BULLET_H

#include "gameObject.h"
class Bullet : public gameObject
{
public:
	Bullet();
	Bullet(string SpriteName, string SpriteVertFrag, startPos init_pos, int screenWidth, int screenHeight, int Num_Frames, float scale) : gameObject(SpriteName, SpriteVertFrag, init_pos, screenWidth, screenHeight, Num_Frames, scale) {};
	Bullet(string SpriteName, string SpriteVertFrag, float init_xpos, float init_ypos, int screenWidth, int screenHeight, int Num_Frames, float scale) : gameObject(SpriteName, SpriteVertFrag, init_xpos, init_ypos, screenWidth, screenHeight, Num_Frames, scale) {};
	~Bullet();

	void Init();
	void Update(float deltaTime);
	void Render();

	float BulletSpeed = 40;
	bool BulletActive = false;
};
#endif
