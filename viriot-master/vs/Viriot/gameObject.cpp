#include "gameObject.h"

gameObject::gameObject() {
}

gameObject::gameObject(string SpriteName, string SpriteVertFrag,
						float init_xpos, float init_ypos, 
						int screenWidth, int screenHeight, 
						int Num_Frames, float scale)
{
	this->screenHeight = screenHeight;
	this->screenWidth = screenWidth;
	BuildSprite(SpriteName, SpriteVertFrag, init_xpos, init_ypos, Num_Frames, scale);
}

gameObject::gameObject(string SpriteName, string SpriteVertFrag,
						startPos init_pos, int screenWidth, 
						int screenHeight, int Num_Frames, float scale)
{
	this->screenHeight = screenHeight;
	this->screenWidth = screenWidth;

	switch (init_pos)
	{
	case startPos::CENTER: 
		BuildSprite(SpriteName, SpriteVertFrag, 0, 0, Num_Frames, scale);
		reposSprite(((float)screenWidth - frame_width) / 2, ((float)screenHeight - frame_height) / 2);
		break;
	case startPos::CENTER_BOTTOM :
		BuildSprite(SpriteName, SpriteVertFrag, 0, 0 , Num_Frames, scale);
		reposSprite(((float)screenWidth - frame_width) / 2, ((float)screenHeight - frame_height));
		break;
	case startPos::CENTER_TOP:
		BuildSprite(SpriteName, SpriteVertFrag, 0, 0 , Num_Frames, scale);
		reposSprite(((float)screenWidth - frame_width) / 2, 0);
		break;
	default:
		break;
	}
	
}

gameObject::~gameObject()
{
}

void gameObject::Update(float deltaTime) {
	
	UpdateSprite(deltaTime);
}

void gameObject::UpdateSprite(float deltaTime) {
	frame_dur += deltaTime;
	if (frame_dur > FRAME_DUR) {

		frame_dur = 0;

		if (flip == 0) {
			if (frame_idx >= (NUM_FRAMES - 1)) frame_idx = 0;  else frame_idx++;
		}
		else {
			if (frame_idx <= 0) frame_idx = (NUM_FRAMES - 1);  else frame_idx--;
		}
	}
	// Pass frameIndex to shader
	glUniform1i(glGetUniformLocation(this->program, "frameIndex"), frame_idx);
}

void gameObject::Render() {
	RenderSprite();
}

int gameObject::getScreenHeight() {
	return this->screenHeight;
}

void gameObject::setScreenHeight(int value) {
	this->screenHeight = value;
}

int gameObject::getScreenWidth() {
	return this->screenWidth;
}

void gameObject::setScreenWidth(int value) {
	this->screenWidth = value;
}

bool gameObject::IsCollided(gameObject obj) {
	float x1 = this->xpos, y1 = this->ypos, width1 = this->frame_width, height1 = this->frame_height;
	float x2 = obj.xpos, y2 = obj.ypos, width2 = obj.frame_width, height2 = obj.frame_height;
	return (x1 < x2 + width2 && x1 + width1 > x2 && y1 < y2 + height2 && y1 + height1 > y2);
}


void gameObject::reposSprite(float x, float y) {
	xpos = x;
	ypos = y;
}

float gameObject::getPosx() {
	return this->xpos;
}

void gameObject::setPosx(float value) {
	this->xpos = value;
}

float gameObject::getPosy() {
	return this->ypos;
}

void gameObject::setPosy(float value) {
	this->ypos = value;
}

void gameObject::setFlip(bool value) {
	this->flip = value ? 1 : 0;
}
