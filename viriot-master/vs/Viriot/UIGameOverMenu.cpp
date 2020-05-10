#include "UIGameOverMenu.h"


UIGameOverMenu::UIGameOverMenu()
{
}

UIGameOverMenu::UIGameOverMenu(int screenWidth, int screenHeight, float bgWidth, float bgHeight)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->bgWidth = bgWidth;
	this->bgHeight = bgHeight;
	Init();
}


UIGameOverMenu::~UIGameOverMenu()
{
}

void UIGameOverMenu::Init()
{
	string buttons[NUM_BUTTON] = {  "restartbtnGO.png", "exitbtnGO.png" };
	string hover_buttons[NUM_BUTTON] = { "restartbtnGO_hover.png", "exitbtnGO_hover.png" };
	this->program = BuildShader("shader.vert", "shader.frag");
	InitText();
	InitButton(buttons, hover_buttons);
	//	newS = "";
	posX[0] =  (bgWidth + (button_width[0] / 2)) / 2;
	posX[1] = (bgWidth + (button_width[1] / 2)) / 2;

	posY[0] = (screenHeight)/2;
	posY[1] = ((screenHeight) / 2 )+ 100;

}

void UIGameOverMenu::DeInit() {

}

void UIGameOverMenu::Update(float deltaTime)
{
	
}

void UIGameOverMenu::Render()
{
	RenderButton(posX, posY);
}