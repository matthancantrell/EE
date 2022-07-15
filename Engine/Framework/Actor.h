#pragma once
#include "GameObject.h"
#include "../Renderer/Model.h"

namespace Engine
{
	class Actor : public GameObject
	{
	public:
		Actor() = default;
		Actor(Model model, Transform transform) : GameObject{ transform }, model_{ model }  {}

		virtual void Update() override {}
		virtual void Draw(Renderer& renderer);

	private:

	protected:
		Model model_;

	};
}