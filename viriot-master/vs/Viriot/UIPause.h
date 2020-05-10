#ifndef UIPAUSE_H
#define UIPAUSE_H

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>
#include <GLM/gtc/type_ptr.hpp>
#include <glm/gtx/vector_angle.hpp>

#include <SOIL/SOIL.h>

#include <SDL/SDL_mixer.h>
#include <SDL/SDL_thread.h>

#include <ft2build.h>
#include <freetype/freetype.h>
#include <map>


#define FONTSIZE 40
#define FONTNAME "SourceSansPro-Regular.otf"
#define NUM_BUTTON_PAUSE 3
#define NUM_BUTTON_GAMEOVER 2

using namespace std;
using namespace glm;

#include <iomanip>
#include <locale>
#include <sstream>
#include <string>

struct Character {
	GLuint TextureID; // ID handle of the glyph texture
	ivec2 Size; // Size of glyph
	ivec2 Bearing; // Offset from baseline to left/top of glyph
	GLuint Advance; // Offset to advance to next glyph
};

class UIPause
{
public:
	UIPause();
	UIPause(int screenWidth, int screenHeight);
	~UIPause();

	virtual void Init();
	virtual void DeInit();
	virtual void Update(float deltaTime);
	virtual void Render();

	void RenderText(string text, GLfloat x, GLfloat y, GLfloat scale, vec3 color, bool centeredPivot);
	void RenderButton(float posX[], float posY[]);

	void Err(string errorString);
	int activeButtonIndex = 0;

protected:
	void InitText();

	void InitButton(string buttons[], string hover_buttons[]);


	map<GLchar, Character> Characters;
	GLuint texture[NUM_BUTTON_PAUSE], hover_texture[NUM_BUTTON_PAUSE], VBO, VBO2, VAO, VAO2, program;
	float button_width[NUM_BUTTON_PAUSE], button_height[NUM_BUTTON_PAUSE], hover_button_width[NUM_BUTTON_PAUSE], hover_button_height[NUM_BUTTON_PAUSE];


	void CheckShaderErrors(GLuint shader, string type);
	GLuint BuildShader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);
	void UseShader(GLuint program);

	int screenHeight = 10, screenWidth = 10;


};



#endif