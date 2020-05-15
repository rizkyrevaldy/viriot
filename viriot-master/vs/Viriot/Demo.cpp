#include "Demo.h"

SceneGameplay Sgameplay;

Demo::Demo()
{
}


Demo::~Demo()
{
	
	if (Mix_Playing(sfx_channel) == 0) {
		Mix_FreeChunk(sound);
	}
	/*
	if (music != NULL) {
		Mix_FreeMusic(music);
	}
	*/
	Mix_CloseAudio();
	
}

void Demo::Init()
{
	InputMapping();
	InitAudio();
	Sgameplay = SceneGameplay(GetScreenWidth(),GetScreenHeight());
	
}

void Demo::Update(float deltaTime)
{
	if (IsKeyDown("Quit")) {
		Sgameplay.state = pause;
	}


	if (Sgameplay.state == gameOver || Sgameplay.state == pause){  
		ControlUI(deltaTime);
		
	}
	else {
		ControlPlayerSprite(deltaTime);
		Sgameplay.Update(deltaTime);
	}
	
	if (Mix_Playing(sfx_channel) == 0 && IsKeyDown("Shoot")) {
		sfx_channel = Mix_PlayChannel(-1, sound, 0);
		if (sfx_channel == -1) {
			Err("Unable to play WAV file: " + string(Mix_GetError()));
		}
	}
	/*
	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		Mix_PlayMusic(music, -1);
		SDL_Delay(150);
	}
	//If music is being played
	else
	{
		//If the music is paused
		if (Mix_PausedMusic() == 1)
		{
			//Resume the music
			Mix_ResumeMusic();
			SDL_Delay(150);
		}
		//If the music is playing
		else
		{
			//Pause the music
			Mix_PauseMusic();
			SDL_Delay(150);
		}
	}
	*/
	
}

void Demo::Render()
{
	//Setting Viewport
	glViewport(0, 0, GetScreenWidth(), GetScreenHeight());

	//Clear the color and depth buffer
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Set the background color
	glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

	//Draw	
		Sgameplay.Render();


}

void Demo::ControlPlayerSprite(float deltaTime)
{
	if (IsKeyDown("Move Right")) {
		float newX = Sgameplay.player.getPosx() + deltaTime * 0.5f;
		Sgameplay.player.setPosx(newX);
		Sgameplay.player.setFlip(false);
	}

	if (IsKeyDown("Move Left")) {
		float newX = Sgameplay.player.getPosx() - deltaTime * 0.5f;
		Sgameplay.player.setPosx(newX);
		Sgameplay.player.setFlip(true);
	}

	if (IsKeyDown("Move Up")) {
		float newY = Sgameplay.player.getPosy() - deltaTime * 0.5f;
		Sgameplay.player.setPosy(newY);
	}
	if (IsKeyDown("Move Down")) {
		float newY = Sgameplay.player.getPosy() + deltaTime * 0.5f;
		Sgameplay.player.setPosy(newY);
	}

	if (IsKeyDown("Shoot")) {
		Sgameplay.player.canShoot = false;
	}

}

