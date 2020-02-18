#pragma once
#include "CObject.h"
#include "SDL.h"
#include <vector>
#include "STextureManager.h"
typedef STextureManager TheTextureManager;
class CWorld
{
public:
	CWorld(SDL_Renderer*);
	std::vector <CObject*> objects;
	bool loadworld();
	void processInput();
	void update(float delta = 0);
	void render();
	//SDL_Window* m_pWindow;
	SDL_Renderer* p_renderer;
	/*SDL_Texture* m_pTexture; // the new SDL_Texture variable
	SDL_Rect m_sourceRectangle; // the first rectangle
	SDL_Rect m_destinationRectangle; // another rectangle*/

};