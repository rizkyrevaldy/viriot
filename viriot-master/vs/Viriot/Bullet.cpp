#include "Bullet.h"



Bullet::Bullet()
{
}

Bullet::~Bullet()
{
}

void Bullet::Init() {

}

void Bullet::Update(float deltaTime) {
	this->gameObject::Update(deltaTime);
	if (BulletActive) {
		float newY = getPosy() - deltaTime * (BulletSpeed / 50);
		setPosy(newY);
	}
	else {
		this->ypos = getScreenHeight() + 35;
	}
}

void Bullet::Render() {
	this->gameObject::Render();
}