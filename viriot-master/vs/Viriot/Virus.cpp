#include "Virus.h"



Virus::Virus()
{
}


Virus::~Virus()
{
}

void Virus::Init() {

}

void Virus::Update(float deltaTime) {
	this->gameObject::Update(deltaTime);
	if (this->virusLife <= 0) {
		this->ypos = -35;
	}
	else {
		float newY = getPosy() + deltaTime * (virusSpeed / 200);
		setPosy(newY);
	}
}

void Virus::Render() {
	this->gameObject::Render();
}