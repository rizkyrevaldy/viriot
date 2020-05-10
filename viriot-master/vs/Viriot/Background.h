#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "gameObject.h"
class Background : public gameObject
{
public:
	Background();
	Background(string SpriteName, string SpriteVertFrag, startPos init_pos, int screenWidth, int screenHeight, int Num_Frames, float scale) : gameObject(SpriteName, SpriteVertFrag, init_pos, screenWidth, screenHeight, Num_Frames, scale) {};
	Background(string SpriteName, string SpriteVertFrag, float init_xpos, float init_ypos, int screenWidth, int screenHeight, int Num_Frames, float scale) : gameObject(SpriteName, SpriteVertFrag, init_xpos, init_ypos, screenWidth, screenHeight, Num_Frames, scale) {};
	~Background();

	void Init();
	void Update(float deltaTime);
	void Render();

};
#endif
