#include "PlayerScript.h"
#include "Virus.h"


PlayerScript::PlayerScript()
{
}

PlayerScript::~PlayerScript()
{
}


void PlayerScript::Init() {

}

void PlayerScript::Update(float deltaTime) {
	this->gameObject::Update(deltaTime);
	if (this->xpos <= batasKiri) {
		xpos = batasKiri;
	}if (this->xpos >= batasKanan) {
		xpos = batasKanan;
	}
	if (this->ypos <= batasAtas) {
		ypos = batasAtas;
	}if (this->ypos >= batasBawah) {
		ypos = batasBawah;
	}
	if (!canShoot) {
		timerCount++;
		if (timerCount>600) {
			timerCount = 0;
			canShoot = true;
		}
	}

}

void PlayerScript::Render() {
	this->gameObject::Render();
}