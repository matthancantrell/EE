#pragma once
#include "Framework/Actor.h"

class Player : public Engine::Actor
{
public:
	Player() = default;
	Player(const Engine::Model& model, const Engine::Transform& transform) : Actor(model, transform) {}

	void Update() override;

private:
	float speed_{ 0 };
	float maxSpeed_{ 5 };
};
