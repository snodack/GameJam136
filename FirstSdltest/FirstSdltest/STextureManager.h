#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <map>
/*Singleton Texture Manager*/
class STextureManager
{
public:
	bool load(std::string fileName, std::string id,
		SDL_Renderer* pRenderer);
	void draw(std::string id, int x, int y, int width, int
		height, SDL_Renderer* pRenderer, SDL_RendererFlip flip =
		SDL_FLIP_NONE);
	/*void draw(std::string id, SDL_Rect pos, int width, int
		height, SDL_Renderer* pRenderer, SDL_RendererFlip flip =
		SDL_FLIP_NONE);*/
	void drawFrame(std::string id, int x, int y, int width, int
		height, int currentRow, int currentFrame, SDL_Renderer*
		pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	std::map<std::string, SDL_Texture*> m_textureMap;
	static STextureManager* Instance();
	static STextureManager* S_Instance;
	~STextureManager();
private:
	STextureManager() {}
	
};

