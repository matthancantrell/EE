#pragma once
#include "Framework/Actor.h"

class Enemy : public Engine::Actor
{
public:
	Enemy() = default;
	Enemy(const Engine::Model& model, const Engine::Transform& transform) : Actor{ model, transform } {}

	void Update() override;

private:

	float speed_ = 50;

};