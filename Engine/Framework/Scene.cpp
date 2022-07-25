#include "Scene.h"
#include <algorithm>

namespace Engine
{
	void Scene::Update()
	{
		auto iter = actors_.begin();
		while (iter != actors_.end()) 
		{
			(*iter)->Update();
			if ((*iter)->destroy_)
			{
				iter = actors_.erase(iter);
			}
			else
			{
				iter++;
			}
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
		actor->scene_ = this;
		actors_.push_back(std::move(actor));
	}
}