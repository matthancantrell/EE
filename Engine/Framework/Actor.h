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
		Actor(const Model& model,const Transform& transform) : GameObject{ transform }, model_{ model }  {}

		virtual void Update() override {}
		virtual void Draw(Renderer& renderer);

		Scene* scene_ = nullptr;

	protected:
		Model model_;
	};
}