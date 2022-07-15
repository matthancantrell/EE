#include "Model.h"
#include "../Core/File.h"

#include <iostream>
#include <sstream>

namespace Engine
{
	void Model::Draw(Renderer& renderer, const Vector2& position, float angle, float scale)
	{

		for (int i = 0; i < points_.size() - 1; i++)
		{
			Engine::Vector2 p1 = Vector2::Rotate((points_[i]* scale), angle) + position;
			Engine::Vector2 p2 = Vector2::Rotate((points_[i + 1] * scale), angle) + position;
			renderer.DrawLine(p1, p2, color_);
		}
	}

	////////////////////////////////////////////////////////
	void Model::Load(const std::string& filename)
	{
		std::string buffer;

		Engine::ReadFile(filename, buffer);
		color_.r = 255;
		color_.g - 255;
		color_.b = 255;
		color_.a = 255;

		std::istringstream stream(buffer);
		std::string line;
		std::getline(stream, line);

		//get number of points
		size_t numPoints = std::stoi(line);

		//// read model points
		for (size_t i = 0; i < numPoints; i++)
		{
			Vector2 point;

			stream >> point;
			points_.push_back(point);
		}

	}
}