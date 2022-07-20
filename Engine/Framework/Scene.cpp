#include "Scene.h"

namespace Engine
{
	void Scene::Update()
	{
		for (auto& actor : actors_)
		{
			actor->Update();
		}
	}
	void Scene::Draw(Renderer& renderer)
	{
		for (auto& actor : actors_)
		{
			actor->Draw(renderer);
		}
	}
	void Scene::Add(std::unique_ptr<Actor> actor)
	{
		actors_.push_back(std::move(actor));
	}
}