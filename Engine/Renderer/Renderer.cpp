#include "Renderer.h"
#include <SDL.h>

namespace Engine
{
	void Renderer::Initialize()
	{
		SDL_Init(SDL_INIT_VIDEO);
	}
	void Renderer::ShutDown() // Shutdown is often in opposite order of initialization
	{
		SDL_DestroyRenderer(renderer_);
		SDL_DestroyWindow(window_);
	}
	void Renderer::CreateWindow(const char* title, int width, int height)
	{
		window_ = SDL_CreateWindow(title, 100, 100, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
		renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
	}
}