#include "UIPauseMenu.h"


UIPauseMenu::UIPauseMenu()
{
}

UIPauseMenu::UIPauseMenu(int screenWidth, int screenHeight, float bgWidth, float bgHeight)
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	this->bgWidth = bgWidth;
	this->bgHeight = bgHeight;
	Init();
}


UIPauseMenu::~UIPauseMenu()
{
}

void UIPauseMenu::Init()
{
	string buttons[NUM_BUTTON_PAUSE] = { "resume.png", "restart.png", "exit.png" };
	string hover_buttons[NUM_BUTTON_PAUSE] = { "resume.png", "restart.png", "exit.png" };
	this->program = BuildShader("shader.vert", "shader.frag");
	InitText();
	InitButton(buttons, hover_buttons);
	posX[0] = (bgWidth + (button_width[0] / 2)) / 2;;
	posX[1] = (bgWidth + (button_width[1] / 2)) / 2;;
	posX[2] = (bgWidth + (button_width[2] / 2)) / 2;;

	posY[0] = (screenHeight) / 2;
	posY[1] = ((screenHeight) / 2)+100;
	posY[2] = ((screenHeight) / 2) + 200;

}

void UIPauseMenu::DeInit() {

}

void UIPauseMenu::Update(float deltaTime)
{
	
}

void UIPauseMenu::Render()
{
	RenderButton(posX, posY);
}