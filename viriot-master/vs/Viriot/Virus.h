#ifndef VIRUS_H
#define VIRUS_H

#include "gameObject.h"
class Virus : public gameObject
{
public:
	Virus();
	Virus(string SpriteName, string SpriteVertFrag, startPos init_pos, int screenWidth, int screenHeight, int Num_Frames, float scale) : gameObject(SpriteName, SpriteVertFrag, init_pos, screenWidth, screenHeight, Num_Frames, scale) {};
	Virus(string SpriteName, string SpriteVertFrag, float init_xpos, float init_ypos, int screenWidth, int screenHeight, int Num_Frames, float scale, int phealtVirus, int ppoin) : gameObject(SpriteName, SpriteVertFrag, init_xpos, init_ypos, screenWidth, screenHeight, Num_Frames, scale) { healtVirus = phealtVirus; poin = ppoin; };
	~Virus();

	void Init();
	void Update(float deltaTime);
	void Render();

	float virusSpeed = 40;
	int virusLife = 0, healtVirus, poin;
};
#endif
