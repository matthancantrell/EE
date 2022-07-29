#pragma once
#include "Framework/Actor.h"

class PowerUp : public Engine::Actor
{
public:
	PowerUp() = default;
	PowerUp(const Engine::Model& model, const Engine::Transform& transform) : Actor{ model, transform } {}

	void OnCollision(Actor* other) override;
};
