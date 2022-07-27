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

		virtual void OnCollision(Actor* other) {}
		float GetRadius() { return model_.GetRadius() * transform_.scale; }
		std::string& GetTag() { return tag_; }
		
		friend class Scene;

	protected:
		std::string tag_;

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