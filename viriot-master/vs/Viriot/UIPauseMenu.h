#ifndef UIPAUSEMENU_H
#define UIPAUSEMENU_H

#include "UIPause.h"



using namespace glm;
using namespace std;

class UIPauseMenu : public UIPause
{
public:

	UIPauseMenu();
	UIPauseMenu(int screenWidth, int screenHeight,float bgWidth,float bgHeight);
	~UIPauseMenu();

	virtual void Init();
	virtual void DeInit();
	virtual void Update(float deltaTime);
	virtual void Render();

protected:

	float posX[NUM_BUTTON_PAUSE], posY[NUM_BUTTON_PAUSE];
	float bgWidth = 0, bgHeight = 0;

};

#endif