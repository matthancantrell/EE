#pragma once
#include "../Math/Transform.h";

namespace Engine
{
	class GameObject
	{
	public:

		GameObject() = default;
		GameObject(const Transform& transform) : transform_{ transform } {}

		virtual void Update() = 0;

		Transform& GetTransform() { return transform_;  }

	private:

	protected:

		Transform transform_;

	};
}