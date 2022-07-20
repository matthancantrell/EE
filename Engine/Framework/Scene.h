#pragma once
#include "Actor.h"
#include <list>
#include <memory>

namespace Engine
{
	class Actor;
	class Renderer;

	class Scene
	{
	public:

		Scene() = default;
		~Scene() = default;

		void Update();
		void Draw(Renderer& renderer);
		void Add(std::unique_ptr<Actor> actor);

	private:

		std::list<std::unique_ptr<Actor>> actors_;

	};

}
