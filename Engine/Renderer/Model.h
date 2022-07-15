#pragma once
#include "Renderer.h"
#include <vector>
#include <string>

namespace Engine
{
	class Model
	{

	public:

		Model() = default;
		Model(const std::vector<Engine::Vector2>& points, const Engine::Color& color) : points_{ points }, color_{ color }{}

		void Draw(Renderer& renderer, const Vector2& position, float angle, float scale);

		void Load(const std::string& filename);

	private:

		Engine::Color color_;
		std::vector<Engine::Vector2> points_;

	};
}