void Demo::ControlUI(float deltaTime)
{

	switch (Sgameplay.state)
	{
	case pause:
		if (Sgameplay.state != gameOver) {
			if (IsKeyDown("Shoot")) {
				if (Sgameplay.uipause.activeButtonIndex == 0) {
					Sgameplay.state = play;
				}
			}

			if (IsKeyUp("Move Down")) {
				if (Sgameplay.uipause.activeButtonIndex < 2) {
					Sgameplay.uipause.activeButtonIndex = Sgameplay.uipause.activeButtonIndex + 1;
					SDL_Delay(150);
				}
			}

			if (IsKeyUp("Move Up")) {
				if (Sgameplay.uipause.activeButtonIndex > 0) {
					Sgameplay.uipause.activeButtonIndex = Sgameplay.uipause.activeButtonIndex - 1;
					SDL_Delay(150);
				}
			}
		}
		
		break;
	case gameOver:
		
		if (IsKeyDown("Shoot")) {
			if (Sgameplay.uigameover.activeButtonIndex == 1) {
				
				SDL_Quit();
				exit(0);
			}
		}

		if (IsKeyUp("Move Down")) {
			
			if (Sgameplay.uigameover.activeButtonIndex < 1) {
				
				Sgameplay.uigameover.activeButtonIndex = Sgameplay.uigameover.activeButtonIndex + 1;
				SDL_Delay(150);
			}
		}

		if (IsKeyUp("Move Up")) {
			if (Sgameplay.uigameover.activeButtonIndex > 0) {
				Sgameplay.uigameover.activeButtonIndex = Sgameplay.uigameover.activeButtonIndex - 1;
				SDL_Delay(150);
			}
		}
		break;
	default:
		break;
	}

	
}

bool Demo::IsCollided(gameObject obj1, gameObject obj2) {
	float x1 = obj1.xpos, y1 = obj1.ypos, width1 = obj1.frame_width, height1 = obj1.frame_height;
	float x2 = obj2.xpos, y2 = obj2.ypos, width2 = obj2.frame_width, height2 = obj2.frame_height;
	return (x1 < x2 + width2 && x1 + width1 > x2 && y1 < y2 + height2 && y1 + height1 > y2);
}

void Demo::InputMapping() {
	Engine::Game::InputMapping("Move Right", SDLK_RIGHT);
	Engine::Game::InputMapping("Move Left", SDLK_LEFT);
	Engine::Game::InputMapping("Move Up", SDLK_UP);
	Engine::Game::InputMapping("Move Down", SDLK_DOWN);
	Engine::Game::InputMapping("Move Right", SDLK_d);
	Engine::Game::InputMapping("Move Left", SDLK_a);
	Engine::Game::InputMapping("Move Up", SDLK_w);
	Engine::Game::InputMapping("Move Down", SDLK_s);
	Engine::Game::InputMapping("Move Right", SDL_BUTTON_RIGHT);
	Engine::Game::InputMapping("Move Left", SDL_BUTTON_LEFT);
	Engine::Game::InputMapping("Move Right", SDL_CONTROLLER_BUTTON_DPAD_RIGHT);
	Engine::Game::InputMapping("Move Left", SDL_CONTROLLER_BUTTON_DPAD_LEFT);
	Engine::Game::InputMapping("Move Up", SDL_CONTROLLER_BUTTON_DPAD_UP);
	Engine::Game::InputMapping("Move Down", SDL_CONTROLLER_BUTTON_DPAD_DOWN);
	Engine::Game::InputMapping("Quit", SDLK_ESCAPE);
	Engine::Game::InputMapping("Shoot", SDLK_SPACE);
	

}

void Demo::InitAudio() {
	int flags = MIX_INIT_MP3 | MIX_INIT_FLAC | MIX_INIT_OGG;
	if (flags != Mix_Init(flags)) {
		Err("Unable to initialize mixer: " + string(Mix_GetError()));
	}

	int audio_rate = 44100; Uint16 audio_format = AUDIO_S16SYS; int audio_channels = 1; int audio_buffers = 2048;

	if (Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers) != 0) {
		Err("Unable to initialize audio: " + string(Mix_GetError()));
	}

	/*
	music = Mix_LoadMUS("bensound-funkyelement.ogg");
	if (music == NULL) {
		Err("Unable to load Music file: " + string(Mix_GetError()));
	}
	*/
	sound = Mix_LoadWAV("Omega-Pulse2.wav");
	if (sound == NULL) {
		Err("Unable to load WAV file: " + string(Mix_GetError()));
	}


}

int main(int argc, char** argv) {

	Engine::Game &game = Demo();
	game.Start("Viriot", 800, 720, false, WindowFlag::WINDOWED , 60, 1);
	
	return 0;
}
