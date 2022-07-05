#pragma once

struct SDL_Renderer; // forward declaration
struct SDL_Window; // forward declaration

namespace Engine
{
	class Renderer
	{
	public:
		
		Renderer() = default; // Constructor - Calls an instance of this class
		~Renderer() = default; // Destructor - Destroys an instance of this class

		void Initialize();
		void ShutDown();

		void CreateWindow(const char* title, int width, int height);

	private:

		SDL_Renderer* renderer_ = nullptr; // (title)_ shows that this is a member variable
		SDL_Window* window_ = nullptr;
	};
}
