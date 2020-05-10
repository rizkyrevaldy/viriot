#ifndef UIGAMEOVERMENU_H
#define UIGAMEOVERMENU_H

#include "UIGameOver.h"


using namespace glm;
using namespace std;

class UIGameOverMenu : public UIGameOver
{
public:

	UIGameOverMenu();
	UIGameOverMenu(int screenWidth, int screenHeight, float bgWidth, float bgHeight);
	~UIGameOverMenu();

	virtual void Init();
	virtual void DeInit();
	virtual void Update(float deltaTime);
	virtual void Render();

protected:

	float posX[NUM_BUTTON], posY[NUM_BUTTON];
	float bgWidth=0 , bgHeight=0;


};

#endif