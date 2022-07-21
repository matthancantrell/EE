#pragma once
#include "Framework/Actor.h"

class Bullet : public Engine::Actor
{
public:
	Bullet() = default;
	Bullet(const Engine::Model& model, const Engine::Transform& transform) :
		Actor{ model, transform } {}

	void Update() override;

private:
	float speed_ = 200;
	float lifespan_ = 5;
};