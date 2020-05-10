#ifndef DEMO_H
#define DEMO_H

#include "Game.h"
#include "PlayerScript.h"
#include "Virus.h"
#include "Bullet.h"
#include "UIPause.h"
#include "SceneGameplay.h"


#define FRAME_DUR 80

using namespace glm;

class Demo :
	public Engine::Game
{
public:
	Demo();
	~Demo();
	virtual void Init();
	virtual void Update(float deltaTime);
	virtual void Render();

	bool IsCollided(gameObject obj1, gameObject obj2);

private:
	unsigned int frame_idx = 0, flip = 0;
	void ControlPlayerSprite(float deltaTime);
	void ControlUI(float deltaTime);
	void InputMapping();

	
};

#endif

