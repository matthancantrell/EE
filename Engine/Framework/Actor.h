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
		
		friend class Scene;

	protected:

		// State
		bool destroy_ = false;

		// Physics
		Vector2 velocity_;
		float damping_ = 1;

		// Object
		Scene* scene_ = nullptr;
		Model model_;
	};
}