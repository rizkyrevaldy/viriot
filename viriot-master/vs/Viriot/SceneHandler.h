#pragma once
class SceneHandler

{
public:
	SceneHandler();
	SceneHandler(unsigned int screenWidth, unsigned int screenHeight);
	~SceneHandler();

	virtual void Init() = 0;
	virtual void Update(float deltaTime) = 0;
	virtual void Render() = 0;

	unsigned int screenHeight = 0, screenWidth = 0;
};
