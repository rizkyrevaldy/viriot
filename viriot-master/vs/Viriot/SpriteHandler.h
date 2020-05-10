#ifndef SPRITEHANDLER_H
#define SPRITEHANDLER_H

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

// mengatur kecepatan animasi
#define FRAME_DUR 60

using namespace std;
using namespace glm;

namespace Sprite {
	class SpriteHandler
	{
	public:
		SpriteHandler();
		~SpriteHandler();

		float frame_width = 0, frame_height = 0, frame_dur = 0, NUM_FRAMES = 0;
		float old_xpos = 0, xpos = 0, old_ypos = 0, ypos = 0;
		int screenWidth = 0, screenHeight = 0;

	protected:
		void RenderSprite();
		void UseShader(GLuint program);
		void BuildSprite(string Spritename, string SpriteVertFrag, float init_xpos, float init_ypos, int num_frame, float scale);
		GLuint BuildShader(const char* vertexPath, const char* fragmentPath, const char* geometryPath = nullptr);
		//virtual void UpdateSprite(float deltaTime);
		void DrawSprite();

		GLuint texture, program;
		
		unsigned int frame_idx = 0, flip = 0;

	private:
		GLuint VBO, VAO, EBO;
		void Err(string errorString);
		void CheckShaderErrors(GLuint shader, string type);
	};
}
#endif