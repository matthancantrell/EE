#pragma once
#include "GameObject.h"
#include "../Renderer/Model.h"

namespace Engine
{
	class Scene;

	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(Model model, Transform transform) : GameObject{ transform }, model_{ model }  {}

		virtual void Update() override {}
		virtual void Draw(Renderer& renderer);

		Scene* scene_;

	protected:
		Model model_;
	};
}